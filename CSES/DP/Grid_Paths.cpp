#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long 




int main()
{
    fastio
    
    int n;
    cin >> n;

    vector<vector<ll>> grid(n, vector<ll> (n, 0));
    vector<vector<char>> strGrid(n, vector<char> (n));


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> strGrid[i][j];

            if(strGrid[i][j] == '*') grid[i][j] = -1;
        }

    }

    if(grid[0][0] == -1 or grid[n-1][n-1] == -1)
    {
        cout << 0 << "\n";
    }

    else
    {
        grid[0][0] = 1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i != n-1 and grid[i+1][j] != -1)
                {
                    if(grid[i][j] != -1)
                        grid[i+1][j] = (grid[i+1][j] %mod + grid[i][j] %mod) %mod ;
                }
                    

                if(j != n-1 and grid[i][j+1] != -1)
                {
                    if(grid[i][j] != -1)
                        grid[i][j+1] = (grid[i][j+1] %mod + grid[i][j] %mod) %mod ;
                }    
            }

        }

        cout << grid[n-1][n-1] %mod << "\n";

    }    
    

}