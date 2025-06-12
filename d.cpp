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
    
    int n;
    cin>>n;
    vector<string> g(n);
    for(auto &s: g) cin>>s;

    print(g);
    vector<vector<int>> prefix_row(n, vector<int>(n + 1));
    for(int r = 1; r <=n; ++r) for(int c = 1; c <= n; ++c) prefix_row[r][c] = prefix_row[r][c - 1] + int(g[r - 1][c - 1] == '#');

    
    vector<vector<int>> prefix_col(n, vector<int>(n + 1));
    for(int r = 1; r <=n; ++r) for(int c = 1; c <= n; ++c) prefix_col[r][c] = prefix_col[r - 1][c] + int(g[r - 1][c - 1] == '#');

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[0][0][1][1] = int(g[0][0] == '#');

    for(int r1 = 1; r1 <= n; ++r1) for(int c1 = 1; c1 <= n; ++c1) {
        for(int r2 = r1 + 1; r2 <= n; ++r2) for(int c2 = c1 + 1; c2 <= n; ++c2){
            // counting the no of black cells in the grid
                
            dp[r1][c1][r2][c2] = max(r2 - r1, c2 - c1);
            
            dp[r1][c1][r2][c2] = min({
                dp[r1][c1][r2][c2],

            })
        }
    }

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
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    cerr.flush(); // Ensure data is written to error.txt immediately
#endif
    return 0;
}