#include<bits/stdc++.h>
using namespace std;
#define ll long long


// Range updates and queries with lazy prop
struct segTree{
    vector<int> seg, arr, lazy;
    vector<bool> hasUpdate;

    segTree(int n, vector<int> arr2){
        arr = arr2;
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
        hasUpdate.assign(4*n, 0);
    }

    void buildSegtree(int v, int tl, int tr){
        if(tl==tr){
            seg[v] = arr[tl];
            return;
        }
        int tm = tl + (tr-tl)/2;
        buildSegtree(2*v, tl, tm);
        buildSegtree(2*v+1, tm+1, tr);
        seg[v] = seg[2*v] + seg[2*v+1];
    }

    int rangeSum(int v, int tl, int tr, int l, int r){
        if(l>r) return 0;
        if(tl==l and tr==r){
            return seg[v];
        }
        int tm = tl + (tr-tl)/2;
        return rangeSum(2*v, tl, tm, l, min(r, tm)) +
                rangeSum(2*v+1, tm+1, tr, max(l, tm+1), r);
    }

    void push(int v){
        if(hasUpdate[v]){
            lazy[2*v]  += lazy[v];
            seg[2*v] += lazy[v];

            lazy[2*v+1] += lazy[v];
            seg[2*v+1] += lazy[v];

            lazy[v] = 0;
            hasUpdate[2*v] = hasUpdate[2*v+1] = true;
            hasUpdate[v] = false;
        }
    }

    void rangeUpdate(int v, int tl, int tr, int l, int r, int newVal){
        if(l>r) return;
        if(tl==l and tr==r){
            seg[v] += newVal;
            lazy[v] += newVal;
        }
        push(v);
        int tm = tl + (tr-tl)/2;
        rangeUpdate(2*v, tl, tm, l, min(r, tm), newVal);
        rangeUpdate(2*v+1, tm, tr, max(l, tm+1), r, newVal);
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input1.txt", "r", stdin);
	    freopen("output1.txt", "w", stdout);
	#endif

	ll n; cin >> n;
	vector<ll> arr(n);
	for(int i=0; i<n; i++){
	    cin >> arr[i];
	}

	segTree segtree1 = segTree(n, arr);
}


// struct segTree{
//     vector<ll> seg;
//     vector<ll> arr;

//     segTree(int n, vector<ll> arr2){
//         seg.assign(4*n, 0);
//         arr = arr2;
//     }

//     void buildSegtree(int v, int tl, int tr){
//         if(tl==tr){
//             seg[v] = arr[tl];
//             return;
//         }
//         int tm = tl + (tr - tl)/2;
//         buildSegtree(2*v, tl, tm);
//         buildSegtree(2*v+1, tm+1, tr);
//         seg[v] = max(seg[2*v], seg[2*v+1]);
//     }


//     ll rangeMax(int v, int tl, int tr, int l, int r){
//         if(l>r) return LLONG_MIN;
//         if(tl==l and tr==r) return seg[v];
//         int tm = tl + (tr - tl)/2;
//         return max(rangeMax(2*v, tl, tm, l, min(tm, r)), 
//                     rangeMax(2*v+1, tm+1, tr, max(tm+1, l), r));
//     }

//     void update(int v, int tl, int tr, int pos, int newVal){
//         if(tl==tr){
//             seg[v] = newVal;
//             return;
//         }
//         int tm = tl + (tr - tl)/2;
//         if(pos > tm) update(2*v+1, tm+1, tr, pos, newVal);
//         else update(2*v, tl, tm, pos, newVal);
//         seg[v] = max(seg[2*v], seg[2*v+1]);
//     }

// };
