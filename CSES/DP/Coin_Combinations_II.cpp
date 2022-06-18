#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long
 
 
 
 
int main()
{
    fastio;
 
    int n, sum;
    cin >> n >> sum;

    ll coins[n];
    for(int i=0; i<n; i++) cin >> coins[i];
    
    vector<ll> dp(sum+1, 0);
 
    dp[0] = 1;

    for(int j=0; j<n; j++)
    {
        for(int i= coins[j]; i<=sum; i++)
        {
            if(dp[i - coins[j]]) 
                dp[i] = dp[i] %mod + dp[i - coins[j]] %mod;
        }
    }


    cout << dp[sum] % mod << "\n";

}    