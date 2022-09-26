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

unordered_map<char, int> mapper = {
    {' a ', 1},
    {' b ', 2},
    {' c ', 3},
    {' d ', 4},
    {' e ', 5},
    {' f ', 6},
    {' g ', 7},
    {' h ', 8},
    {' i ', 9},
    {' j ', 10},
    {' k ', 11},
    {' l ', 12},
    {' m ', 13},
    {' n ', 14},
    {' o ', 15},
    {' p ', 16},
    {' q ', 17},
    {' r ', 18},
    {' s ', 19},
    {' t ', 20},
    {' u ', 21},
    {' v ', 22},
    {' w ', 23},
    {' x ', 24},
    {' y ', 25},
    {' z ', 26}};

void solve()
{
    string s;
    cin >> s;
    int node = 0;
    map<char, vector<int>> finder;
    int n = s.size();
    for (int i = 1; i < n - 1; ++i)
        finder[s[i]].push_back(i + 1);
    if (s[0] < s[n - 1])
    {
        for (char i = s[0]; i <= s[n - 1]; ++i)
        {
            node += finder[i].size();
        }
        cout << s[n - 1] - s[0] << ' ' << node + 2 << nline;
        cout << 1 << ' ';
        for (char i = s[0]; i <= s[n - 1]; ++i)
        {
            for (int j : finder[i])
            {
                cout << j << ' ';
            }
        }
        cout << n << nline;
    }
    else
    {
        for (char i = s[0]; i >= s[n - 1]; --i)
        {
            node += finder[i].size();
        }
        cout << s[0] - s[n - 1] << ' ' << node + 2 << nline;
        cout << 1 << ' ';
        for (char i = s[0]; i >= s[n - 1]; --i)
        {
            for (int j : finder[i])
            {
                cout << j << ' ';
            }
        }
        cout << n << nline;
    }
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