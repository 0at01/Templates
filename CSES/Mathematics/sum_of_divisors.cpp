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

ll modExpo(ll x, ll y)
{
    ll res = 1;

    while(y>0)
    {
        if(y&1) res = (res*x)%mod;
        x = (x*x)%mod;
        y = y>>1;
    }

    return res;
}



int main()
{
    fastio

    ll n; cin >> n;
    
    ll ans = 0;

    for(ll i=1,j; i<=n; i=j)
    {
        ll q = n/i;
        j = n/q + 1;

        ll sumUptoJminus1 = (((j%mod)*((j-1)%mod))%mod * modExpo(2, mod-2))%mod;
        ll sumUptoIminus1 = (((i%mod)*((i-1)%mod))%mod * modExpo(2, mod-2))%mod;

        ll rangeSum = (sumUptoJminus1-sumUptoIminus1+mod)%mod;

        ans = (ans + (q%mod)*rangeSum)%mod;
    }

    cout << ans << nln;

}