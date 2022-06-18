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




int main()
{
    fastio
 
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
 
    ll ans = 0;
 
    map<int, int> mp;
 
    mp[0] = 1;
 
    for(int i=0; i<n; i++)
    {
        if(i-1>=0) arr[i] += arr[i-1];
 
        int req = (arr[i]%n + n)%n;        
 
        ans += mp[req];
 
        mp[arr[i]]++;
    }
 
    cout << ans << nln; 
 
}