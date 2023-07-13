
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
#define nline "\n"

//////////////////////////// HELPER FUNCTIONS ////////////////////////////

// printing variables
void printer()
{
    cerr << nline;
}

template <typename Head, typename... Tail>
void printer(Head H, Tail... T)
{
    cerr << " " << H;
    printer(T...);
}

// printing vectors
template <typename T>
void printer(vector<T> v)
{
    cerr << " [";
    for (auto i : v)
        cerr << i << " ";
    cerr << "] \n";
}

// printing sets
template <typename T>
void printer(set<T> v)
{
    for (auto i : v)
        cerr << i << " ";
    cerr << "\n";
}

// printing multisets
template <typename T>
void printer(multiset<T> v)
{
    for (auto i : v)
        cerr << i << " ";
    cerr << "\n";
}

// printing unordered_sets
template <typename T>
void printer(unordered_set<T> v)
{
    for (auto i : v)
        cerr << i << " ";
    cerr << "\n";
}

// printing unordered_map (k and v are variables)
template <typename T>
void printer(unordered_map<T, T> v)
{
    for (auto i : v)
        cerr << i.first << " -> " << i.second << "\n";
}

// printing map (k and v are variables)
template <typename T>
void printer(map<T, T> v)
{
    for (auto i : v)
        cerr << i.first << " -> " << i.second << "\n";
}

// printing unordered_map (k and v are variables)
template <typename T>
void printer(unordered_map<T, vector<T>> v)
{
    for (auto i : v)
    {
        cerr << i.first << " -> [";
        for (auto &v : i.second)
            cerr << v << " ";
        cerr << "]\n";
    }
}

// printing map (k and v are variables)
template <typename T>
void printer(map<T, vector<T>> v)
{
    for (auto i : v)
    {
        cerr << i.first << " -> [";
        for (auto &v : i.second)
            cerr << v << " ";
        cerr << "]\n";
    }
}

// printing vector containing pairs
template <typename T>
void printer(vector<pair<T, T>> v)
{
    cerr << "[ ";
    for (auto i : v)
        cerr << "{" << i.first << "," << i.second << "},";
    cerr << "]"
         << "\n";
}

// printing matrix
template <typename T>
void printer(vector<vector<T>> mat)
{
    cerr << nline;
    for (auto &v : mat)
    {
        for (auto &i : v)
        {
            cerr << i << " ";
        }
        cerr << nline;
    }
}

template <typename T>
ll factorial(T n, ll mod = MAX)
{
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
    {
        ans = (ans * i) % mod;
    }

    return ans;
}

template <typename T>
vector<vector<T>> vector_perms(vector<T> s)
{
    vector<vector<T>> ans;
    do
    {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    return ans;
}

template <typename T>
void printer(priority_queue<T> pq)
{
    while (pq.empty() == false)
    {
        T top = pq.top();
        pq.pop();
        cerr << top << " ";
    }
    cerr << nline;
}

template <typename T>
void printer(priority_queue<T, vector<T>, greater<T>> pq)
{
    while (pq.empty() == false)
    {
        T top = pq.top();
        pq.pop();
        cerr << top << " ";
    }
    cerr << nline;
}

template <typename T>
vector<string> string_perms(string s)
{
    vector<string> ans;
    do
    {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    return ans;
}

ll npr(ll n, int r)
{
    return factorial(n) / factorial(n - r);
}

ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    return npr(n, r) / factorial(r);
}

vector<int> split(string s)
{
    vector<int> res;
    for (auto i : s)
        res.push_back(i - '0');
    return res;
}

template <typename T>
void printPath(vector<T> parent, T j)
{

    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    cerr << j;
}

template <typename T>
vector<T> shortestPath(vector<pair<T, T>> adj[], T V, T src, T num_nodes)
{
    vector<bool> visited(num_nodes, false);
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> pq;
    vector<T> parent(V);
    parent[0] = -1;

    vector<T> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        T u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        for (auto x : adj[u])
        {

            T v = x.first;
            T weight = x.second;

            if (dist[v] > dist[u] + weight)
            {

                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    cerr << "Print shortest distances stored in dist[]" << nline;
    dist[src] = 0;
    for (T i = 0; i < V; ++i)
    {
        cerr << src << " -> " << i << "->" << dist[i] << nline;
    }

    return dist;
}


long long int mod_exp(long long b, long long int p, long long int m) 
{
    long long int res = 1;
    while (p > 0) 
	{
        if (p & 1) res = (res * b)%m;
        b = (b * b)%m;
        p >>= 1;
    }
    return res;
}

ll expo(ll base, ll power, ll mod = MAXX)
{
    ll ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base % mod;

        base = base * base % mod;
        power >>= 1;
    }

    return ans;
}


vector<int> seivePrimes(int n)
{
    vector<int> Primes(n + 1, 1);
    Primes[0] = Primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (Primes[i])
            for (int p = i * i; p <= n; p += i)
                Primes[p] = 0;

    // vector<int> primesList;
    // for (int i = 2; i <= n; i++)
    //     if (Primes[i])
    //         primesList.push_back(i);
    // return primesList;

    return Primes;
}

vector<ll> giveAllSubsetSum(vector<int> arr)
{

    vector<ll> to_return;
    int n = arr.size();
    for (int i = 0; i < (1 << n); i++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sum += arr[j];

        to_return.push_back(sum);
    }

    return to_return;
}

/*

Segment Tree code

*/
class SegmenTree{
    public:
        vector<ll> segTree;
        vector<ll> a;
        vector<ll> lz;
        void SegmentTree(vector<ll> v){
            a = v;
            int n = a.size();
            segTree.resize(4*n + 1);
            lz.resize(4*n + 1);
        }
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


            segTree[seg_idx] = (segTree[2*seg_idx + 1] + segTree[2*seg_idx + 2]);
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

            return (left + right);
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
            // ll left = ansRangeQueries(2*seg_idx + 1, seg_l, mid, a_l, a_r);
            // ll right = ansRangeQueries(2*seg_idx + 2, mid + 1, seg_r, a_l, a_r);

            // return left + right;
            return ansRangeQueries(2*seg_idx + 1, seg_l, mid, a_l, a_r) + ansRangeQueries(2*seg_idx + 2, mid + 1, seg_r, a_l, a_r);
        }
};


#define print(...) cerr << #__VA_ARGS__ << " : ", printer(__VA_ARGS__)
//////////////////////////// END OF HELPER FUNCTIONS ////////////////////////////
