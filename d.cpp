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
 
int N = 3e5 + 1;

void solve()
{      
    ll n, s, m;
    cin>>n>>s>>m;

    vector<pair<ll, ll>> v(n);
    for(auto &p: v) cin>>p.first>>p.second;
    v.push_back({0,0});
    v.push_back({m, m});
    sort(v.begin(), v.end());
    print(v);
    for(int i = 1; i<v.size(); ++i){
        print((v[i].first - v[i - 1].second));
        if((v[i].first - v[i - 1].second) >= s){
            cout<<"YES"<<nline;
            return;
        }
    }
    cout<<"NO"<<nline;

}   
 
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input_output/input.txt", "r", stdin);
    freopen("input_output/error.txt", "w", stderr);
    freopen("input_output/output.txt", "w", stdout);
    setbuf(stdout, NULL);  // Disable buffering for output.txt
    setbuf(stderr, NULL);  // Disable buffering for error.txt
#endif
    fastio;
    int tcs = 1;
    cin >> tcs;
 
    for (int tc = 1; tc <= tcs; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
 
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    cerr.flush(); // Ensure data is written to error.txt immediately
#endif
    return 0;
}