#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll modExpo(int base, int expo, int modulo){
    if(expo==0) return 1;
 
    ll res = modExpo(base, expo/2, modulo);
 
    if(expo&1) 
        return (((res*res)%modulo) * base)%modulo;
 
    return (res*res)%modulo;    
}




