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
    ll n, k;
    cin>>n>>k;

    vector<ll> v(n);
    for(auto &i: v) cin>>i;

    int ans = 0;
    for(int l = 0, r = n - 1, kk = k; l<=r && kk > 0; ){
        if(v[l] + v[r] <= kk){
            ans += 2, kk -= (v[l++] + v[r++]);
        }else{
            // Checking the position of kraken
            // If odd no. of times kraken has moved
            // then it is at Left or first ship
            // else right or right ship
            if(2*min(v[l], v[r]) <= kk) ++ans, kk = 0;
            break;
        }
        print(l, r, ans);
    }

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