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
#else
#define print(...) 42
#endif

void solve()
{
    int n, m;
    string s;
    cin >> n >> s >> m;
    map<char, int> rightMost, leftMost;
    vector<char> chars;
    for (int i = 0; i < n; i++)
    {
        rightMost[s[i]] = i;
        if (leftMost.find(s[i]) == leftMost.end())
        {
            leftMost[s[i]] = i;
            chars.push_back(s[i])
        }
    }
    // If no of chars are not enough
    int k = chars.size();
    if (k < m)
    {
        cout << -1 << endl;
        return;
    }
    // check for correct order

    int minn = INT_MAX;
    for (int i = 0; i < k - m + 1; i++)
    {
        char c = chars[i];
        int startL = leftMost[c], startR = rightMost[c];
        int delsL = 0, delsR = 0;
        int cntL = 1, cntR = 1, j = i + 1;
        while (cntL < m)
        {
            int r_val = rightMost[chras[j]];
            int l_val = leftMost[chars[j]];
            if (r_val - startL < 0)
            {
                delsL += l_val - startL - 1;
                startL = l_val;
            }
            else if (r_val - startL < l_val - startL)
            {
                delsL += r_val - startL - 1;
                startL = r_val;
            }
            else
            {
                delsL += l_val - startL - 1;
                startL = l_val;
            }

            cntL++;
        }

        while (cntR < m)
        {
            int r_val = rightMost[chras[j]];
            int l_val = leftMost[chars[j]];
            if (l_val - startR < 0)
            {
                delsR += r_val - startR - 1;
                startR = r_val;
            }
            else if (l_val - startR < r_val - startR)
            {
                delsR += l_val - startR - 1;
                startR = l_val;
            }
            else
            {
                delsR += r_val - startR - 1;
                startR = r_val;
            }

            cntR++;
        }
        minn = min(minn, min(delsL, delsR));
    }
    cout << minn << "\n";
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
    int tcs = 0;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
