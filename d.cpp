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
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i: v) cin>>i;

    set<int> finder(v.begin(), v.end());

    int max_len = finder.size();
    vector<int> uq_elements(finder.begin(), finder.end());
    print(uq_elements);
    map<int, set<int>> lmapper;
    for(int i = 0; i<n; ++i){
        lmapper[v[i]].insert(i);
    }

    // for(int i: finder){
    //     print(i);
    //     for(auto idx: lmapper[i]){
    //         print(idx);
    //     }
    // }
    
    // Generating all permutations
    vector<int> ans;
    do{ 
        bool push = 1;
        for(int i = 1, prev_idx = *lmapper[uq_elements[0]].begin(); i<max_len; ++i){
            int ele = uq_elements[i];
            auto lb = lmapper[ele].lower_bound(prev_idx);
            if(lb == lmapper[ele].end()) --lb;
            if(prev_idx > *lb){
                push = 0;
                break;
            }

            prev_idx = *lb;
            print(uq_elements[i], prev_idx);
        }
        
        if(push){
            if(ans.size() == 0){
                ans = uq_elements;
            }else{
                bool good = false;
                vector<int> a = ans;
                vector<int> b = uq_elements;

                for(int i = 0; i<max_len; i += 2) a[i] *= -1, b[i] *= -1;


                if(a > b) ans = uq_elements;
            }
        }
    }while(next_permutation(uq_elements.begin(), uq_elements.end()));

    cout<<max_len<<nline;
    for(auto ele: ans){
        cout<<ele<<" ";
    }

    cout<<nline;
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