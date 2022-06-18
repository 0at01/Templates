#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long




void solve(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	vector<int> prefLis(n), temp;
	for(int i=0; i<n; i++){
		auto it = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
		if(it == ((int)temp.size())) temp.push_back(arr[i]);
		else temp[it] = arr[i];
		prefLis[i] = (int)temp.size();
	}

	vector<int> suffLis(n), temp2;
	for(int i=n-1; i>=0; i--){
		auto it = lower_bound(temp2.begin(), temp2.end(), -arr[i]) - temp2.begin();
		if(it == ((int)temp2.size())) temp2.push_back(-arr[i]);
		else temp2[it] = -arr[i];
		suffLis[i] = (int)temp2.size(); 
	}

	int res = suffLis[0];
	for(int i=1; i<n; i++){
		res = max(res, suffLis[i] + prefLis[i-1]);
	}

	cout << res << "\n";
}



int main(){
    fastio    
    #ifndef ONLINE_JUDGE 
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
 
    int t; cin >> t;
    while(t--){
        solve();
    } 
}