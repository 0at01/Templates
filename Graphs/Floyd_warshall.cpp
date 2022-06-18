#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Declare global distance matrix d
vector<vector<ll>> d;

void floyd_warshall(int n){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if((d[i][k]==LLONG_MAX) or (d[k][j]==LLONG_MAX)) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main()
{
    int n, m, q; cin >> n >> m >> q;
    d.assign(n+1, vector<ll>(n+1, LLONG_MAX));
    for(int i=1; i<=n; i++) d[i][i] = 0; //distance to self is 0
    
    for(int i=0; i<m; i++){// Input the weights between edges
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = min((ll)c, d[a][b]); // This is for bidirectional edges
        d[b][a] = min((ll)c, d[b][a]);
    }

    floyd_warshall(n);

    for(int i=0; i<q; i++){// Printing the distance between a and b for each query
        int a, b; cin >> a >> b;
        if(d[a][b] != LLONG_MAX) cout << d[a][b] << "\n";
        else cout << -1 << "\n";
    }

}