#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long
#define nln "\n"
#define vi vector<double>
#define vll vector<ll>
#define begend(x) x.begin(), x.end()



int main()
{
    fastio
    int n; cin >> n;
    vi p(n);
    for(int i=0; i<n; i++) cin >> p[i];    

    int leastHeads = n/2 + 1;

    vector<vi> dp(n+1, vi(leastHeads+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++)    
        for(int j=1; j<=leastHeads; j++)        
            dp[i][j] = p[i-1]*dp[i-1][j-1] + (1 - p[i-1])*dp[i-1][j];   

    cout << fixed << setprecision(10) << dp[n][leastHeads] << nln;

}