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



struct fenwickTree{
    vector<int> bit;
    int n; 

    fenwickTree(int n){
        this->n = n;
        bit.assign(n+1, 0);
    }

    fenwickTree(vector<int> arr){ // init bit with array in O(n) instead of O(nlogn)
        bit = arr;
        n = (int) arr.size();

        for(int i=1; i<n; i++){
            int p = i + (i&-i);
            if(p<n){
                bit[p] += bit[i];
            }
        }
    }

    int sum(int r){
        int res = 0;
        while(r>0){ // At 0 it will get trapped in infinite loop becasue 0&-0=0
            res += bit[r];
            r -= (r&-r);
        }
        return res;
    }

    void add(int i, int val){
        while(i<n){
            bit[i] += val;
            i += (i&-i);
        }
    }

    int rangeSum(int l, int r){
        if(l==0) return sum(r);
        return sum(r) - sum(l-1);
    }
};







int main(){
    vector<int> arr;
    fenwickTree f1 = fenwickTree(arr);
    // For range update: update bit[l] with +val and bit[r+1] with -val
}
