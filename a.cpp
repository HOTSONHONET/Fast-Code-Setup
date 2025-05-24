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
#define ull unsigned ll
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


void solve(){    
    int n;
    cin>>n;
    vector<int> d(n);
    for(auto &ele: d) cin>>ele;
    vector<ipair> ob(n);
    for(auto &ele: ob) cin>>ele.first>>ele.second;

    ipair range = {0, 0};
    vector<ipair> ranges;
    for(int i = 0; i < n; ++i){
        auto [l,r] = ob[i];
        auto [rl, rr] = range;
        if(d[i] == 1) rl++, rr++;
        else if(d[i] == -1) rr++;
        
        int L = max(l, rl), R = min(r, rr);
        if(L > R){
            cout<<-1<<nline;
            return;
        }
        range = {L, R};
        ranges.push_back(range);
    }

    print(ranges);

    int target_h = ranges.back().first;
    print(target_h);
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; --i){
        auto [l, r] = ranges[i];
        if(d[i] != -1) target_h -= d[i], ans[i] = d[i];
        else{
            if(i == 0){

            }else{
                if((target_h >= ranges[i - 1].first) && (target_h <= ranges[i - 1].second)) ans[i] = 0;
                else ans[i] = 1, target_h--;
            }
        }
        
    }
    for(auto &ele: ans) cout<<ele<<" ";
    cout<<nline;

    // // checking ans
    // int h = 0;
    // int all_ok = 1;
    // for(int i = 1; all_ok && i < n; ++i) {
    //     auto [l, r] = ob[i];
    //     if(ans[i] == 1) ++h;
    //     if(!(l <= h && h <= r)) all_ok = 0;
    // }

    // print(all_ok);
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
