#include<iostream>
using namespace std;
#include<bits/stdc++.h>


// b is remainder, a is dividend
// x and y are coefficients of extended euclidean equation


struct triplet
{
    int x, y, gcd;
};


triplet extended_euclid(int a, int b)
{
    if(b==0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    triplet smallAns = extended_euclid(b, a%b);

    triplet ans2;
    ans2.gcd = smallAns.gcd;
    ans2.x = smallAns.y;
    ans2.y = smallAns.x - (a/b)*smallAns.y;

    return ans2;
    
}


int main()
{
    int a, b; cin >> a >> b;

    triplet ans = extended_euclid(a, b);

    cout << ans.gcd << " " << ans.x << " " << ans.y << endl;
}
