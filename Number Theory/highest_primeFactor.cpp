#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long
#define nln "\n"


// For single queries O(sqrt(n))

ll hpf(ll n){
    ll maxPrime = -1;
    
    while(n%2==0){
        maxPrime = 2;
        n >>=1;
    }
    while(n%3==0){
        maxPrime = 3;
        n /= 3;
    }

    for(int i=5; i*i<=n; i+=6){
        while(n%i==0){
            maxPrime = i;
            n /= i;
        }
        while((n%(i+2)) == 0){
            maxPrime = i+2;
            n /= (i+2);
        }
    }

    if(n>4) maxPrime = n; 

    return maxPrime;
}


// Precomputed hpf for multiple queries 

const int N = 1e6;
int hipf[N + 1];
void pFactors(){
    for (int i = 2; i * i <= N; i++){
        if (hipf[i] == 0){
            for (int j = i * i ; j <= N; j+=i){
                if (hipf[j] == 0){
                    hipf[j] = i;
                }
            }
        }
    }
}

int largestprime(int n){
    while (hipf[n] != 0){
        n = n/hipf[n];
    }
    return n;
}




int main()
{
    pFactors();
    cout << largestprime(14) << nln;
    cout << hpf(14) << nln;
}