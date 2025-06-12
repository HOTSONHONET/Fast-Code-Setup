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
#define ull unsigned ll
#define MAXX 1000000007
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

template<typename t> 
t gcd(t a, t b){
    return a == 0 ? b : gcd(b%a, a);
}



void solve(){       
    int n;
    cin>>n; 
    vector<int> a(n);
    for(auto &ele: a) cin>>ele;

    bool all_zero_check = count(a.begin(), a.end(), 0) == n;
    print(all_zero_check);
    if(all_zero_check){
        cout<<3<<nline;
        cout<<1<<" "<<2<<nline;
        cout<<3<<" "<<n-1<<nline;
        cout<<1<<" "<<2<<nline;
    }else{
        // finding the first non-zero number
        int idx = -1;
        for(int i = 0; i < n; ++i) if(a[i] > 0){
            idx = i;
            break;
        }
        ++idx; // 1-based indexing
        if(idx == 1){
            cout<<2<<nline;
            cout<<2<<" "<<n<<nline;
            cout<<1<<" "<<2<<nline;
        }else if(idx == n){
            cout<<2<<nline;
            cout<<1<<" "<<n-1<<nline;
            cout<<1<<" "<<2<<nline;
        }else{
            // print(1);
            int left_z = count(a.begin(), a.begin() + idx, 0);
            int right_z = count(a.begin() + idx, a.end(), 0);
            if(left_z == 0){
                cout<<2<<nline;
                cout<<idx<<" "<<n<<nline;
                cout<<1<<" "<<idx<<nline;
            }else if(right_z == 0){
                cout<<2<<nline;
                cout<<1<<" "<<idx<<nline;
                cout<<1<<" "<<(n-idx+1)<<nline;
            }else{
                cout<<3<<nline;
                if(idx == 2){
                    cout<<1<<" "<<idx<<nline;
                    cout<<3<<" "<<n<<nline;
                    cout<<1<<" "<<2<<nline;
                }else{
                    cout<<idx<<" "<<n<<nline;
                    cout<<1<<" "<<idx-1<<nline;
                    cout<<1<<" "<<2<<nline;
                }
            }
        }
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
