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

    int n, x; cin >> n >> x ;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    
    map<ll, ll> mp;
    mp[0] = 1;    

    ll ans = 0;

    
    // Storing the number of prefix sums that occured upto the current element
    // in the map while simultaneoulsy cauculating ans because if the complete map is made
    // before, then it will give a wong answer as the prefixs that occur in the future 
    // will also be added.

    for(int i=0; i<n; i++)
    {
        if(i-1>=0) arr[i] += arr[i-1];

        if(mp.find(arr[i]-x) != mp.end())
            ans+=mp[arr[i]-x];

        mp[arr[i]]++;
    }

    cout << ans << nln;

}