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

    int n, Q;
    cin >> n >> Q;
    vector<vector<int>> g(n + 1);
    vector<int> load(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int sum = 0;
    for (int i = 0; i < Q; ++i)
    {
        int tmp;
        cin >> tmp;
        sum++;
    }

    if (sum == n)
    {
        cout << n << nline;
        return;
    }

    queue<int> q;
    q.push(1);
    load[1] = 1;
    vector<int> levels;
    while (q.empty() == false)
    {
        int sz = q.size();
        levels.push_back(sz);
        for (int i = 0; i < sz; ++i)
        {
            int top = q.front();
            q.pop();
            load[top] = 1;
            for (int i : g[top])
            {
                if (!load[i])
                    q.push(i);
            }
        }
    }

    int ans = 0;
    int height = levels.size();
    print(levels);
    for (int i = 0; i < height; ++i)
    {
        int numContainers = levels[i];
        if (numContainers > sum)
        {
            break;
        }
        else
            ans += numContainers, sum -= numContainers;
    }

    cout << ans << nline;
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
        cout << "Case #" << tc << ": ";
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
