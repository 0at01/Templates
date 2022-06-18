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

vector<int> graph[100005];

int dp[100005];



int findlongestPath(int src)
{
    if(dp[src] != -1)
        return dp[src];

    int noNbr = true;

    int result = INT_MIN;

    for(auto nbr: graph[src])
    {
        noNbr = false;

        result =  max(result, findlongestPath(nbr));
    }

    return dp[src] = noNbr ? 0 : 1 + result;

}





int main()
{
    fastio

    #ifndef ONLINE_JUDGE 
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

    memset(dp, -1, sizeof(dp));

    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int u, v;
        cin >> u >> v;

         graph[v].push_back(v);        
    
    }
 
    int ans = INT_MIN;

    for(int i=1; i<=n; i++)
    {
        ans = max(ans, findlongestPath(i));
    }

    cout << ans << nln;


}