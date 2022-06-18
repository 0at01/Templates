#pragma GCC optimize "trapv"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//---------------------------------------------------------Macros------------------------------------------------------------------------------------------------
#define fastio      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod         1000000007
#define ll          long long
#define nln         "\n"
#define vi          vector<int>
#define vll         vector<ll>
#define vch         vector<char>
#define begend(x)   x.begin(), x.end()
#define cln         cerr << nln;
#define csp         cerr << " ";
#define ff          first
#define ss          second
#define eb          emplace_back
#define pb          push_back
#define sz(x)       (int)x.size()
#define pi          pair<int, int>
#define pll         pair<ll, ll> 
//--------------------------------------------------Local Debug Template-----------------------------------------------------------------------------------------
 #ifndef ONLINE_JUDGE
#include "debug_template.hpp"
#else
#define debug(...)
#endif 
//--------------------------------------------------------Utils--------------------------------------------------------------------------------------------------
 #define printMat(arr, n, m) for(int i=0; i<n; i++) { for(int j=0; j<m; j++){ cout << arr[i][j] << "";} cout << nln;}
#define printArr(arr, beg, end) for(int i=beg; i<=end; i++){ cout << arr[i] << " ";}cout << nln;
bool isPo2(int n){if(n==0) return false; return (ceil(log2(n)) == floor(log2(n)));}
int toint(const string& s) {stringstream ss;ss << s;int x;ss >> x;return x;}
string tostring(int number) {stringstream ss; ss << number;return ss.str();}
ll xorUptoN(ll n){ if(n%4==0) return n; else if(n%4==1) return 1; else if(n%4==2) return n + 1; return 0;}
ll modExpo(ll x, ll y, int p){ ll res = 1; x = x % p; if (x == 0) return 0; while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p; }return res; }
ll mod_Inv(ll a, ll p){ return modExpo(a, p-2, p); } // for prime only
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
 //---------------------------------------------------------------------------------------------------------------------------------------------------------------

vi precomputedPowers(1000006);

vector<vll> st;
vi arr;
int n;

void buildTable(){
	for(int i=0; i<n; i++) st[i][0] = arr[i];

	precomputedPowers[1] = 0;
	for(int i=2; i<n; i++) precomputedPowers[i] = log2(i);

	for(int j=1; j<25; j++){
		for(int i=0; i<n; i++){
			if((i+(1<<(j-1))) < n)
			st[i][j] = __gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
}

int getRangeGcd(int l, int r){
	int lr = r - l + 1;
	int po2 = precomputedPowers[lr];
	int res = __gcd(st[l][po2], st[r - pow(2, po2) +1][po2]);
	return res;
}
 
 
int main()
{
    fastio    
    #ifndef ONLINE_JUDGE 
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
 
    cin >> n;
    st.assign(n+1, vll(25));
    arr.assign(n+1, 0);
	for(int i=0; i<n; i++) cin >> arr[i];	

 
}
