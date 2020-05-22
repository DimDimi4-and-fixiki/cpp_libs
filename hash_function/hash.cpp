// hash-function

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll binpow(ll a, ll n, ll mod){ // fast power
    if(n == 0){
        return 1;
    }
    if(n % 2 == 1){
        return binpow(a, n - 1, mod) * a % mod;
    }else{
        ll b = binpow(a, n / 2, mod);
        return b * b % mod;
    }
}


inline void get_straight_hash(int * s, int n, ll * hash, ll p, ll mod){ // straight hash
    hash[0] = 0;
    for(int i = 0; i < n; ++i){
        hash[i + 1] = (hash[i] + binpow(p, i, mod) * s[i]) % mod;
    }
}

inline ll get_straight_substr(ll * hash, ll p, ll mod, int l, int r){ // get hash of substring
    ll n = 1e5;
    return ((hash[r] - hash[l - 1]) * binpow(p, n - l, mod) % mod + mod) % mod;
}
