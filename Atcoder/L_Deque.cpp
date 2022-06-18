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


ll dp2[3002][3002];
ll solveMemo(vll &arr, int i, int j)
{
    if(dp2[i][j] != -1) return dp2[i][j];

    if(i == j) return dp2[i][j] = arr[i];

    return dp2[i][j] = max(arr[i] - solveMemo(arr, i+1, j), arr[j] - solveMemo(arr, i, j-1));
}


ll solTopDown(vll &arr, int n)
{
    vector<vll> dp(n, vll(n, 0));

    for(int i=0; i<n; i++) dp[i][i] = arr[i];

    for(int len = 0; len < n; len++){
        for(int i=0; i+len<n; i++){
            int j= i + len;
            if(i+1 < n)
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);    
        }
    }

    return dp[0][n-1];
}


int main()
{
    fastio

    int n;
    cin >> n;
    
    vll arr(n);

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }


    memset(dp2, -1, sizeof(dp2));

    cout << solTopDown(arr, n);


}