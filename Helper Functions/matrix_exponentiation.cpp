#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>


vvl multiplyMat(vector<vll> &a, vector<vll>&b)
{
    int n = a.size();
    vector<vll> res(n, vll(n, 0));

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    for(int k=0; k<n; k++)
    res[i][j] = (res[i][j] + a[i][k]*b[k][j])%mod;

    return res;
}

vvl matrixExpo(vvl &mat, ll exp)
{
    if(exp==1) return mat;
    vvl res = matrixExpo(mat, exp/2);
    vvl ans = multiplyMat(res, res);
    if(exp%2 != 0) return multiplyMat(ans, mat);
    return ans;
}