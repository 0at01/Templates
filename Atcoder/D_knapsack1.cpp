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
    fastio

    ll n, W;
    cin >> n >> W;

    ll weights[n], val[n];

    for(ll i=0; i<n; i++)
    {
        cin >> weights[i] >> val[i];
    }

    vll dp1(W+1, 0);
    vll dp2(W+1, 0);

    for(int i=0; i<=n; i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(j - weights[i] >= 0)
                dp2[j] = max({dp2[j], dp1[j], val[i] + dp1[j-weights[i]]});

            else 
                dp2[j] = dp1[j];    
        }

        dp2.swap(dp1);
        dp2.clear();           
      
    }

    cout << dp1[W] << nln;


}