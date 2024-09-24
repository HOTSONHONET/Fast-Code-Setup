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

        As per Fermet's little theorem
        - (mod>=2)*(mod-2) to ensure we are not sending any -ve number

    */
    return expo(b, (mod >=2)*(mod - 2), mod);
}

ll mod_prod(ll a, ll b, ll mod = MAXX){
    /*

        a*b % mod = (a%mod * b%mod) * mod

    */
    return ((a % mod) * (b % mod)) % mod;
}

ll mod_div(ll a, ll b, ll mod = MAXX){
    /*
        (a/b)%mod = (a%mod * b_inverse%mod)%mod

        where b_inverse = b^mod-2
    */
    return a * mod_inverse(b, mod);
}

void solve(){
    ll n, m, k;
    cin>>n>>m>>k;

    vector<llpair> ds(n);
    for(int i=0; i<n; ++i){
        ll d, a;
        cin>>ds[i].first>>ds[i].second;
    }

    ds.push_back({1e18, 0});

    ll ans = 0;
    stack<llpair> st;
    for(int i = 0; i<n; ++i){
        auto &[cur_day, cur_milk] = ds[i];

        cur_milk = min(cur_milk, m*k);

        ll days = cur_milk / m;

        ll good = min(ds[i+1].first - cur_day, days);

        ans += good;
        cur_day += good;
        cur_milk -= good*m;

        // Checking if we have some milk left
        // and if it not expired until the next milk acquisition day
        // we can keep it for the consumption calculation
        if(cur_day == ds[i+1].first && cur_milk > 0){
            st.push({cur_day - good, cur_milk});
        }

        // Looping until we have not reached the next milk acquisition day
        // and the cur_milk that we have not expired
        while(cur_day < ds[i + 1].first && !st.empty() && cur_day < st.top().first + k){
            auto &[prev_day, prev_milk] = st.top();
            st.pop();

            cur_milk += prev_milk;

            days = cur_milk / m;

            // Checking what is the minimum runway we have
            // days between the next milk acquisition day
            // current milk runway
            // days for the prev milk to expire
            good = min({ds[i+1].first - cur_day, days, prev_day + k - cur_day});

            ans += good;
            cur_day += good;
            cur_milk -= good*m;

            if(cur_day == ds[i+1].first && cur_milk > 0){
                st.push({prev_day, cur_milk});
            }
        }
    }

    cout<<ans<<nline;

};


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