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

        As per Euclid algorithm
        - (mod>=2)*(mod-2) to ensure we are not sending any -ve number

    */
    return expo(b, (mod >=2)*(mod - 2), mod);
}

ll mod_prod(ll a, ll b, ll mod = MAXX){
    /*

        a*b % mod = (a%mod * b%mod) * mod

    */
   return ((a%mod) * (b%mod))%mod;
}

ll mod_div(ll a, ll b, ll mod = MAXX){
    /*
        (a/b)%mod = (a%mod * b_inverse%mod)%mod

        where b_inverse = b^mod-2
    */
    return mod_prod(a, mod_inverse(b, mod), mod);
}


void solve(){
    int h, w, q;
    cin>>h>>w>>q;
    
    vector<vector<int>> v(h, vector<int>(w, 1));
    int ans = h*w;
    for(int i = 0; i<q; ++i){
        int r, c;
        cin>>r>>c;
        --r, --c;
        if(v[r][c] == 1){
            v[r][c] = 0;
            --ans;
            continue;
        }
        for(int row = r; row>=0; --row){
            if(v[row][c]){
                v[row][c] = 0;
                --ans;
                break;
            }
        }

        for(int row = r; row<h; ++row){
            if(v[row][c]){
                v[row][c] = 0;
                --ans;
                break;
            }
        }

        for(int col = c; col>=0; --col){
            if(v[r][col]){
                v[r][col] = 0;
                --ans;
                break;
            }
        }

        for(int col = c; col<w; ++col){
            if(v[r][col]){
                v[r][col] = 0;
                --ans;
                break;
            }
        }

        // print(v);
        
    }
  
    cout<<ans<<nline;

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
    // cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}