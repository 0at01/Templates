#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long
#define nln "\n"



int main()
{
    int n;
    cin >> n;

    vector<ll> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    vector<vector<ll>> dp(n, vector<ll>(n, 0));


    for(int len=1; len <=n; len++)
    {
        for(int i=0; i+len <= n; i++)
        {
            int j = i + len - 1;

            ll x, y, z;

            x = (i+2 <= j) ? dp[i+2][j] : 0;
            y = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
            z = (i <= j-2) ? dp[i][j-2] : 0;

            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); // The base case (1) is calculated here
        }
    }


    cout << dp[0][n-1] << nln;
}

