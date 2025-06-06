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


void solve(){ 
    int n, m;
    cin>>n>>m;
    vector<int> b(n);
    for(auto &ele: b) cin>>ele;

    vector<vector<pair<int, ll>>> graph(n);
    for(int i = 0; i < m; ++i){ 
        int a, b;
        cin>>a>>b;
        ll w;
        cin>>w;
        --a, --b;
        graph[a].push_back({b, w});
    }

    vector<llpair> range_finder(n, {-1,-1});
    int ans = -1;
    range_finder[0] = {0, b[0]};
    auto dfs = [&](auto &&self, int node, int p = -1)->void {
        auto [L, R] = range_finder[node];

        print(range_finder);
        for(auto [n_node, w]: graph[node]){
            if(n_node == p) continue;
            if(w <= R){ 
                ll tmp_L = max(L, w);
                if(range_finder[n_node].first == -1LL) range_finder[n_node] = {tmp_L, R + b[n_node]};
                else{
                    auto [L_, R_] = range_finder[n_node];
                    if(L_ > tmp_L || (L_ == tmp_L && R + b[n_node] > R_)) range_finder[n_node] = {tmp_L, R + b[n_node]};
                }
            }
            self(self, n_node, node);
        }
    };

    dfs(dfs, 0, -1);

    cout<<range_finder[n - 1].first<<nline;

   
}  


int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input_output/input.txt", "r", stdin);
    freopen("./input_output/error.txt", "w", stderr);
    freopen("./input_output/output.txt", "w", stdout);
#endif
    fastio;

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}