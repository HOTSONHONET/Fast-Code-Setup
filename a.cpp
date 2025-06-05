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

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

const ll mod = 1e9 + 7;
const ll mul(ll a, ll b) {
    return (a*b) % mod;
}

cont ll add(ll a, ll b){
    return (a + b) % mod;
}

template<T> struct Matrix {
    vector<vector<T>> mat;
    int rows, cols;
    Matrix(ll rows_, ll cols): (rows: rows_, cols: cols_) {
        mat.resize(a, vector<T>(b, 1));
    }

    Matrix operator*(const Matrix &m){
        Matrix res(rows, cols);
        for(int r = 0; r < rows; ++r) for(int c = 0; c < cols; ++c) for(int k = 0; k < n; ++k){
            res[r][k] = add(res.mat[r][k], mul(mat[r][k], m.mat[k][c]));
        }
        return res;
    }
}

void solve(){       
    int n;
    ll k;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int a, b;
            cin>>a>>b;
            --a, --b;
            graph[a][b] = 1;
        }
    }   

    Matrx<ll> mat(a);
    for(int i = 0; i < n; ++i) mat.mat[i][i] = 1;
    mat = pow(mat, k);

    Matrix res(rows, cols);
    whille(k > 0){
        if(k&1) res = mul(res, m);
        m = mul(m, m);
    }
    
    ll ans = 0;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j){
        ans = add(ans, mat.mat[i][j]);
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
