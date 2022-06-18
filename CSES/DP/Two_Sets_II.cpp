#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long
#define nln "\n"
#define vi vector<int>
#define vll vector<ll>
#define begend(x) x.begin(), x.end()




int main()
{
    fastio

    int n;
    cin >> n;

    int sum = (n * (n+1))/2;

    if(sum % 2 != 0)
        cout << 0 << nln;

    else
    {
        sum /= 2;

        vector<vll> dp(n+1, vll(sum+1, 0));

        dp[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(j-i >= 0)
                    dp[i][j] = (dp[i-1][j] %mod +  dp[i-1][j-i] %mod)%mod;
                else 
                    dp[i][j] = dp[i-1][j]%mod;    
            }
        }

        cout << dp[n][sum] << nln;

    }

}