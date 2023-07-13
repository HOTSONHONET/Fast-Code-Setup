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

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cost = 1, count = 1;
    char c = s[0];
    for(int i = 1; i<n; ++i){
        if(s[i] == c) count++;
        else{
            c = s[i];
            cost = max(cost, count);
            count = 1;
        }
    }
    cost = max(cost, count);
    cost++;
    cout<<cost<<nline;
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

