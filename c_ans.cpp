#include <bits/stdc++.h>


#define ll long long
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
    int n, k;
    cin>>n>>k;
    vector<ll> a(n), b(n);
    for(int i = 0; i<n; ++i) cin>>a[i];
    for(int i = 0; i<n; ++i) cin>>b[i];
    sort(b.begin(), b.end());
    vector<pair<ll, int>> pairs(n);
    for(int i = 0; i<n; ++i){
        pairs[i] = {a[i], i};
    }

    sort(pairs.begin(), pairs.end());
    vector<ll> res(n);

    for(int i = 0; i<n; ++i){
        res[pairs[i].second] = b[i];
    }

    for(auto &i: res){
        cout<<i<<" ";
    }
    cout<<endl;

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