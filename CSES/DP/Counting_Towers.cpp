#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long


vector<vector<ll>> dp(2, vector<ll> (1000000+1, 0));

// 0 => Connectd
// 1 => Not Connected                                                              

void solve()
{
    dp[0][1] = 1; dp[1][1] = 1;

    for(int i=1; i<=1000000; i++)
    {
        dp[0][i] += (4*dp[0][i-1]%mod + dp[1][i-1]%mod)%mod;
        dp[1][i] += (dp[0][i-1]%mod + 2*dp[1][i-1]%mod)%mod;
    }
}


int main()
{
    fastio
    solve();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << ((dp[1][n]%mod + dp[0][n]%mod)%mod) << "\n";
    }
}

