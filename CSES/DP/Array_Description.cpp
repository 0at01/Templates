#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long



int main()
{
    fastio
    int m, n;
    cin >> n >> m;

    ll arr[n];

    for(int i=0; i<n; i++) cin >> arr[i];

    vector<vector<ll>> dp(m+1, vector<ll>(n, 0));

    for(int i=0; i<n; i++)
    {
        if(i == 0)
        {
            if(arr[i] != 0) dp[arr[i]][i] = 1;

            else
            {
                for(int j=1; j<=m; j++)
                    dp[j][i] = 1;
            }         

        }

        else 
        {
            if(arr[i] != 0)
            {
                dp[arr[i]][i] = ((arr[i]-1 > 0) ? dp[arr[i]-1][i-1]%mod : 0) + dp[arr[i]][i-1]%mod + ((arr[i]+1 <= m) ? dp[arr[i]+1][i-1]%mod : 0);
            }

            else 
            {
                for(int j=1; j<=m; j++)
                {
                    dp[j][i] += dp[j][i-1]%mod;
                    dp[j][i] = dp[j][i]%mod + dp[j-1][i-1]%mod;

                    if(j<m)
                        dp[j][i] = dp[j][i]%mod + dp[j+1][i-1]%mod;

                    dp[j][i] %= mod;

                }
            }
        }

    }


    if(arr[n-1] != 0)
        cout << dp[arr[n-1]][n-1]%mod << "\n";

    else 
    {
        ll ans = 0;

        for(int j=1; j<=m; j++)
            ans = (ans%mod + dp[j][n-1]%mod)%mod;

        cout << ans << "\n";    
    }     

   
}