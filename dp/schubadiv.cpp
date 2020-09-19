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



const int  INF=1e9;


signed main(){
	tt{
		int T,A,N;
		cin>>T>>A;
		cin>>N;
		
		vector<array<int,3>>a(N+1);
		for(int i=1;i<=N;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		int dp[100][100];
		
		
	
		
		
		for(int k=0;k<=N;++k){
			for(int i=T;i>=0;i--){
				for(int j=A;j>=0;j--){
					if(k==0) {
						dp[i][j] = INF;
						if(i==0 && j==0) dp[i][j] = 0;
					} else {
						dp[i][j] = min(dp[i][j], a[k][2] + dp[max(0,i-a[k][0])][max(0,j-a[k][1])]);
					}
				}
			}
		}
	cout<<dp[T][A]<<endl;
		
		
	}


}
