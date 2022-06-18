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
#define debug(...)
#define print(...)
#endif
bool isPo2(int n){if(n==0) return false; return (ceil(log2(n)) == floor(log2(n)));}
int toint(const string& s) {stringstream ss;ss << s;int x;ss >> x;return x;}
string tostring(int number) {stringstream ss; ss << number;return ss.str();}
ll xorUptoN(ll n){ if(n%4==0) return n; else if(n%4==1) return 1; else if(n%4==2) return n + 1; return 0;}
#define vvl vector<vector<ll>>


vvl multiplyMat(vector<vll> &a, vector<vll>&b)
{
    int n = a.size();
    vector<vll> res(n, vll(n, 0));

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    for(int k=0; k<n; k++)
    res[i][j] = (res[i][j] + a[i][k]*b[k][j])%mod;

    return res;
}

vvl matrixExpo(vvl &mat, ll exp)
{
    if(exp==1) return mat;
    vvl res = matrixExpo(mat, exp/2);
    vvl ans = multiplyMat(res, res);
    if(exp%2 != 0) return multiplyMat(ans, mat);
    return ans;
}

ll walk(vvl &adj, ll k)
{
    int n = adj.size();
    vvl res = matrixExpo(adj, k);
    ll ans = 0;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ans = (ans%mod + res[i][j]%mod)%mod;

    return ans;        
}


int main()
{
    fastio

    ll n, k; cin >> n >> k;
    
    vector<vll> adj(n+1, vll(n+1));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> adj[i][j];    

    cout << walk(adj, k) << nln;

}