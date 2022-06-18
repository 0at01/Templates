#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int u, v, wt;
	node(int first, int second, int weight){
		u = first;
		v = second;
		wt = weight;
	}
};

vector<node> edges;
vector<int> dist;

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input1.txt", "r", stdin);
	    freopen("output1.txt", "w", stdout);
	#endif

	int n, m; cin >> n >> m;
	for(int i=0; i<m; i++){
		int u, v, w; cin >> u >> v >> w;
		edges.push_back(node(u, v, w));
	}

	int src = 0;
	dist[src] = 0;

	for(int i=0; i<n-1; i++){
		for(auto e: edges){
			if(e.u + e.wt < dist[e.v]){
				dist[e.v] = e.u = e.wt;
			}
		}
	}

	bool hasCycle = false;
	for(auto e: edges){
		if(e.u + e.wt < dist[e.v]){
			hasCycle = true;
			break;
		}
	}

	if(!hasCycle){
		for(int i=1; i<=n; i++) cout << dist[i] << ' ';
	}


}