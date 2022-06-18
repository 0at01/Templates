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



ll dp[22][(1<<22)];

ll matching(vector<vi> &compatible, int i, int mask, int n)
{
    if(i==n+1)
    {
        if(mask == 0) return 1;
        return 0;
    }

    if(dp[i][mask] != -1) return dp[i][mask];

    ll ans = 0;

    for(int k=0; k<=n; k++)
    {
        bool available = ((1<<k)&mask);

        if(available and compatible[i][k]==1)
            ans = ((ans%mod) + (matching(compatible, i+1, (mask^(1<<k)), n))%mod)%mod;
    }

    return dp[i][mask] = ans;

}


int main()
{
    fastio

    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;

    vector<vi> arr(22, vi(22, 0));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) 
            cin >> arr[i][j];

    int mask = (1<<n)-1;

    cout << matching(arr, 0, mask, n-1);

}