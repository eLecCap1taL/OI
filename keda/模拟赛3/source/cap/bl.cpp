// Problem: CF1648E Air Reform
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1648E
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//%^~
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <limits>
#include <climits>
#include <bitset>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// #include "ext/pb_ds/priority_queue.hpp"
// #include <ext/rope>
// #define PBDS __gnu_pbds
// #include <bits/extc++.h>
#define MAXN 200005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)--)
#define uLL unsigned long long
#define LL long long
#define LXF int
#define RIN Cap1taLDebug::read()
#define RSIN Cap1taLDebug::rdstr()
#define RCIN Cap1taLDebug::rdchar()
#define HH printf("\n")
#define All(x) (x).begin(), (x).end()
#define fi first
#define se second
#define CA const auto&
#if defined(__clang__)
#define assume(expr) __builtin_assume(expr)
#elif defined(__GNUC__)
#define assume(expr) if (expr) {} else { __builtin_unreachable(); }
#elif defined(_MSC_VER)
#define assume(expr) __assume(expr)
#endif
#define likely(x) __builtin_expect(!!(x), 1) 
#define unlikely(x) __builtin_expect(!!(x), 0)
#define mkp(x,y) make_pair(x,y)
#define ast(x) if(!(x))	{cerr<<endl<<"err at"<<__LINE__<<endl;exit(1);}
#define sz(x) ((int)x.size())
using namespace std;

typedef __int128 i128;
typedef unsigned __int128 u128;
typedef long long i64;
typedef unsigned long long u64;
typedef int i32;
typedef unsigned u32;
typedef short i16;
typedef unsigned short u16;

class Cap1taLDebug{
public:
	#define DEBUGING

	ostream& buf;
	#ifndef DEBUGING
	static char fbuf[1<<21],*p1,*p2;
	#define getchar() (Cap1taLDebug::p1==p2&&(p1=(p2=fbuf)+fread(fbuf,1,1<<21,stdin),p1==p2)?EOF:*p2++)
	#endif
	Cap1taLDebug(ostream& out=cout):buf(out){}
	~Cap1taLDebug(){
		#ifdef DEBUGING
		buf.flush();
		#endif
	}
	static LXF read(){
		LXF x=0,w=1;char ch=0;
		while(!isdigit(ch)){
		if(ch=='-')	w=-1;
		ch=getchar();
		}
		while(isdigit(ch))	x=x*10+(ch^48),ch=getchar();
		return x*w;
	}
	static string rdstr(){
		string s;char c=getchar();
		while(c==' ' || c=='\r' || c=='\n')	c=getchar();	
		while(c!=' ' && c!='\r' && c!='\n' && c!=EOF)	s+=c,c=getchar();
		return s;
	}
	static char rdchar(){
		char c=getchar();
		while(c==' ' || c=='\r' || c=='\n')	c=getchar();
		return c;
	}
	static string i128ToString(i128 x){
		if(x==0)	return "0";
		string s="",w="";
		if(x<0)	w="-",x*=-1;
		while(x) s+=(char)('0'+(int)(x%10)),x/=10;
		reverse(All(s));
		return w+s;
	}
	static string u128ToString(u128 x){
		if(x==0)	return "0";
		string s="",w="";
		while(x) s+=(char)('0'+(int)(x%10)),x/=10;
		reverse(All(s));
		return w+s;
	}
	Cap1taLDebug& operator<<(const string val){
		#ifdef DEBUGING
		buf<<val;
		#endif
		return *this;
	}
	template<typename T1,typename T2>
	Cap1taLDebug& operator<<(const pair<T1,T2>& val){
		#ifdef DEBUGING
		(*this)<<"("<<val.first<<","<<val.second<<")";
		#endif
		return *this;
	}
	template<typename T,template<typename,typename...>class Container,typename...Args>
	Cap1taLDebug& operator<<(const Container<T, Args...>& container){
		#ifdef DEBUGING
		buf<<"{";
		bool fst=0;
		for(const auto& val:container){
			if(!fst)	fst=true;
			else	buf<<",";
			(*this)<<val;	
		}
		buf<<"}";
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(const i128& val){
		#ifdef DEBUGING
		buf<<i128ToString(val);
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(const u128& val){
		#ifdef DEBUGING
		buf<<u128ToString(val);
		#endif
		return *this;
	}
	template<typename T>
	Cap1taLDebug& operator<<(const T& val){
		#ifdef DEBUGING
		buf<<val;
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(ostream& (*manip)(ostream&)){
		#ifdef DEBUGING
		buf<<manip;
		#endif
		return *this;
	}
};
#ifndef DEBUGING
char Cap1taLDebug::fbuf[1<<21],*Cap1taLDebug::p1=nullptr,*Cap1taLDebug::p2=nullptr;
#endif
Cap1taLDebug cein(cout);
// Cap1taLDebug cein(cerr);
ostream& operator<<(ostream& os,i128 val){
	os<<Cap1taLDebug::i128ToString(val);
	return os;
}
ostream& operator<<(ostream& os,u128 val){
	os<<Cap1taLDebug::u128ToString(val);
	return os;
}

#define OPERATOR_FOR_PUSHBACK(pb)\
template<typename T>\
pb<T>& operator += (pb<T>& x,const T& y){x.push_back(y);return x;}

#define OPERATOR_FOR_PUSH(p)\
template<typename T>\
p<T>& operator += (p<T>& x,const T& y){x.push(y);return x;}

#define OPERATOR_FOR_INSERT(i)\
template<typename T>\
i<T>& operator += (i<T>& x,const T& y){x.insert(y);return x;}

OPERATOR_FOR_PUSHBACK(vector)
OPERATOR_FOR_PUSHBACK(deque)
OPERATOR_FOR_PUSH(stack)
OPERATOR_FOR_PUSH(queue)
OPERATOR_FOR_PUSH(priority_queue)
OPERATOR_FOR_INSERT(set)
OPERATOR_FOR_INSERT(unordered_set)
OPERATOR_FOR_INSERT(multiset)
OPERATOR_FOR_INSERT(unordered_multiset)

template<typename T1,typename T2>
inline bool chkmax(T1& x,const T2& y){return (T1)x<y?x=(T1)y,true:false;}
template<typename T1,typename T2>
inline bool chkmin(T1& x,const T2& y){return (T1)y<x?x=(T1)y,true:false;}

class TIMECHKER{
public:
	~TIMECHKER(){
		// cerr<<endl<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	}
}TIMECHECKER;

constexpr int mod=998244353;
// constexpr int mod=1e9+7;

constexpr int& mdd(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mdd(int& x,const T1& y,const T2& ...xr){
	x+=y;
	if(x>=mod)	x-=mod;
	return mdd(x,xr...);
}
constexpr int& mmv(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mmv(int& x,const T1& y,const T2& ...xr){
	x-=y;
	if(x<0)	x+=mod;
	return mmv(x,xr...);
}
constexpr int& mll(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mll(int& x,const T1& y,const T2& ...xr){
	x=(LL)x*y%mod;
	return mll(x,xr...);
}
constexpr int add(const int& x){return x;}
template<class ...T>
constexpr int add(const int& x,const T& ...xr){
	int ret=x+add(xr...);
	if(ret>=mod)	ret-=mod;
	return ret;
}
constexpr int mul(const int& x){return x;}
template<class ...T>
constexpr int mul(const int& x,const T& ...xr){
	return (LL)x*mul(xr...)%mod;
}
constexpr int mev(const int& x){return mod-x;}

constexpr int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)	mll(ret,x);
		mll(x,x),y>>=1;
	}
	return ret;
}

/*

*/

class DSU{
	int fa[MAXN];
	int sz[MAXN];
public:
	void set(int n){
		foru(i,1,n){
			fa[i]=i;
			sz[i]=0;
		}
	}
	int find(int x){
		while(fa[x]!=x){
			x=fa[fa[x]];
		}
		return x;
	}
	void Union(int x,int y){
		x=find(x),y=find(y);
		if(x==y)	return ;
		if(sz[x]>sz[y])	swap(x,y);
		fa[x]=y;
		sz[y]+=sz[x];
	}
};

class KruskalTree{
	int n;
	int N;
	
	vector<int> e[MAXN<<1];
	int fa[MAXN<<1];
	int w[MAXN<<1];
	
	int dfn;
	int top[MAXN<<1];
	int sz[MAXN<<1];
	int son[MAXN<<1];
	int dep[MAXN<<1];
public:
	void set(int _n){
		n=N=_n;
		dfn=0;
		foru(i,1,2*n){
			fa[i]=0;
			w[i]=0;
			e[i].clear();
			
			sz[i]=0;
			dep[i]=0;
			son[i]=0;
		}
	}
	int Union(int u,int v,int _w){
		w[++N]=_w;
		fa[u]=N;
		fa[v]=N;
		e[N]+=u;
		e[N]+=v;
		return N;
	}
	
	void dfs1(int u){
		dep[u]=dep[fa[u]]+1;
		sz[u]=1;
		for(auto v:e[u]){
			dfs1(v);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]])	son[u]=v;
		}
	}
	void dfs2(int u,int topf){
		top[u]=topf;
		if(!son[u])	return ;
		dfs2(son[u],topf);
		for(auto v:e[u]){
			if(v==son[u])	continue;
			dfs2(v,v);
		}
	}
	void build(){
		assert(N==2*n-1);
		dfs1(N);
		dfs2(N,N);
	}
	
	int query(int u,int v){
		// return w[LCA]
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])	swap(u,v);
			u=fa[top[u]];
		}
		if(dep[u]>dep[v])	swap(u,v);
		return w[u];
		
	}
};


class Kruskal{
	class Edge{
	public:
		int u,v,w;
	};
	vector<Edge> e;
	
	DSU dsu;
	int root[MAXN];
	
	int n;
public:
	void set(int _n){
		n=_n;
		e.clear();
	}
	void add_edge(int u,int v,int w){
		e+=Edge{u,v,w};
	}
	void build(KruskalTree& g){
		g.set(n);
		
		dsu.set(n);
		foru(i,1,n){
			root[i]=i;
		}
		
		sort(All(e),[&](auto& x,auto& y)->bool{
			return x.w<y.w;
		});
		
		int MST=0;
		for(auto [u,v,w]:e){
			if(dsu.find(u)==dsu.find(v))	continue;
			
			
			int x=root[dsu.find(u)];
			int y=root[dsu.find(v)];
			
			// kruskal
			dsu.Union(u,v);
			MST++;
			
			// rebuild
			root[dsu.find(u)]=g.Union(x,y,w);
			
			if(MST==n-1)	break;
		}
		
		g.build();
	}
	// auto& get_edges()const{return e;}
};

Kruskal k1,k2;
KruskalTree g1,g2;

class EdgeStore{
	unordered_set<int> st[MAXN];
public:
	void set(int n){
		foru(i,1,n){
			st[i].clear();
		}
	}
	void add_edge(int u,int v){
		if(u>v)	swap(u,v);
		st[u]+=v;
	}
	bool exist(int u,int v){
		if(u>v)	swap(u,v);
		return st[u].find(v)!=st[u].end();
	}
};

EdgeStore eg;

class Boruvka{
	int n;
	
	class SetDSU{
		// set<pair<int,int>> st;
	public:
		void clear(){
			// st.clear();
		}
	}dsu;
	
public:
	void set(int _n){
		n=_n;
		dsu.clear();
	}
	void process(){
		
	}
}br;

class EdgeIn{
public:
	int u,v,w;
}in[MAXN];

int n,m;

void solve(bool SPE){ 
	n=RIN,m=RIN;
	
	k1.set(n);
	eg.set(n);
	
	foru(i,1,m){
		int u=RIN,v=RIN,w=RIN;
		
		in[i]={u,v,w};
		
		eg.add_edge(u,v);
	}
	
	foru(i,1,m){
		k1.add_edge(in[i].u,in[i].v,in[i].w);
	}
	
	k1.build(g1);
	
	k2.set(n);
	
	// brute build g2
	foru(u,1,n){
		foru(v,u+1,n){
			if(eg.exist(u,v))	continue;
			// cout<<u<<' '<<v<<' '<<g1.query(u,v)<<endl;
			k2.add_edge(u,v,g1.query(u,v));
		}
	}
	k2.build(g2);
	
	
	// do boruvka
	br.set(n);
	br.process();
	
	
	// output
	foru(i,1,m){
		auto [u,v,w]=in[i];
		printf("%d ",g2.query(u,v));
	}
	printf("\n");
	
	return ;
}
/*
检查文件读写
检查多测清空
检查数组大小
*/
signed main()
{
	// #define RFILE
	#define MULTITEST
	// #define TESTCASEID
	
	#ifdef RFILE
	#ifndef CPEDITOR
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	#endif
	
	#ifdef MULTITEST
	int T=RIN;
	#else
	int T=1;
	#endif
	
	RIN;
	
	for(int i=1;i<=T;i++){
		solve(i==0);
	}
	return 0;
}