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


struct acts
{
    int a, b, c;
};



int main()
{
    fastio

    int n;
    cin >> n;

    acts arr[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }


    for(int i=1; i<n; i++)
    {
        arr[i].a += max(arr[i-1].b, arr[i-1].c);
        arr[i].b += max(arr[i-1].a, arr[i-1].c);
        arr[i].c += max(arr[i-1].b, arr[i-1].a);
    }

    cout << max(arr[n-1].a, max(arr[n-1].b, arr[n-1].c)) << nln;

}