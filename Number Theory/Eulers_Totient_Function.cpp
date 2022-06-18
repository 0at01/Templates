#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//  EULER'S TOTIENT FUNCTION (refer notes for proof)


// O(sqrt(N)) approach: using modified prime factorization
// This is better for single query
int phi1(int n)
{
    // Initializing res with n, as res has to be multiplied by n later
    int res = n; 

    for(int i=2; i<sqrt(n); i++)
    {
        if(n%i == 0)
        {
            res *= (i-1); // calcuating res from the formula
            res /= i;

            while(n%i==0) // std step used in prime factorization
                n/=i;
        }
    }

    if(n>1)
    {
        res *= (n-1);
        res /= n;
    }

    return res;
}



// O( n log(log(n)) ): using Sieve
//for multiple queries

vector<int> phi(100000 + 1);

void phi_1_to_n(int n) {
    
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}


int main()
{
    //cout << phi1(500) << endl;

    phi_1_to_n(100000);
    cout << phi[5] << endl;
}

