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

struct Line{
    ll m, b;
    
    ll value(ll x){
        return m*x + b;
    }

    pair<ll, ll> intersect(const Line& l2) const {
        // mx + b = m2*x + b2;
        // x = (b2 - b)/(m - m2)
        ll int_diff = l2.b - b;
        ll m_diff = m - l2.m;

        if(m_diff < 0) int_diff *= 1, m_diff *= 1;
        return {int_diff, m_diff};
    }
};

void solve(){
    int n;
    ll C;
    cin>>n>>C;
    vector<ll> h(n);
    for(auto &ele: h) cin>>ele;

    vector<Line> lines;
    // dp[i] = min(dp[i], dp[j] + (hi - hj)^2 + C) for all j = 1...i
    // dp[i] = min(dp[i], dp[j] + hi^2 + hj^2 -2hihj + C)
    // dp[i] = Min -2hj*hi + hi^2 + (dp[j] + C + hj^2)

    ll best = 0;
    for(int i = 0, start = 0; i < n; ++i){
        while(start <= (int)lines.size() - 2){
            Line A = lines[start], B = lines[start + 1];
            if(A.value(h[i]) >= B.value(h[i])) ++start;
            else break;
        }

        best = 0; // dp[i]
        if(i > 0) best = lines[start].value(h[i]) + h[i]*h[i] + C;
        
        Line line{-2*h[i], best + h[i]*h[i]};

        while(start <= (int)lines.size() - 2){
            Line A = lines.end()[-2];
            Line B = lines.end()[-1];
            llpair one = A.intersect(B);
            llpair two = B.intersect(line);
            
            // comparing the value of the intersecting point
            // one.first/one.second >= two.first/two.second
            if((__int128)one.first * two.second >= (__int128)two.first*one.second) lines.pop_back();
            else break;
        }

        lines.push_back(line);
    }

    cout<<best<<nline;

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
    // cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}