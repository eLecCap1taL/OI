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
#include <list>
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// #include "ext/pb_ds/priority_queue.hpp"
// #include <ext/rope>
// #define PBDS __gnu_pbds
// #include <bits/extc++.h>
#define MAXN 300005
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



// make stone logic
class Stone{
public:
	LL sum;
	LL val;
	int N;
	
	Stone(LL _sum=0,LL _val=0,int _N=0):sum(_sum),val(_val),N(_N){}
	
	Stone& add_right(const Stone& x){
		val+=x.val+x.N*sum;
		
		sum+=x.sum;
		N+=x.N;
		return (*this);
	}
	Stone& add_left(const Stone& x){
		val+=x.val+N*x.sum;
		
		sum+=x.sum;
		N+=x.N;
		return (*this);
	}
	
	bool operator < (const Stone& x)const{
		if(sum*x.N==x.sum*N){
			if(sum==x.sum){
				if(val==x.val){
					return N<x.N;
				}
				return val<x.val;
			}
			return sum<x.sum;
		}
		return sum*x.N<x.sum*N;
	}
};
Stone operator + (const Stone& x,const Stone& y){
	return Stone(x.sum+y.sum,x.val+y.val+y.N*x.sum,x.N+y.N);
}

	
class SegmentTree{
public:
	class Node{
	public:
		int l,r;
		Stone s;
	}tr[(MAXN<<2)<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	void push_up(int p){
		tr[p].s=tr[lc(p)].s+tr[rc(p)].s;
	}
	void build(int p,int l,int r){
		tr[p].l=l,tr[p].r=r;
		if(l==r)	return ;
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
	}
	void upd(int p,int pos,const Stone& res){
		if(tr[p].l==tr[p].r){
			tr[p].s=res;
			return ;
		}
		int mid=(tr[p].l+tr[p].r)>>1;
		if(pos<=mid)	upd(lc(p),pos,res);
		else	upd(rc(p),pos,res);
		push_up(p);
	}
	
	LL root_ans(){
		return tr[1].s.val;
	}
}tr;

// register stone operation list
class StoneRecoder{
protected:
	vector<int> ent[MAXN<<2];
	
	// re-index
	int cnt=0;
	map<Stone,int> mp;
	
	// map_int to rank
	int idx[MAXN<<2];
	
	class StoneLoader{
	public:
		Stone base;
		int cnt;
		
		void load(){
			cnt++;
		}
		void unload(){
			cnt--;
		}
		Stone get(){
			if(cnt==0)	return Stone(0,0,0);
			return Stone(
	            base.sum*cnt,
	            base.val*cnt+base.sum*base.N*cnt*(cnt-1)/2,
	            base.N * cnt
	        );
		}
	}ls[MAXN<<2];
	
public:
	void load(int tm,const Stone& res){
		if(mp[res]==0)	mp[res]=++cnt;
		
		int id=mp[res];
		
		ent[tm]+=id;
	}
	void unload(int tm,const Stone& res){
		int id=mp[res];
		
		ent[tm]+=-id;
	}
	
	void process(int q){
		cnt=0;
		for(const auto& [res,id]:mp){
			idx[id]=++cnt;
			ls[cnt].base=res;
		}
		
		// now [cnt] is the num of Stones
		tr.build(1,1,cnt);
		
		foru(i,0,q){
			// now, answer the querys
			
			for(auto opt:ent[i]){
				if(opt<0){
					opt=idx[-opt];
					// del
					ls[opt].unload();
				}else{
					opt=idx[opt];
					// add
					ls[opt].load();
				}
				tr.upd(1,opt,ls[opt].get());
			}
			
			printf("%lld\n",tr.root_ans());
		}
	}
}rec;

// seq
class Seq{
protected:
	list<Stone> a[MAXN];
public:
	void push_back(int id,int x,int tm){
		a[id].emplace_back(x,x,1);
		
		//shrink
		while(sz(a[id])>1 && a[id].back()<*prev(a[id].end(),2)){
			auto res=a[id].back();
			a[id].pop_back();
			
			rec.unload(tm,a[id].back());
			a[id].back().add_right(res);
		}
		
		rec.load(tm,a[id].back());
	}
	void push_front(int id,int x,int tm){
		a[id].emplace_front(x,x,1);
		
		//shrink
		while(sz(a[id])>1 && *next(a[id].begin(),1)<a[id].front()){
			auto res=a[id].front();
			a[id].pop_front();
			
			rec.unload(tm,a[id].front());
			a[id].front().add_left(res);
		}
		
		rec.load(tm,a[id].front());
	}
}seq;


// var
int k,q;
int s[MAXN];

signed main(){
	// freopen("taki.in","r",stdin);
	// freopen("taki.out","w",stdout);
	 
	k=RIN,q=RIN;
	
	foru(i,1,k){
		s[i]=RIN;

		foru(j,1,s[i]){
			int x=RIN;
			seq.push_back(i,x,0);
		}
	}
	
	foru(i,1,q){
		// process operations
		int op=RIN,t=RIN,v=RIN;
		
		if(op==0){
			seq.push_front(t,v,i);
		}else{
			seq.push_back(t,v,i);
		}
	}
	
	rec.process(q);
	
	return 0;
}