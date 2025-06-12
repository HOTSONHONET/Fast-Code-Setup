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


    int h, w, n;
    cin>>h>>w>>n;

    vector<llpair> cells(n + 1);
    for(int i = 0; i < n; ++i) cin>>cells[i].first>>cells[i].second;
    cells.push_back({h, w});

    vector<ll> dp(n + 1, 0);
    const ll mod = 1e9 + 7;
    const int sz = 2*max(h, w) + 1;
    vector<ll> f(sz, 1);

    for(int i = 1; i < sz; ++i) f[i] = (f[i] * f[i - 1]) % mod;

    auto ways = [&](int r1, int c1, int r2, int c2)->ll {
        return mod_div(f[r2 - r1 + c2 - c1], (f[c2]*f[c1]), mod);
    };

    sort(cells.begin(), cells.end());
    print(cells);
    for(int i = 0; i <= n; ++i){
        auto [r2, c2] = cells[i];
        dp[i] = ways(1, 1, r2, c2);
        for(int j = 0; j < i; ++j){
            auto [r1, c1] = cells[j];
            dp[i] -= dp[j] * ways(r1, c1, r2, r2); // number of ways to reach from (1, 1) to jth cell and from the jth cell to the current cell
        }
    }

    ll ans = dp.back() % mod;
    cout<<ans<<nline;

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
    int tcs = 1;
    // cin >> tcs;
 
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