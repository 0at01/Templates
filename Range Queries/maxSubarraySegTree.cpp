#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long



struct segTree{
    
    struct node{
        int maxPref, maxSuff, maxSubArr, sum;
    };

    vector<node> seg;
    vector<int> arr;
    int n;

    segTree(vector<int> arr2){
        arr = arr2;
        n = arr2.size();
        seg.assign(4*n, {0, 0, 0, 0});
    }

    node merge(node n1, node n2){
        node n3;
        n3.sum = n1.sum + n2.sum;
        n3.maxPref = max(n1.maxPref, n1.sum + n2.maxPref);
        n3.maxSuff = max(n2.maxSuff, n1.maxSuff + n2.sum);
        n3.maxSubArr = max({n2.maxSubArr, n1.maxSubArr, n1.maxSuff + n2.maxPref});
        return n3;
    }

    void buildSegtree(int v, int tl, int tr){
        if(tl==tr){
            seg[v].sum = seg[v].maxSuff = seg[v].maxPref = seg[v].maxSubArr = arr[tl];
            return;
        }
        int tm = tl + (tr-tl)/2;
        buildSegtree(2*v, tl, tm);
        buildSegtree(2*v+1, tm+1, tr);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }

    void update(int v, int tl, int tr, int pos, int newVal){
        if(tl==tr){
            seg[v].sum = seg[v].maxSuff = seg[v].maxPref = seg[v].maxSubArr = newVal;
            return;
        }
        int tm = tl + (tr-tl)/2;
        if(pos<=tm) update(2*v, tl, tm, pos, newVal);
        else update(2*v+1, tm+1, tr, pos, newVal);
        seg[v] = merge(seg[2*v], seg[2*v+1]);
    }

};



void solve(){
    int n; cin >> n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    segTree s1 = segTree(arr);
    s1.buildSegtree(1, 0, n-1);   
}



int main(){
    fastio    
    #ifndef ONLINE_JUDGE 
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
 
    int t=1; 
    cin >> t;
    for(int T=1; T<=t; T++){
        solve();
    } 
}
