#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout << " Debug \n";
#define mod 1000000007
#define ll long long
#define nln "\n"
#define vi vector<int>
#define vll vector<ll>
#define begend(x) x.begin(), x.end()
#define printMat(arr, n, m) for(int i=0; i<n; i++) { for(int j=0; j<m; j++){ cout << arr[i][j] << " ";} cout << nln;}
#define printArr(arr, beg, end) for(int i=beg; i<=end; i++){ cout << arr[i] << " ";}cout << nln;


ll dp[100005][2];

ll solve(int node, int parent, vector<int> adj[], int c) 
{
    if(dp[node][c] != -1) return dp[node][c];

    ll ans = 0;
    ll whiteWays = 1;

    for(auto child: adj[node])
    {
        if(child != parent)
        {
            whiteWays = ((whiteWays%mod) * (solve(child, node, adj, 0)%mod))%mod;
        }
    }

    ans = (ans%mod + whiteWays%mod)%mod;


    if(!c)
    {
        int blackWays = 1;

        for(auto child: adj[node])
        {
            if(child != parent)
            {
                blackWays = ((blackWays)%mod * (solve(child, node, adj, 1))%mod)%mod;
            }
        }

        ans = (ans%mod + blackWays%mod)%mod;
    }
       
    return dp[node][c] = ans;

}


int main()
{
    int n; cin >> n;

    vector<int> adj[n+1];

    memset(dp, -1, sizeof(dp));

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v; 
        
        adj[u].push_back(v);
        adj[v].push_back(u);        
    }

    cout << solve(1, -1, adj, 0) << nln;            


}