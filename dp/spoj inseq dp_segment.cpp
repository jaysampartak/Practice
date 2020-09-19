#include<bits/stdc++.h>
using namespace std;
#define ll long long


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


#define all(x) x.begin(),x.end()
#define ip vector<int,pair<int,int>>
#define vii vector<pair<int,int>>
#define vi  vector<int>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define tt int t; cin>>t;while(t--)
#define FOR(i,j,k) for(int i=0;i<j;i++)
#define endl "\n"
#define pb push_back
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mxn=1e5+5;
const int mod=5e6;
int tree[51][4*mxn];
int sum(int v,int tl,int tr,int l,int r,int *t){
	if(l>r)return 0;
	if(tl==l&&r==tr)
		return (t[v]);
	int tm=(tl+tr)/2;
	return (sum(2*v,tl,tm,l,min(tm,r),t)+
			sum(2*v+1,tm+1,tr,max(l,tm+1),r,t))%mod;
}
void update(int v,int tl,int tr,int pos,int val,int *t){
	if(tl==tr)
		(t[v]+=val)%mod;
	else{
		int tm=(tl+tr)>>1;
		if(pos<=tm){
			update(2*v,tl,tm,pos,val,t);
		}else{
			update(2*v+1,tm+1,tr,pos,val,t);
		}
		(t[v]=t[2*v]+t[2*v+1])%=mod;
	}	
}



signed main(){
	
	int n,k,ele;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>ele;
		update(1,0,mxn,ele,1,tree[1]);
		for(int i=2;i<=k;i++){
			update(1,0,mxn,ele,sum(1,0,mxn,0,ele-1,tree[i-1]),tree[i]);
		}
	}
	cout<<(tree[k][1])%mod;

}
