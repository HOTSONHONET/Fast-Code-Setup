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

int wateringPlants(vector<int> &plants, int capacity)
{
    int total_dis = 0, j = -1, n = plants.size();
    int maxCapacity = capacity;
    while (j + 1 < n)
    {
        if (capacity < plants[j + 1])
        {
            total_dis += 2 * (j + 1);
            capacity = maxCapacity - plants[j + 1];
        }
        else
        {
            capacity -= plants[j + 1];
        }

        j++;
    }

    return total_dis += n;
}

void solve()
{
    string str, word;
    getline(cin, str);
    stringstream ss(str);
    int minn = 999, allOK = true;
    while (ss >> word)
    {
        try
        {
            int num = convert(word);
            if (num > 100 || num < 0)
                continue;
            if (minn == 999)
                minn = num;
            else if (num <= minn)
            {
                allOK = 0;
                break;
            }
            else
                minn = min(minn, num);
        }
        catch (...)
        {
            continue;
        }
    }
    cout << allOK;
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
