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
    int h, w;
    cin >> h >> w;

    vector<vll> dp(h, vll(w, 0));

    char arr[h][w];   

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cin >> arr[i][j];

            if(arr[i][j] == '#')
            {
                dp[i][j] = -1;
            }
                
        }
    }


    dp[0][0] = 1;


    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(dp[i][j] != -1)
            {
                if(i+1<h and dp[i+1][j] != -1) dp[i+1][j] += dp[i][j]%mod;
                if(j+1<w and dp[i][j+1] != -1) dp[i][j+1] += dp[i][j]%mod;
            }
            
        }
    }    

    cout << dp[h-1][w-1]%mod << nln;

}