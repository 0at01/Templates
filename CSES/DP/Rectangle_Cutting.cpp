#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long




int main()
{

    fastio;

    int a, b;
    cin >> a >> b;

    vector<vector<ll>> dp(a+1, vector<ll>(b+1, INT_MAX));

    for(int i=0;i<=a; i++)
    {
        for(int j=0; j<=b; j++)
        {
            if(i==j) dp[i][j] = 0;

            else 
            {
                //Horizontal cuts
                for(int k=1; k<=i-1; k++)
                {
                    dp[i][j] = min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
                }

                //Vertical cuts
                for(int k=1; k<=j-1; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                }
            }

        }
    }

    cout << dp[a][b] << "\n";    

}