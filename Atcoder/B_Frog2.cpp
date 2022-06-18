#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long




int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> h(n+1);

    for(int i=1; i<=n; i++)
    {
        cin >> h[i];
    }


    vector<int> dp(n+1, INT_MAX);

    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    for(int i=3; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i-j > 0)
                dp[i] = min(abs(h[i-j] - h[i]) + dp[i-j], dp[i]);
        }
    }

    cout << dp[n] << "\n";

}