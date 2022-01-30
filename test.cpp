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

using namespace std;

#define ipair pair<int, int>
#define llpair pair<long long, long long>
#define llipair pair<long long int, long long int>
#define ll long long
#define lli long long int
#define ull unsigned long long
#define MAX 1000000007
#define ull unsigned long long
#define INF 0x3f3f3f3f

#ifndef ONLINE_JUDGE
#include "helper_functions.h"
#endif

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n, 1)), b(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];

            if (b[i][j] == 0)
            {
                for (int k = 0; k < max(m, n); k++)
                    a[k % m][j] = a[i][k % n] = 0;
            }
        }
    }

    // Checking
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int or_res = 0;
            for (int k = 0; k < max(m, n); k++)
            {
                or_res |= (a[k % m][j] | a[i][k % n]);
            }
            if (or_res != b[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (vector<int> &i : a)
    {
        for (int &j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
    // int tcs = 0;
    // cin >> tcs;
    // for (int tc = 1; tc <= tcs; tc++)
    // {
    //     solve();
    // }

    solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
