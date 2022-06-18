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
bool isPo2(int n){if(n==0) return false; return (ceil(log2(n)) == floor(log2(n)));}
int toint(const string& s) {stringstream ss;ss << s;int x;ss >> x;return x;}
string tostring(int number) {stringstream ss; ss << number;return ss.str();}
ll xorUptoN(ll n){ if(n%4==0) return n; else if(n%4==1) return 1; else if(n%4==2) return n + 1; return 0;}




vector<bool> isprime(100005, 1);

void sieve(vector<int> &primes)
{
    isprime[0] = 0;
    isprime[1] = 0;

    for(int i=2; i*i<100005; i++)
    {
        if(isprime[i])

        for(int j=i*i; j<100005; j+=i)
        {
            isprime[j] = 0;
        }
    }

    for(int i=0; i<100005; i++)
        if(isprime[i]) primes.emplace_back(i);
}




void segmentedSieve(ll l, ll r, vector<int> primes)
{
    vector<bool> dummy(l-r+1, 1);

    for(auto p: primes)
    {   
        int firstMultiple = (l/p)*p;
        if(firstMultiple<l) firstMultiple += p;

        for(int i=max(firstMultiple, p*p); i<=r; i+=p)
        {
            dummy[i-l] = false;
        }
    }

    for(int i=l; i<=r; i++)
    {
        if(dummy[i-l]) cout << i << ' ';
    }

    cout << endl;   
}









int main()
{
    fastio

    vector<int> primes;

    sieve(primes);

    segmentedSieve(1, 20, primes);
}