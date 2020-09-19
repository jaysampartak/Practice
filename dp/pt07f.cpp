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



vector<vector<int>>ans(1e4+4);
vector<vector<int>>adj(1e4+4);
int cn=0;
int sz=0;
void dfs(int u, int par){
	int pc=cn;
	int child=adj[u].size();
	if(u!=1)child--;
	if(child==0)cn++;
	for(int v:adj[u]){
		if(v==par)continue;
		dfs(v,u);
	}
	ans[pc].pb(u);
	sz=max(pc,sz);
}
signed main(){
	tt{	cn=0;
		int n=78;
		//cin>>n;
		for(int i=0;i<n;i++){
			adj[i].clear();
			ans[i].clear();
		}
		int u,v;
		for(int i=0;i<n-1;i++){
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1,-1);
		cout<<sz+1<<endl;
		for(int i=sz;i>=0;i--){
			for(size_t j=0;j<ans[i].size();j++){
					if(j)cout<<" ";
					cout<<ans[i][j];
			}
			cout<<endl;
		}
	}

}
