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


ll expo(ll a, ll b, ll mod = MAXX){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }

    return res%mod;
}

ll mod_inverse(ll b, ll mod = MAXX){
    /*

        As per Fermet's little theorem
        - (mod>=2)*(mod-2) to ensure we are not sending any -ve number

    */
    return expo(b, (mod >=2)*(mod - 2), mod);
}

ll mod_prod(ll a, ll b, ll mod = MAXX){
    /*

        a*b % mod = (a%mod * b%mod) * mod

    */
    return ((a % mod) * (b % mod)) % mod;
}

ll mod_div(ll a, ll b, ll mod = MAXX){
    /*
        (a/b)%mod = (a%mod * b_inverse%mod)%mod

        where b_inverse = b^mod-2
    */
    return a * mod_inverse(b, mod);
}

void solve(){
    int N, q;
    cin>>N>>q;
    vector<ull> a(N);
    for(auto &i: a) cin>>i;

    vector<ull> pre(N + 1);
    for(int i = 1; i<=N; ++i) pre[i] = pre[i - 1] + a[i - 1];
    for(int i = 0; i<N; ++i) pre.push_back(pre[N + i] + a[i]);
    
    
    //a =  1 2 3
    //b = [1 2 3] [2 3 1] [3 1 2]
    //     0 1 2   3 4 5   6 7 8
    // l = 4, r = 7
    // cycle_l = 4/3 = 1
    // cycle_r = 7/3 = 2
    // l_pos = 4%3 = 1
    // r_pos = 7%3 = 1  

    print(pre);
    ull n = N;
    for(int i = 0; i<q; ++i){
        ull l,r;
        cin>>l>>r;
        --l, --r;

        // lets determine the position of l and r in b
        ull cycle_l = l/n; 
        ull cycle_r = r/n;
        print(cycle_l, cycle_r);

        // Now finding the position of l and r
        // int their corresponding cycles
        ull l_pos = l % n;
        ull r_pos = r % n;
        print(l_pos, r_pos);

        ull ans = 0;
        // For # As are present between l and r
        // we can directly get the sum of the elements

        // lets say we are covering all the elements belong to cycle_l to cycle_r
        // then we can decide what all elements we remove
        ans += (cycle_r - cycle_l + 1)*pre[n];
        print(ans);
        // Finding the position of first element and last element (wrt a) in cycle_l
        // A[cycle_no]....A[x]....A[n-1] A[0].....A[cycle_no - 1]
        // A[cycle_no]....A[n-1] A[0].....A[x]....A[cycle_no - 1]
        // where x belongs to [l_pos, r_pos]

        ans += pre[cycle_l] - pre[cycle_l + l_pos];
        print(ans, cycle_l + l_pos, l_pos, pre.size());
        ans += pre[cycle_r + r_pos + 1] - pre[n + cycle_r];
        print(ans, n + cycle_r, cycle_r + r_pos + 1, pre.size());
        print("----------------");
        cout<<ans<<nline;
    }


}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input_output/input.txt", "r", stdin);
    freopen("./input_output/error.txt", "w", stderr);
    freopen("./input_output/output.txt", "w", stdout);
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