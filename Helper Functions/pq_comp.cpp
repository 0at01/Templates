#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define pii pair<int, int>

int main(){
    auto cmp2 = [](pii a, pii b){
        if(a.first!=b.first) return a.first > b.first;
        else return a.second < b.second;
    };

    priority_queue <pii, vector<pii>, decltype(cmp2)> pq(cmp2);
}