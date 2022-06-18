#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long



int find_greatest_digit(int n)
{
    string snum = to_string(n);

    int maxdig = -1;

    int slen = snum.length();

    for(int i=0; i<slen; i++)
    {
        int dig = snum[i] - '0';

        maxdig = max(maxdig, dig);
    }

    return maxdig;
}




int main()
{
    ll n;
    cin >> n;

    if(n == 0) cout << 0 << endl;

    else if(n>0 and n<10)
        cout << 1 << "\n";

    else
    {
        vector<ll> dp(n+1, 0);

        for(int i=1; i<=9; i++) dp[i] = 1;        

        for(int i=10; i<=n; i++)
        {
            dp[i] = 1 + dp[ i - find_greatest_digit(i)];
        }        

        cout << dp[n] << "\n";
    }    
    
}