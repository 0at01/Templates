#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long




int main()
{

    int n, x;
    cin >> n >> x;

    int price[n], pages[n];

    for(int i=0; i<n; i++) cin >> price[i];
    for(int i=0; i<n; i++) cin >> pages[i];


    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=x; j++)
        {
            if(price[i-1] > j)
                dp[i][j] = dp[i-1][j];

            else 
            {
                dp[i][j] = max(dp[i-1][j], pages[i-1] + dp[i-1][j - price[i-1]]);
            }    
        }
    }

    cout << dp[n][x] << "\n";

}