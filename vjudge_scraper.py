"""
VJudge 比赛题目爬虫
使用 Playwright 浏览器自动化获取比赛内的题目列表
"""

import json
import re
import sys
from pathlib import Path
from playwright.sync_api import sync_playwright, TimeoutError as PwTimeout

# 需要抓取的比赛列表（NOIP训练题单）
NOIP_CONTESTS = [
    (720599, "NOIP第1组【序列类问题】"),
    (720601, "NOIP第2组【序列区间/二维序列类问题】"),
    (720603, "NOIP第3组【区间数据结构类问题】"),
    (720606, "NOIP第4组【状态表示/枚举搜索类问题】"),
    (720607, "NOIP第5组【动态规划/组合递推类问题】"),
]

# 省选题单
PROVINCE_CONTESTS = [
    (726185, "省选第12组【生成函数和多项式相关问题】"),
    (726183, "省选第13组【组合性质和递推类问题】"),
    (726143, "省选第14组【杂题】"),
]

COOKIES = [
    {"name": "JSESSlONID", "value": "ZA4JXQGZSSK9HX20LS86QUFPKQEPY61C", "domain": ".vjudge.net", "path": "/"},
    {"name": "JSESSIONlD", "value": "859679|IAIATLZDKCTP3AE1F84LQEMP56LC50", "domain": ".vjudge.net", "path": "/"},
    {"name": "_ga", "value": "GA1.1.1934578420.1783762078", "domain": ".vjudge.net", "path": "/"},
    {"name": "_ga_374JLX1715", "value": "GS2.1.s1783762077$o1$g1$t1783764846$j49$l0$h0", "domain": ".vjudge.net", "path": "/"},
]

OUTPUT_DIR = Path("D:/Projects/OI/keda/26.7/vjudge_data")
OUTPUT_DIR.mkdir(exist_ok=True)


def extract_problems(page) -> list:
    """从已加载的页面提取题目信息"""
    problems = []

    # 方法1: 从 localStorage 中读取
    try:
        ls_data = page.evaluate("""() => {
            const keys = Object.keys(localStorage);
            const result = {};
            for (const key of keys) {
                if (key.includes('problem') || key.includes('contest') || key.includes('720599')) {
                    try {
                        result[key] = JSON.parse(localStorage.getItem(key));
                    } catch {
                        result[key] = localStorage.getItem(key);
                    }
                }
            }
            return result;
        }""")
        if ls_data:
            print(f"    localStorage keys found: {list(ls_data.keys())}")
    except Exception as e:
        print(f"    localStorage read failed: {e}")

    # 方法2: 从页面DOM中提取题目行
    try:
        problem_rows = page.query_selector_all('table tr[class*="problem"], .problem-item, tr.problem')
        print(f"    DOM problem rows found: {len(problem_rows)}")
    except Exception as e:
        print(f"    DOM query failed: {e}")

    # 方法3: 从window全局变量获取
    try:
        window_data = page.evaluate("""() => {
            const result = {};
            if (window.contestProblems) result.contestProblems = window.contestProblems;
            if (window.problems) result.problems = window.problems;
            if (window.problemList) result.problemList = window.problemList;
            if (window.__INITIAL_STATE__) result.initialState = window.__INITIAL_STATE__;
            return result;
        }""")
        if window_data:
            for k, v in window_data.items():
                print(f"    window.{k}: {json.dumps(v, ensure_ascii=False)[:200]}")
    except Exception as e:
        print(f"    window var read failed: {e}")

    # 方法4: 抓取页面html中的题目表格数据
    html = page.content()

    # 尝试解析题目列表
    patterns = [
        (r'<td[^>]*class="[^"]*oj[^"]*"[^>]*>([^<]+)</td>', 'oj'),
        (r'<td[^>]*class="[^"]*prob[^"]*"[^>]*>([^<]+)</td>', 'probNum'),
        (r'<td[^>]*class="[^"]*title[^"]*"[^>]*>([^<]+)</td>', 'title'),
        (r'<a[^>]*href="/problem/([^"]+)"[^>]*>([^<]+)</a>', 'problem_link'),
    ]

    for pattern, name in patterns:
        matches = re.findall(pattern, html)
        if matches:
            print(f"    {name} matches ({len(matches)}): {matches[:5]}")

    return problems


def fetch_contest(contest_id: int, title: str, browser):
    """抓取单个比赛"""
    url = f"https://vjudge.net/contest/{contest_id}"
    print(f"\n{'='*60}")
    print(f"抓取: [{contest_id}] {title}")
    print(f"{'='*60}")

    context = browser.new_context(
        viewport={"width": 1920, "height": 1080},
        user_agent="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"
    )

    # 设置 cookies
    context.add_cookies(COOKIES)

    page = context.new_page()

    # 监听网络请求，捕获 XHR 数据
    api_responses = []
    def on_response(response):
        if 'contest' in response.url and 'data' in response.url:
            try:
                body = response.text()
                api_responses.append({
                    'url': response.url,
                    'status': response.status,
                    'body_preview': body[:500]
                })
            except:
                pass

    page.on("response", on_response)

    try:
        page.goto(url, wait_until="networkidle", timeout=30000)
        print(f"    Page loaded: {page.title()}")

        # 等待一段时间确保JS执行
        page.wait_for_timeout(3000)

        # 提取题目数据
        problems = extract_problems(page)

        # 记录API响应
        for resp in api_responses:
            print(f"    API: {resp['url'][:80]}")
            print(f"         status={resp['status']}, data={resp['body_preview'][:200]}")

        # 保存页面HTML到文件
        html = page.content()
        out_file = OUTPUT_DIR / f"contest_{contest_id}.html"
        with open(out_file, 'w', encoding='utf-8') as f:
            f.write(html)
        print(f"    HTML saved: {out_file}")

    except PwTimeout:
        print(f"    Timeout loading page")
    except Exception as e:
        print(f"    Error: {e}")
    finally:
        context.close()

    return api_responses


def main():
    print("VJudge 比赛题目爬虫")
    print(f"浏览器: Chromium (headless)")

    with sync_playwright() as p:
        browser = p.chromium.launch(headless=True, args=['--no-sandbox'])

        # 抓取NOIP题单
        for cid, name in NOIP_CONTESTS:
            fetch_contest(cid, name, browser)

        # 抓取省选题单
        for cid, name in PROVINCE_CONTESTS:
            fetch_contest(cid, name, browser)

        browser.close()

    print(f"\n抓取完成！数据保存在 {OUTPUT_DIR}")


if __name__ == "__main__":
    main()
