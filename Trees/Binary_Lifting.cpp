#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio                  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod                     1000000007
#define ll                      long long
#define nln                     "\n"
#define vi                      vector<int>
#define vll                     vector<ll>
#define begend(x)               x.begin(), x.end()
#define printMat(arr, n, m)     for(int i=0; i<n; i++) { for(int j=0; j<m; j++){ cout << arr[i][j] << " ";} cout << nln;}
#define printArr(arr, beg, end) for(int i=beg; i<=end; i++){ cout << arr[i] << " ";}cout << nln;
#ifndef ONLINE_JUDGE
#include "debug_template.hpp"
#else
#define print(...)
#endif
bool isPo2(int n){if(n==0) return false; return (ceil(log2(n)) == floor(log2(n)));}
int toint(const string& s) {stringstream ss;ss << s;int x;ss >> x;return x;}
string tostring(int number) {stringstream ss; ss << number;return ss.str();}
ll xorUptoN(ll n){ if(n%4==0) return n; else if(n%4==1) return 1; else if(n%4==2) return n + 1; return 0;}
//---------------------------------------------------------------------------------------------------------------------------------------------------


int n;
#define N 100005
#define LOG 18
vector<vector<int>>adj;
vector<vector<int>> up;
vector<int> depth;


// Preprocessing for binary lifting

void dfs(int u, int p){
    for(auto v: adj[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;

        up[v][0] = u;
        for(int j=1; j<LOG; j++){
            up[v][j] = up[up[v][j-1]][j-1];
        }

        dfs(v, u);
    }
}


int getKthAncestor(int node, int k){
    if(depth[node]<k) return -1;
    for(int j=0; j<LOG; j++){
        if(1&(k>>j)){
            node = up[node][j];
        }
    }
    return node;
}


int LCA(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    int k = depth[x] - depth[y];

    for(int j=LOG-1; j>=0; j--){
        if(1&(k>>j)) x = up[x][j];
    }

    if(x == y) return x;

    for(int j=LOG-1; j>=0; j--){
        if(up[x][j] != up[y][j]){ // This is repeated a number of times until the position is reached
            x = up[x][j];
            y = up[y][j];
        }
    }
    return up[x][0];
}

 

int main(){
    cin >> n;
    adj.assign(n, {});
    up.assign(n, vi(LOG, -1));

    for(int i=1; i<=n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}