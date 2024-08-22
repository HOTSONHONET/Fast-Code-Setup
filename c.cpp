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

void solve()
{      
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &i: v) cin>>i;
    ll ans = 0;
    vector<int> pows(n, 1);
    for(ll i = 1; i<n; ++i){
        if(v[i-1] > 1 && v[i] == 1){
            cout<<-1<<nline;
            return;
        }
        
        // b^(2^x) >= a^m
        // (2^x)*log(b) >= m*log(a)
        ll k = 0;
        ll a =v[i-1], b = v[i];
        while(a != 1 && a*a <= b) --k, a*a = 
        for(;pows[i]*(double)log2(v[i]) < (double)log2(v[i-1])*pows[i-1]; pows[i] = pow(2, ++k));

        ans += k;
    }
    print(v);
    print(pows);
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
    cin >> tcs;

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