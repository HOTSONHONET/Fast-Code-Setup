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

int N = 2e5 + 1;
vector<ll> fact(N, 1);

ll inverse(ll a, ll b){
    ll r = 1;
    for(; b>0; b/=2, a = (a * a) % MAXX){
        if(b&1){
            r = (r*a) % MAXX;
        }
    }

    return r;
}

ll C(ll n, ll k){
    if(n < k) return 0LL;

    return (fact[n] * inverse((fact[n - k] * fact[k]) % MAXX, MAXX - 2)) % MAXX;
}

void solve()
{      
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i: v) cin>>i;

    sort(v.begin(), v.end());
    int ans = v[n/2];
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
    
    // Populating factorial
    for(int i = 1; i<N; ++i) fact[i] = (1LL * i * fact[i - 1]) % MAXX;
    
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