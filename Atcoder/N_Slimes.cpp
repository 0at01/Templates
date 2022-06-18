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


ll dp[500][500];


ll presum(int i, int j, vll &pref)
{
    if(i==0) return pref[j];

    return(pref[j] - pref[i-1]);
}


ll slimes(vll &arr, int i, int j, vll &pref)
{
    if(i==j) return 0;

    if(dp[i][j] != -1) return dp[i][j];    

    ll mincost = LONG_LONG_MAX; // not INT_MAX

    for(int k=i; k+1<=j; k++)
    {
        ll left = slimes(arr, i, k, pref);
        ll right = slimes(arr, k+1, j, pref);

        mincost = min(mincost, left + right + presum(i, j, pref));

    }

    return dp[i][j] = mincost;
}




int main()
{
    fastio

    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    vll arr(n);
    vll pref(n);


    for(int i=0; i<n; i++) cin >> arr[i];
    
    pref[0] = arr[0];

    for(int i=1; i<n; i++) pref[i] += arr[i] + pref[i-1];
    

    ll ans = slimes(arr, 0, n-1, pref);

    cout << ans << nln;

}