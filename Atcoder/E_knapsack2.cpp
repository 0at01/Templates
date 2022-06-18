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

    int n, w;
    cin >> n >> w;

    int wt[n], val[n];

    for(int i=0; i<n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    vll dp1(n*1000+1, INT_MAX); 
    vll dp2(n*1000+1, INT_MAX);

    dp1[0] = 0;
    //dp1[val[0]] = wt[0];


    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n*1000; j++)
        {
            if(val[i-1] > j)
                dp2[j] = dp1[j];               

            else 
                dp2[j] = min({dp1[j], wt[i-1] + dp1[j - val[i-1]]});                    

        }


        for(int k=1; k<=n*1000; k++)
        {
            dp1[k] = dp2[k];
            dp2[k] = INT_MAX;
        }


    }


    int ans = 0;

    for(int i=0; i<=n*1000; i++)
    {
        if(dp1[i] <= w) ans = i;
    }

    cout << ans << nln;


}