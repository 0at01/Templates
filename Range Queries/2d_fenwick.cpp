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
ll modExpo(ll x, ll y, int p){ ll res = 1; x = x % p; if (x == 0) return 0; while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p; }return res; }
ll mod_Inv(ll a, ll p){ return modExpo(a, p-2, p); } // for prime only
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}


ll bit[2000][2000];


void update(int ni, int nj, int n, int val){
    for(int i=ni; i<=n; i+= i&(-i)) 
        for(int j=nj; j<=n; j+= j&(-j))
            bit[i][j] += val;        
}


ll getSum(int ni, int nj){
    ll sum = 0;
    for(int i=ni; i>0; i-= i&(-i))
        for(int j=nj; j>0; j-= j&(-j))
            sum += bit[i][j];
    return sum;
}



int subMatrixSum(int x1, int y1, int x2, int y2){
    ll sum = 0;
    sum += getSum(x2, y2);
    sum -= getSum(x2, y1-1);
    sum -= getSum(x1-1, y1);
    sum += getSum(x1-1, y1-1);
    return sum;
}


int main()
{
    fastio    
    int t;
    cin >> t;    

    while(t--)
    {
        int n; cin >> n;
        string query = "start";

        memset(bit, 0, sizeof(bit));
        
        while(query!="END"){
            cin >> query;

            if(query == "SET"){
                string xs, ys, nums; cin >> xs >> ys >> nums;
                int x = toint(xs); int y = toint(ys); int num = toint(nums);
                x++; y++;


                int prevVal = subMatrixSum(x, y, x, y);
                update(x, y, n, num-prevVal);
            }
            else if(query == "SUM"){
                string x1s, y1s, x2s, y2s; cin >> x1s >> y1s >> x2s >> y2s;
                int x1 = toint(x1s), y1 = toint(y1s), x2 = toint(x2s), y2 = toint(y2s);
                x1++; y1++; x2++; y2++;


                cout << subMatrixSum(x1, y1, x2, y2) << nln;;
            }
        }        
    }
}




