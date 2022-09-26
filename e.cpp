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
#define MAXX 1000000009
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

int solve()
{
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
    // cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        ll inp1, inp2;
        for (ll i = 1; i <= 7; ++i)
        {
            for (ll j = i + 1; j <= 7; ++j)
            {
                cout << "? " << i << ' ' << j << nline;
                cin >> inp1;
                cout << "? " << j << ' ' << i << nline;
                cin >> inp2;
                if (inp1 == -1)
                {
                    cout << "! " << max(i, j) - 1 << nline;
                    return 0;
                }
                if (inp1 != inp2)
                {
                    cout << "! " << inp1 + inp2 << nline;
                    return 0;
                }
            }
        }
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}