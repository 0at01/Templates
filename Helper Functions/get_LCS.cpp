#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long
#define nln "\n"


string getLCS(string a, string b, int al, int bl)
{
    vector<vector<int>> dp(al+1, vector<int>(bl+1, 0));   

    for(int i=1; i<=al; i++)
    {
        for(int j=1; j<=bl; j++)
        {
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];

            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }

    string ans = "";
    int i=al, j=bl;    

    while(i>0 and j>0)
    {
        if(a[i-1] == b[j-1])
        {
            ans += a[i-1];
            i--; j--;            
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }        
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main()
{
    string a = "aafffffffdsafasd", b = "fff";
    cout << getLCS(a, b, a.length(), b.length()) << nln;

}
