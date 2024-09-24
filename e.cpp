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


vector<ll> shortest_path(int n, const vector<vector<pair<int, int>>> &g, const vector<bool> &hs, int src) {

    vector<vector<ll>> d(2, vector<ll>(n + 1, LLONG_MAX));

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;

    d[0][src] = 0;
    pq.emplace(0, 0, src);

    if(hs[src]) {
        d[1][src] = 0;
        pq.emplace(0, 1, src);
    }

    while(!pq.empty()) {
        auto [current_time, state, node] = pq.top();
        pq.pop();

        if(current_time > d[state][node]) continue;

        for(auto &[n_node, w] : g[node]) {
            if(state == 0) {
                ll new_time = current_time + w;
                if(new_time < d[0][n_node]) {
                    d[0][n_node] = new_time;
                    pq.emplace(new_time, 0, n_node);
                }

                // horse available
                if(hs[node]) {
                    ll halved_time = current_time + (ll)(w / 2);
                    if(halved_time < d[1][n_node]) {
                        d[1][n_node] = halved_time;
                        pq.emplace(halved_time, 1, n_node);
                    }
                }
            }
            else {
                ll new_time = current_time + (ll)(w / 2);
                if(new_time < d[1][n_node]) {
                    d[1][n_node] = new_time;
                    pq.emplace(new_time, 1, n_node);
                }
            }
        }
    }

    vector<ll> mind(n + 1, LLONG_MAX);
    for(int n_node = 1; n_node <= n; ++n_node){
        mind[n_node] = min(d[0][n_node], d[1][n_node]);
    }

    return mind;
}

void solve()
{
    ll n, m, h;
    cin >> n >> m >> h;

    vector<int> mountPoints(h);
    for(auto &x : mountPoints) cin >> x;

    vector<bool> hs(n + 1, false);
    for(auto &mp : mountPoints) hs[mp] = true;

    vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>());
    for(ll i = 0; i < m; ++i){
        ll a, b, w;
        cin >> a >> b >> w;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    if(n ==1){
        cout << 0 <<nline;
        return;
    }

    vector<ll> marian_t = shortest_path(n, g, hs, 1);
    vector<ll> robin_t = shortest_path(n, g, hs, n);

    print(marian_t);
    print(robin_t);

    ll least_t = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        if(marian_t[i] == LLONG_MAX || robin_t[i] == LLONG_MAX) continue;
        ll meetingTime = max(marian_t[i], robin_t[i]);
        least_t = min(least_t, meetingTime);
    }

    cout << (least_t == LLONG_MAX ? -1 : least_t) << nline;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input_output/input.txt", "r", stdin);
    freopen("input_output/error.txt", "w", stderr);
    freopen("input_output/output.txt", "w", stdout);
#endif
    fastio;

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}