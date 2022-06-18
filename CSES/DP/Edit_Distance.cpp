#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long


ll dp[6001][6001];


ll editDist(string s1, string s2, int n, int m)
{
    if(dp[n][m] != -1) return dp[n][m];

    if(n==0 and m==0) return dp[n][m] = 0;
    if(n == 0) return dp[n][m] = m;
    if(m == 0) return dp[n][m] = n;

    if(s1[n-1] == s2[m-1])
        return dp[n][m] = editDist(s1, s2, n-1, m-1);

    ll ans = 1 + min(editDist(s1, s2, n-1, m-1), min(editDist(s1, s2, n-1, m), editDist(s1, s2, n, m-1)));

    return dp[n][m] = ans;            
}


int main()
{
    fastio

    memset(dp, -1, sizeof(dp));

    string r, s;
    cin >> r >> s;

    cout << editDist(r, s, r.length(), s.length()) << "\n";

    for(int i=0; i<=r.length(); i++)
    {
        for(int j=0; j<=s.length(); j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }


}


// Tabulation:

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// #define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define mod 1000000007
// #define ll long long
 
 
 
 
// int main()
// {
//     fastio
 
//     string r, s;
//     cin >> r >> s;
 
//     int m = r.length(), n = s.length();
 
//     vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
 
//     dp[0][0] = 0;
 
//     for(int i=1; i<=m; i++)
//     {
//         dp[i][0] = i;
//     }
 
//     for(int i=1; i<=n; i++)
//     {
//         dp[0][i] = i;
//     }   
 
 
 
//     for(int i=1; i<=m; i++)
//     {
//         for(int j=1; j<=n; j++)
//         {
//             if(r[i-1] == s[j-1]) 
//                 dp[i][j] = dp[i-1][j-1];
 
//             else
//                 dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
//         }
//     }
 
 
//     cout << dp[m][n] << "\n";
 
 
// }