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




ll modExpo(int base, int expo, int modulo){
    if(expo==0) return 1; 
    ll res = modExpo(base, expo/2, modulo); 
    if(expo&1) return (((res*res)%modulo) * base)%modulo; 
    return (res*res)%modulo;    
}


// power+1 because 0 is also included in the powers
int geometricSum(int base, int power){
    ll numerator = (modExpo(base, power+1, mod)-1+mod)%mod;
    ll denominator = modExpo(base-1, mod-2, mod);
    return (numerator*denominator)%mod;
}


int main()
{
    fastio

    int n; cin >> n;
    vi prime(n), expv(n);
    for(int i=0; i<n; i++) cin >> prime[i] >> expv[i];

    ll numDivisors = 1;
    for(int i=0; i<n; i++)
        numDivisors = ((numDivisors)%mod * (expv[i]+1)%mod)%mod;

    
    ll divisorSum = 1;
    for(int i=0; i<n; i++)
        divisorSum = (divisorSum * geometricSum(prime[i], expv[i]))%mod;    


    ll divisorsProduct = 1;
    bool oddExp = false;
    int oddPos;
    for(int i=0; i<n; i++){
        if(expv[i]%2){
            oddExp=true;
            oddPos = i;
        }
    }    
    if(oddExp){
        ll outerExpo = 1;
        for(int i=0; i<n; i++){
            if(i==oddPos) outerExpo = (outerExpo * (expv[i]+1)/2)%(mod-1);
            else outerExpo = (outerExpo * (expv[i]+1))%(mod-1);
        }

        for(int i=0; i<n; i++)
            divisorsProduct = (divisorsProduct * modExpo(prime[i], (expv[i]*outerExpo)%(mod-1), mod))%mod;
    }
    else{
        ll outerExpo = 1;
        for(int i=0; i<n; i++) 
            outerExpo = (outerExpo * (expv[i]+1))%(mod-1);
        for(int i=0; i<n; i++)
            divisorsProduct = (divisorsProduct * modExpo(prime[i], ((expv[i]/2)*outerExpo)%(mod-1), mod))%mod;
    }

    cout << numDivisors << ' ' << divisorSum << ' ' << divisorsProduct << nln;

}

// The division by 2 for product doesn't work because for taking inverse we need to take 
// mod of 2 with (mod-1), but 2 and mod-1 are not coprime, so the inverse is not possible.