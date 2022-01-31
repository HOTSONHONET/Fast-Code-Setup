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

string addBinary(string &a, string &b)
{
    int i = a.length() - 1;
    int j = b.length() - 1;
    string ans;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        if (i >= 0)
        {
            carry += a[i] - '0', i--;
        }
        if (j >= 0)
        {
            carry += b[j] - '0', j--;
        }

        ans += (carry % 2 + '0');
        carry = carry / 2;
    }
    return ans;
}

void solve()
{
    string x, y;
    cin >> x >> y;

    string minn = "";
    int k = 0;
    while (minn.size() <= x.size())
        minn += '1';

    for (int i = 0; i <= x.size(); i++)
    {
        string tmp = addBinary(x, y);
        if (tmp < minn)
        {
            k = i;
            minn = tmp;
        }
        y += '0';
    }

    cout << k << "\n";
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
