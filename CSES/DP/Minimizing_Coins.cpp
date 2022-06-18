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

    int coins[n];
    for(int i=0; i<n; i++) cin >> coins[i];
    
    vector<ll> dp(sum+1, -1);
 
    dp[0] = 0;

    for(int j=0; j<n; j++)
    {
        for(int i=coins[j]; i<=sum; i++)
        {
            if(dp[i - coins[j]] != -1)
            {
                ll newval = (1 + dp[i-coins[j]]) %mod;

                if(dp[i] == -1)
                    dp[i] = newval;

                else dp[i] = min(dp[i], newval);
            }
                
        }
    }    
 
    cout << dp[sum] << "\n";
 
    return 0;   
 
}