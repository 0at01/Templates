#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define ll long long




int main()
{
    int n; cin >> n; 

    set<ll> sat;

    while(n--)
    {
        int x; 
        cin >> x;

        if(sat.size() == 0)
        {
            sat.insert(x);
            continue;
        }

        vector<ll> vec;

        for(auto it = sat.begin(); it != sat.end(); it++)
        {
            vec.push_back(*it + x);
        }

        sat.insert(x);

        for(auto e: vec) sat.insert(e);        

    }

    cout << sat.size() << "\n";

    for(auto it = sat.begin(); it != sat.end(); it++) cout << *it << " ";


    

}