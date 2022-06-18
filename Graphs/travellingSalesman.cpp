#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int n = 4; // number of cities
int dp[(1<<n)][n]; // 1<<n is 2^n, initialising array for memoization

int adjMat[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

int VISITED_ALL = (1<<n) - 1;



int tsp(int mask, int pos)
{
    if(mask==VISITED_ALL)
        return adjMat[pos][0];
    

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    
    int ans = INT_MAX;

    
    for(int city=0; city<n; city++)
    {
        if((mask&(1<<city)) == 0)
        {
            int newAns = adjMat[pos][city] + tsp(mask|(1<<city), city);
            ans = min(ans, newAns);
        }

        
    }
    return dp[mask][pos] = ans;
}




int main()
{
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n ; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout<<"Shortest travel distance: " << tsp(1, 0);
}