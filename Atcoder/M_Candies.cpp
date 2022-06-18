#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout << " Debug \n";
#define mod 1000000007
#define ll long long
#define nln "\n"
#define vi vector<int>
#define vll vector<ll>
#define begend(x) x.begin(), x.end()
#define printMat(arr, n, m) for(int i=0; i<n; i++) { for(int j=0; j<m; j++){ cout << arr[i][j] << " ";} cout << nln;}
#define printArr(arr, beg, end) for(int i=beg; i<=end; i++){ cout << arr[i] << " ";}cout << nln;



ll candies(vi &arr, int n, int k)
{
    vector<vll> dp(n+1, vll(k+1, 0));

    for(int j=0; j<=k; j++)
    {
        dp[1][j] = (j <= arr[1] ? 1 : 0);
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            if(j==0) dp[i][j] = dp[i-1][j]; 

            else
            dp[i][j] = (mod + (dp[i][j-1]%mod + dp[i-1][j]%mod - ((j-arr[i]-1>=0) ? dp[i-1][j-1-arr[i]]%mod : 0)))%mod;
        }
    }

    return dp[n][k];

}


int main()
{
    fastio

    int n, k;
    cin >> n >> k;

    vi arr(n+1);

    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    cout << candies(arr, n, k) << nln;


}