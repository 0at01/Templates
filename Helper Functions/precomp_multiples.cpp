#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define vll vector<long long>



int main(){

	vll freq(500006, 0);
	vll multiples(500006, 0);

	int n; cin >> n;
	vll arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
		freq[arr[i]]++;
	}

	for(int i=1; i<=5000000; i++){
		for(int j=i; j<=5000000; j+=i){
			multiples[i] += freq[j];
		}
	}

	
}