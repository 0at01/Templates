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
#define printMat(arr, n, m) for(int i=0; i<n; i++) { for(int j=0; j<m; j++){ cout << arr[i][j] << " ";} cout << nln;}
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

int n;
vector<vector<int>> adj(n+1);
int max_dist, res;

// Default is initialized like this if you don't want the user to know the parameters
// GPP
void dfs(int u, vector<int>&dist, int p=-1, int d=0){
    dist[u] = d;
    if(max_dist<d){
        max_dist = d;
        res = u;
    }
    for(auto v: adj[u]){
        if(v==p) continue;
        dfs(v, dist, u, d+1);
    }
}


// Pick a random node, generally 0, then find the farthest node, and from that farthest node
// find the next farthest node, the distance between these two will be the diameter



int main()
{
    fastio

    cin >> n;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> d1(n, 0);

    max_dist = 0;
    dfs(0, d1);

    max_dist = 0;
    dfs(res, d1);
    cout << "Diameter = " << max_dist;

}