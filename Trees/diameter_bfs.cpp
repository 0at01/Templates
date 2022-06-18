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
vector<int> par(n+1);
int max_dist, res;


pair<int, int> bfs(int v, int n, vector<int> &dist){
    queue<int> q;
    dist[v] = 0;
    q.push(v);
    int res = v; // node with answer;
    max_dist = 0;

    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(auto k: adj[v]){
            if(dist[k] > dist[curr]+1){ // This condition is generally not required
                dist[k] = dist[curr]+1; // Can be done with parent vec or visited vec
                if(max_dist < dist[k]){
                    max_dist = dist[k];
                    res = k;
                }
                q.push(k);
                par[k] = curr;
            }
        }
    }

    return {res, max_dist};
}



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

    pair<int, int> p = bfs(0, n, d1);
    pair<int, int> p2 = bfs(p.first, n, d1);
    cout << "Diameter = " << p.second;

}