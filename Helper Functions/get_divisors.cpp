vi getDivisors(int n){
    vi v;
    
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            v.push_back(i);
            if((n/i) != i) v.push_back(n/i);
        }
    }

    return v;
}
