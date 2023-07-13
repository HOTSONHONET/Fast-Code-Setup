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
#define lli long long int
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
    ll row, col;
    cin>>row>>col;
    ll maxx = max(row, col);
    ll elements_covered = (maxx - 1) * (maxx - 1);
    ll elements_will_be_coverted = maxx * maxx;
    ll ans;
    if(maxx == row){
        if(maxx & 1){
            ans = elements_covered + col;
        }else{
            ans = elements_will_be_coverted - (col - 1);
        }
    }else{
        if(maxx & 1){
            ans = elements_will_be_coverted - (row - 1);
        }else{
            ans = elements_covered + row;
        }
    }

    cout<<ans<<nline;
}


int main()
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
        // cout << "Case #" << tc << ": ";
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}