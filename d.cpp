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


void solve()
{      

    int n, q;
    cin>>n>>q;
    vector<ull> points(n + 1);

    // Things require for XOR hashing
    random_device rd; 
    mt19937_64 gen(rd());
    map<ull, ull> mapping;
    set<ull> finder = {0};

    for(int i = 1; i<=n; ++i){
        cin>>points[i];
        // Learn about XOR Hashing
        ull random;
        if(!mapping.count(points[i])){
            do{
                random = gen();
            }while(finder.count(random));

            finder.insert(random);
            mapping[points[i]] = random;
        }else{
            random = mapping[points[i]];
        }

        points[i] = random ^ points[i - 1];
    }

    print(points);    
    for(int i = 0; i<q; ++i){
        int l, r;
        cin>>l>>r;
        // so we have to determine whether the range
        // can lead to a tie or the second player win
        

        // The only condition the Sherif cannot lose is making a tie
        // which means the sum of the points in that range is even
        // ==> But 11 8 1 1 will fail
        // ==> Both Robin and Sherif should score the same
        // ==> All elements in that range should appear even no. of times
        
        if(((points[r] ^ points[l - 1])) == 0){
            cout<<"YES"<<nline;
        }else{
            cout<<"NO"<<nline;
        }
    }
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