# rename_testdata_final.py
import argparse
import os
import re

def batch_rename(
    root_dir: str,
    old_name: str,
    new_name: str | None,
    target_style: str,
    out2ans: bool = False,
    ans2out: bool = False
):
    # 匹配规则：前缀 + 旧题目名 + (可选下划线) + 数字 + .in/.ans/.out
    pattern = re.compile(
        rf"(.*?)({re.escape(old_name)})(?:_?)(\d+)\.(in|ans|out)$",
        re.IGNORECASE
    )

    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            match = pattern.fullmatch(filename)
            if not match:
                continue

            prefix, tag_old, num, ext = match.groups()
            ext_lower = ext.lower()

            # 替换题目主名，不指定则沿用原名
            tag_new = new_name if new_name is not None else tag_old

            # 按指定风格拼接：带下划线 / 无下划线
            if target_style == "underline":
                stem = f"{prefix}{tag_new}_{num}"
            else:
                stem = f"{prefix}{tag_new}{num}"

            # 后缀双向转换逻辑
            final_ext = ext_lower
            if out2ans and final_ext == "out":
                final_ext = "ans"
            elif ans2out and final_ext == "ans":
                final_ext = "out"

            new_filename = f"{stem}.{final_ext}"
            old_full_path = os.path.join(dirpath, filename)
            new_full_path = os.path.join(dirpath, new_filename)

            if old_full_path == new_full_path:
                print(f"[跳过] {old_full_path} 无需变更")
                continue

            try:
                os.rename(old_full_path, new_full_path)
                print(f"[成功] {old_full_path}  -->  {new_full_path}")
            except Exception as e:
                print(f"[失败] {old_full_path} 错误：{str(e)}")

def main():
    parser = argparse.ArgumentParser(
        description="竞赛测试数据批量重命名：更换题目名、格式切换、out↔ans互转、递归扫描、预览模式"
    )
    # 必选：原始题目名
    parser.add_argument("old_name", help="当前匹配的旧题目标识，例如 abc")
    # 可选：新题目名称
    parser.add_argument("--new-name", type=str, default=None, help="替换为新的题目名，例如 ddd，不填则保持原名不变")
    # 数字格式样式
    parser.add_argument(
        "--style",
        choices=["underline", "noline"],
        default="underline",
        help="数字格式：underline=abc_1；noline=abc1；默认 underline"
    )
    # 互斥后缀转换
    suffix_group = parser.add_mutually_exclusive_group()
    suffix_group.add_argument("--out2ans", action="store_true", help="匹配的.out 文件后缀改为 .ans")
    suffix_group.add_argument("--ans2out", action="store_true", help="匹配的.ans 文件后缀改为 .out")
    # 扫描目录
    parser.add_argument("--root", default=".", help="递归扫描根目录，默认当前工作目录")
    # 预览模式
    parser.add_argument("--dry-run", action="store_true", help="仅打印将要执行的修改，不实际重命名文件")

    args = parser.parse_args()

    # 预览模式劫持 os.rename，只打印不执行
    if args.dry_run:
        origin_rename = os.rename
        def fake_rename(src, dst):
            print(f"[预览] {src}  -->  {dst}")
        os.rename = fake_rename

    batch_rename(
        root_dir=args.root,
        old_name=args.old_name,
        new_name=args.new_name,
        target_style=args.style,
        out2ans=args.out2ans,
        ans2out=args.ans2out
    )

    # 恢复原生rename
    if args.dry_run:
        os.rename = origin_rename

if __name__ == "__main__":
    main()