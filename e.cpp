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

const int N = 1e6+1;
vector<vector<int>> cnt(N);

void solve()
{
    int n;
    cin>>n;

    map<int, int> finder;
    vector<int> v(n);
    int g = 1;
    for(auto &i: v){
        cin>>i;
        for(auto f: cnt[i]){
            finder[f]++;
            if(g == INT_MIN) g = f;
            if(finder[f] >= 2 && f>g) g = f;
        } 
    } 

    cout<<g<<nline;

}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input_output/input.txt", "r", stdin);
    freopen("input_output/error.txt", "w", stderr);
    freopen("input_output/output.txt", "w", stdout);
#endif
    fastio;

    for(int i=1; i<=N; ++i){
        for(int j = i; j<=N; j += i){
            cnt[j].push_back(i);
        }
    }

    int tcs = 1;
    // cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}