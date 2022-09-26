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

#include <iostream>

using namespace std;

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

#ifndef ONLINE_JUDGE
#include "../helper_functions.h"
#else
#define print(...) 42
#endif

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input_output/input.txt", "r", stdin);
    freopen("../input_output/error.txt", "w", stderr);
    freopen("../input_output/output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
    int tcs = 0;
    cin >> tcs;
    while (tcs--)
    {
        vector<vector<int>> v(1e2 + 1, vector<int>(2, 0));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            v[tmp][0]++;
            v[tmp][1] = i + 1;
        }

        for (auto &i : v)
        {
            if (i[0] == 1)
            {
                cout << i[1] << nline;
            }
        }
    }
}