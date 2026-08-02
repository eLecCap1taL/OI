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
#define MAXN 100005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)--)
#define uLL unsigned long long
#define LL long long
#define LXF LL
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


class SegmentTree{
public:
	class Node{
	public:
		int l,r;
		LL cov_tag;
		LL sum;
		LL lv;
	}tr[MAXN<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	void push_up(int p){
		tr[p].sum=tr[lc(p)].sum+tr[rc(p)].sum;
		tr[p].lv=tr[lc(p)].lv;
	}
	void upd(int p,LL k){
		tr[p].sum=(tr[p].r-tr[p].l+1)*k;
		tr[p].lv=k;
		
		tr[p].cov_tag=k;
	}
	void push_down(int p){
		if(tr[p].cov_tag==-1)	return ;
		upd(lc(p),tr[p].cov_tag);
		upd(rc(p),tr[p].cov_tag);
		tr[p].cov_tag=-1;
	}
	void build(int p,int l,int r){
		tr[p].l=l,tr[p].r=r;
		tr[p].cov_tag=-1;
		tr[p].sum=tr[p].lv=0;
		if(l==r){
			return ;
		}
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
	}
	void print(int p){
		if(tr[p].l==tr[p].r){
			printf("%lld\n",tr[p].sum);
			return ;
		}
		push_down(p);
		this->print(lc(p));
		this->print(rc(p));
	}
	
	
	void cover(int p,int l,int r,LL k){
		if(l<=tr[p].l && tr[p].r<=r){
			upd(p,k);
			return ;
		}
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	cover(lc(p),l,r,k);
		if(r>mid)	cover(rc(p),l,r,k);
		push_up(p);
	}
	LL query_sum(int p,int l,int r){
		if(l<=tr[p].l && tr[p].r<=r)	return tr[p].sum;
		LL ret=0;
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	ret+=query_sum(lc(p),l,r);
		if(r>mid)	ret+=query_sum(rc(p),l,r);
		return ret;
	}
	
	// ret 1 == continue to search left
	bool find(int p,int x,LL& y,LL& lst_v,int& pos){
		if(tr[p].r<=x){
			LL val=(tr[p].lv-lst_v)*(x-tr[p].l+1)+(lst_v)*(pos-tr[p].l)-tr[p].sum;
			
			if(y-val>=0){
				y-=val;
				lst_v=tr[p].lv;
				pos=tr[p].l;
				
				// continue to search....
				return 1;
			}
			
			if(tr[p].l==tr[p].r)	return 0;
			
			push_down(p);
			//its in there
			if(find(rc(p),x,y,lst_v,pos)==0)	return 0;
			else	return find(lc(p),x,y,lst_v,pos);
		}
		
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(x<=mid){
			// pure left
			return find(lc(p),x,y,lst_v,pos);
		}
		if(find(rc(p),x,y,lst_v,pos)==0)	return 0;
		else	return find(lc(p),x,y,lst_v,pos);
	}
}tr;

class Seq{
	// LL c[MAXN];
public:
	LL get_sum(int l,int r){
		// LL ret=0;
		// foru(i,l,r){
			// ret+=c[i];
		// }
		// return ret;
		return tr.query_sum(1,l,r);
	}
	void cover(int l,int r,LL v){
		// foru(i,l,r){
			// c[i]=v;
		// }
		tr.cover(1,l,r,v);
	}
	void print(int n){
		// foru(i,1,n){
			// printf("%lld\n",c[i]);
		// }
		tr.print(1);
	}
	int find_first_pos(int x,LL y){
		// int p=-1;
		// for(int i=1;i<=x;i++){
			// LL sum=get_sum(i,x);
			// LL v=get_sum(i,i);
// 			
			// LL res=v*(x-i+1)-sum;
			// if(y>=res){
				// p=i;
				// break;
			// }
		// }
		
		
		int p=x+1;
		LL lst_v=0;
		tr.find(1,x,y,lst_v,p);
		return p;
	}
}seq;

int n,m;
signed main(){
	freopen("umiri.in","r",stdin);
	freopen("umiri.out","w",stdout);
	
	n=RIN,m=RIN;
	
	tr.build(1,1,n);
	
	foru(o,1,m){
		int x=RIN;
		LL y=RIN;
		
		// find the right place
		int p=seq.find_first_pos(x,y);
		
		// so, we can cover [p,x] with c_p
		LL sum=seq.get_sum(p,x);
		LL v=seq.get_sum(p,p);
		int len=(x-p+1);
		
		y-=v*len-sum;
		
		// and now, we will have some extra points....
		// do some calc....
		LL w=y/len;
		LL r=y%len;
		
		if(p<=p+r-1){
			seq.cover(p,p+r-1,v+w+1);
		}
		seq.cover(p+r,x,v+w);
	}
	
	seq.print(n);
	
	return 0;
}