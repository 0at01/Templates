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
#define printMat(arr, n, m) for(int i=0; i<n; i++) { for(iknt j=0; j<m; j++){ cout << arr[i][j] << " ";} cout << nln;}
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


struct flowers{
    ll height;
    ll beauty;
};


ll solve_flowers(vector<flowers> &arr, int n){
    vector<ll> dp(n+1);
    map<ll, ll> mp;
    dp[1] = arr[1].beauty;
    mp[arr[1].height] = arr[1].beauty;
    ll ans = arr[1].beauty;

    for(int i=2; i<=n; i++){
        dp[i] = arr[i].beauty;
        auto it = mp.upper_bound(arr[i].height);

        if(it!=mp.begin()){
            it--;
            dp[i] += (*it).second;            
        }

        mp[arr[i].height] = dp[i];
        auto it2 = mp.upper_bound(arr[i].height);

        // the second condition in while below works because the order of beauty has been
        // preserved so far and it is in increasing order
        // By doing this both height and beauty are in increasing order
        while(it2!=mp.end() and (*it2).second<=dp[i]){
            auto nxt = it2;
            nxt++;
            mp.erase(it2);
            it2 = nxt;
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}



int main(){
    fastio    
    int n; cin >> n;    
    vector<flowers> arr(n+1);
    for(int i=1; i<=n; i++) cin >> arr[i].height;
    for(int i=1; i<=n; i++) cin >> arr[i].beauty;

    ll res = solve_flowers(arr, n);
    cout << res << nln;

}