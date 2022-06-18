#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pi pair<int, int>
// CSES - Traffic lights

// The comparator only works with a struct and not with other things like pair
struct street{
    int l, r; 
};

// Don't forget passing by reference and the 3 consts used
struct cmp1{
    bool operator()(const street &s1, const street &s2) const{
        return s1.l < s2.l;
    }
};

struct cmp2{
    bool operator()(const street &s1, const street &s2) const{
        return ((s1.r - s1.l) < (s2.r - s2.l));
    }
};


// The appropriate cmp must also be passed in function parameter.
void printSet(multiset<street, cmp2> ms){
    auto it=ms.begin();
    while(it!=ms.end()){
        street st = *it;
        cout << "(" <<  st.l << " " << st.r << ") ";
        it++;
    }
}


int main(){
    fastio    
    #ifndef ONLINE_JUDGE 
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    
    int n, m; cin >> n >> m;
    multiset<street, cmp1> ms1; // for start points
    multiset<street, cmp2> ms2; // for segment length

    street start;
    start.l = 0, start.r = n;
    ms1.insert(start);
    ms2.insert(start);

    for(int i=0; i<m; i++){
        int p; cin >> p;
        street point; 
        point.l = p, point.r = INT_MAX;
        auto lb = ms1.lower_bound(point);
        if(lb==ms1.begin()) continue;

        lb--;
        street lbS = *lb;

        if(lbS.r >= p){
            street s1, s2;
            s1.l=lbS.l; s1.r = p;
            s2.l = p; s2.r = lbS.r;
            ms1.erase(ms1.find(lbS)); ms2.erase(ms2.find(lbS));
            ms1.insert(s1); ms2.insert(s1);
            ms1.insert(s2); ms2.insert(s2);
        }

        street maxStreet = *ms2.rbegin();
        cout << maxStreet.r - maxStreet.l << " ";
    }

}