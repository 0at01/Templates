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



struct Job
{
    ll start, finish, price;
};


bool cmp(Job a, Job b)
{
    return a.finish < b.finish;
}




int binarySearch(Job arr[], int i)
{
    int lo = 0, hi = i-1;

    while(lo <= hi)
    {
        ll mid = lo + (hi-lo)/2;

        if(arr[mid].finish < arr[i].start)
        {
            if(arr[mid+1].finish < arr[i].start)
                lo = mid + 1;

            else 
                return mid;    
        }

        else
            hi = mid - 1;        
        
    }
    return -1;
}




int main()
{
    int n;
    cin >> n;

    struct Job arr[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i].start >> arr[i].finish >> arr[i].price;
    }

    sort(arr, arr+n, cmp);


    vll dp(n, 0);
    dp[0] = arr[0].price;   

    for(int i=1; i<n; i++)
    {
        ll excl = dp[i-1];

        ll incl = arr[i].price;

        ll idx = binarySearch(arr, i);
        if(idx != -1)
        {
            incl += dp[idx];
        }

        dp[i] = max(incl, excl);

    }


    cout << dp[n-1] << nln;


}