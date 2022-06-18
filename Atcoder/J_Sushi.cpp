#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout << " Debug \n";
#define mod 1000000007
#define ll long long
#define nln "\n"
#define vi vector<int>
#define vll vector<ll>
#define begend(x) x.begin(), x.end()
#define printMat(arr, n, m) for(int i=0; i<n; i++) { for(int j=0; j<m; j++){ cout << arr[i][j] << " ";} cout << nln;}
#define printArr(arr, beg, end) for(int i=beg; i<=end; i++){ cout << arr[i] << " ";}cout << nln;

int dp[300][300][300];


int main()
{
    fastio

    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vi arr(n);
    unordered_map<int, int> freq;
    for(int i=0; i<n; i++){
    	cin >> arr[i];
    	freq[arr[i]]++;
    }

    
    memset(dp, 0, sizeof(dp));

    dp[0][0][0] = 0;

    for(int threes=0; threes<freq[3]; threes++){
    	for(int twos=0; twos<freq[2]; twos++){
    		for(int ones=0; ones<freq[1]; ones++){
    			
    			dp[ones][twos][threes]=n;

    			if(ones-1>=0)
    				dp[ones][twos][threes] += dp[ones-1][twos][threes];
    			if(twos-1>=0)
    				dp[ones][twos][threes] += dp[ones+1][twos-1][threes];
    			if(threes-1>=0)
    				dp[ones][twos][threes] += dp[ones][twos+1][threes-1];

    			dp[ones][twos][threes] /= (ones+twos+threes);
    		}
    	}
    }

    cout << dp[freq[1]][freq[2]][freq[3]] << nln;

}