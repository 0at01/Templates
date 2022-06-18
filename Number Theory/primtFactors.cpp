#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

vi prmFactors(int n){vi res; for(int i=2;i*i<=n;i++){if(n%i==0){while(n%i==0)n/=i;res.pb(i); }}if(n>1)res.pb(n); return res;}

vi prmFactors(int n){
    vi res; 
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            // cout << i << endl;
            while(n%i==0)
                n/=i;
            res.push_back(i); 
        }
    }
    if(n>1)res.push_back(n); 
    return res;
}


void primeFactors(int n){
    int spf[n+1] = {0};

    for(int i=2; i<=n; i++) spf[i] = i;

    for(int i=2; i*i<=n; i++){
        if(spf[i] == i){
            for(int j=i*i; j<=n; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    while(n!=1){
        cout << spf[n] << " ";
        n = n/spf[n];
    }
}

void primeFactors2(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            int cnt = 0;

            while(n%i == 0){
                n = n/i;
                cnt++;
                cout << i << "^" << cnt << endl;
            }
        }        
    }

    if(n>1) cout << n << "^" << 1 << endl;
}


int main(){
    primeFactors2(12);
}