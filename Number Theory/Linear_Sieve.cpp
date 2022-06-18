// modified seive with O(N) time

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long
#define nln "\n"
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define begend(x) x.begin(), x.end()
#define printMat(arr, n, m) for(int i=0; i<n; i++) { for(int j=0; j<m; j++){ cout << arr[i][j] << " ";} cout << nln;}
#define printArr(arr, beg, end) for(int i=beg; i<=end; i++){ cout << arr[i] << " ";}cout << nln;
#ifndef ONLINE_JUDGE
#include "debug_template.hpp"
#else
#define debug(...)
#endif
bool isPo2(int n){if(n==0) return false; return (ceil(log2(n)) == floor(log2(n)));}
int getMSD(ll n){ long double k = log10(n); k -= floor(k); ll x = pow(10, k); return x;}
int toint(const string& s) {stringstream ss;ss << s;int x;ss >> x;return x;}
string tostring(int number) {stringstream ss; ss << number;return ss.str();}
ll xorUptoN(ll n){ if(n%4==0) return n; else if(n%4==1) return 1; else if(n%4==2) return n + 1; return 0;}
ll modExpo(ll x, ll y, int p){ ll res = 1; x = x % p; if (x == 0) return 0; while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p; }return res; }
ll mod_Inv(ll a, ll p){ return modExpo(a, p-2, p); } // for prime only
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}


const int MAX_SIZE = 2800001;
vector<int>isprime(MAX_SIZE , true);
vector<int> idx(MAX_SIZE);
vector<int> prime;
vector<int>SPF(MAX_SIZE);

void manipulated_seive(int N){
    isprime[0] = isprime[1] = false ;
    for (int i = 2; i < N ; i++) {
        if (isprime[i]) {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
            isprime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j] ;
        }
    }
    for (int i = 0; i < (int)prime.size(); i++){
        idx[prime[i]] = i + 1;
    }
}



int main()
{
    fastio    
    #ifndef ONLINE_JUDGE 
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

   manipulated_seive(100);

   for(int i=1; i<=40; i++) cout << i << ' ' << isprime[i] << nln;

}


