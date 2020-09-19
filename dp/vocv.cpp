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

int n;
const int mxn=1e5+8943;
const int mod=1e4+7;
vector<int>adj[mxn];
int dp[2][mxn];
int ways[2][mxn];

void dfs(int u,int par){
	//debug(u,par);
	dp[0][u]=0;
	dp[1][u]=1;
	ways[0][u]=ways[1][u]=1;
	for(int v:adj[u]){
		if(v==par)
			continue;
		dfs(v,u);
		(dp[1][u]+=min(dp[1][v],dp[0][v]));
		(dp[0][u]+=dp[1][v]);
		(ways[0][u] *=ways[1][v])%=mod;
		int w;
		if(dp[0][v]==dp[1][v])
			w=(ways[1][v]+ways[0][v])%mod;
		else{
			 w=(dp[0][v]<dp[1][v])?ways[0][v]:ways[1][v];
		}	
		(ways[1][u]*=w)%=mod;
	}
	
}


signed main(){
	tt{	
		int u,v;
		cin>>n;
		for(int i=0;i<=n;i++){
			ways[0][i]=ways[1][i]=1;
			dp[0][i]=0;
			dp[1][i]=1;
			adj[i].clear();
		}
		for(int i=0;i<n-1;i++){
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1,-1);
		if(dp[1][1]==dp[0][1])
			cout<<dp[1][1]<<" "<<(ways[0][1]+ways[1][1])%mod;
		else if(dp[1][1]<dp[0][1])
			cout<<dp[1][1]<<" "<<ways[1][1];
		else
			cout<<dp[0][1]<<" "<<ways[0][1];
		cout<<endl;	
	}


}
