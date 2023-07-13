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
#define lli long long int
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

vector<ll> segTree;
vector<ll> a;
vector<ll> lz;
void build(int seg_idx, int seg_l, int seg_r){
    if(seg_l == seg_r){
        segTree[seg_idx] = a[seg_l];
        return;
    }
    int mid = (seg_l + seg_r) >> 1;
    build(2*seg_idx + 1, seg_l, mid);
    build(2*seg_idx + 2, mid + 1, seg_r);
    segTree[seg_idx] = segTree[2*seg_idx + 1] + segTree[2*seg_idx + 2];
}

void update(vector<ll> &a, int seg_idx, int seg_l, int seg_r, int a_idx){
    if(seg_l == seg_r){
        segTree[seg_idx] = a[a_idx];
        return;
    }

    int mid = (seg_l + seg_r)>>1;
    if(a_idx <= mid)
        update(a, 2*seg_idx + 1, seg_l, mid, a_idx);
    else update(a, 2*seg_idx + 2, mid + 1, seg_r, a_idx);


    segTree[seg_idx] = (segTree[2*seg_idx + 1] ^ segTree[2*seg_idx + 2]);
}

ll ansQuery(int seg_idx, int seg_l, int seg_r, int ql, int qr){
    if(seg_l >= ql && seg_r <= qr){
        return segTree[seg_idx];
    }

    // Not overlapping
    if(seg_r < ql || seg_l > qr){
        return 0;
    }

    // if partial overlapping
    int mid = (seg_l + seg_r) >> 1;
    ll left = ansQuery(2*seg_idx + 1, seg_l, mid, ql, qr);
    ll right = ansQuery(2*seg_idx + 2, mid + 1, seg_r, ql, qr);

    return (left ^ right);
}

void rangeUpdate(int seg_idx, int seg_l, int seg_r, int a_l, int a_r, int val){
    // check for pending updates
    if(lz[seg_idx] != 0){
        segTree[seg_idx] += (seg_r - seg_l + 1) * lz[seg_idx];
        if(seg_l != seg_r){
            lz[2*seg_idx + 1] += lz[seg_idx];
            lz[2*seg_idx + 2] += lz[seg_idx];
        }
        lz[seg_idx] = 0;
    }

    // No overlapping case
    if(seg_l > a_r || seg_r < a_l || seg_l > seg_r) return;

    // Check if current range completely lies, postpone the lz update for children
    if(seg_l >= a_l && seg_r <= a_r){
        segTree[seg_idx] += (seg_r - seg_l + 1) * val;
        if(seg_l != seg_r){
            lz[2*seg_idx + 1] += val;
            lz[2*seg_idx + 2] += val;
        }
        return;
    }
    int mid = (seg_l + seg_r) >> 1;
    rangeUpdate(2*seg_idx + 1, seg_l, mid, a_l, a_r, val);
    rangeUpdate(2*seg_idx + 2, mid + 1, seg_r, a_l, a_r, val);
    segTree[seg_idx] = segTree[2*seg_idx + 1] + segTree[2*seg_idx + 2];
}


ll ansRangeQueries(int seg_idx, int seg_l, int seg_r, int a_l, int a_r){
    if(lz[seg_idx] != 0){
        segTree[seg_idx] += (seg_r - seg_l + 1) * lz[seg_idx];
        if(seg_l != seg_r){
            lz[2*seg_idx + 1] += lz[seg_idx];
            lz[2*seg_idx + 2] += lz[seg_idx];
        }
        lz[seg_idx] = 0;
    }

    if(seg_l > a_r || seg_r < a_l || seg_l > seg_r){
        return 0;
    }

    if(seg_l >= a_l && seg_r <= a_r){
        return segTree[seg_idx];
    }

    int mid = (seg_l + seg_r) >> 1;
    ll left = ansRangeQueries(2*seg_idx + 1, seg_l, mid, a_l, a_r);
    ll right = ansRangeQueries(2*seg_idx + 2, mid + 1, seg_r, a_l, a_r);

    return left + right;
}


void solve(){
    int n, q;
    cin>>n>>q;
    segTree.resize(4*n + 1, 0);
    lz.resize(4*n + 1, 0);
    a.resize(n, 0);

    for(int i = 0; i<n; ++i){
        cin>>a[i];
    }

    build(0, 0, n - 1);

    for(int i = 0; i<q; ++i){
        int type;
        cin>>type;
        if(type == 1){
            int l, r, v;
            cin>>l>>r>>v;
            --l, --r;
            rangeUpdate(0, 0, n - 1, l, r, v);
        }else{
            int pos;
            cin>>pos;
            --pos;
            ll value = ansRangeQueries(0, 0, n - 1, pos, pos);
            cout<<value<<nline;
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
    // cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}