/*
    Code by HOTSON HONET
     ______________________
    |					 |
    |					 |
    |                    |
    |                    |
    |                    |
    |                    |
__________________________________
    |\       /          /
    | \_____/          /
    |  \              /
    |   \            /
    |    \///////////
    /\    \/////////
   /__\    \______/
 
*/
 
#include <bits/stdc++.h>
 
#define ipair pair<int, int>
#define llpair pair<long long, long long>
#define llipair pair<long long int, long long int>
#define ll long long
#define ull unsigned long long
#define MAXX 1000000007
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define nline "\n"
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#include "helper_functions.h"
#else
#define print(...) 42
#endif
 
 
ll expo(ll a, ll b, ll mod = MAXX){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
 
    return res%mod;
}
 
ll mod_inverse(ll b, ll mod = MAXX){
    /*
 
        As per Euclid algorithm
        - (mod>=2)*(mod-2) to ensure we are not sending any -ve number
 
    */
    return expo(b, (mod >=2)*(mod - 2), mod);
}
 
ll mod_prod(ll a, ll b, ll mod = MAXX){
    /*
 
        a*b % mod = (a%mod * b%mod) * mod
 
    */
   return ((a%mod) * (b%mod))%mod;
}
 
ll mod_div(ll a, ll b, ll mod = MAXX){
    /*
        (a/b)%mod = (a%mod * b_inverse%mod)%mod
 
        where b_inverse = b^mod-2
    */
    return mod_prod(a, mod_inverse(b, mod), mod);
}


template<typename t> 
t gcd(t a, t b){
    return a == 0 ? b : gcd(b%a, a);
}



void solve()
{ 
    
}  
 
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input_output/input.txt", "r", stdin);
    freopen("input_output/error.txt", "w", stderr);
    freopen("input_output/output.txt", "w", stdout);
    setbuf(stdout, NULL);  // Disable buffering for output.txt
    setbuf(stderr, NULL);  // Disable buffering for error.txt
#endif
    fastio;

    const int SZ = 1e7;
    vector<int> prime_check(SZ + 1, 1);
    prime_check[0] = prime_check[1] = 0;
    for(int i = 2; i <= SZ; ++i){
        if(prime_check[i] == 0) continue;
        primes.push_back(i);
        if(i <= 5) print(primes);
        for(auto j = 2*i; j <= SZ; j += i) prime_check[j] = 0;
    }
    
    int tcs = 1;
    cin >> tcs;
 
    for (int tc = 1; tc <= tcs; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
 
#ifndef ONLINE_JUDGE
    cerr<<nline;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    cerr.flush(); // Ensure data is written to error.txt immediately
#endif
    return 0;
}