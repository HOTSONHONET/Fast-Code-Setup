
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

ll expo(ll base, ll power)
{
    ll ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base % MAX;

        base = base * base % MAX;
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

// Segment Tree Code Begins
void buildSegTree(vector<ll> &v, vector<ll> &segTree, int idx, int low, int high)
{
    if (low == high)
    {
        segTree[idx] = v[low];
        return;
    }

    ll mid = (low + high) >> 1;
    buildSegTree(v, segTree, 2 * idx + 1, low, mid);
    buildSegTree(v, segTree, 2 * idx + 2, mid + 1, high);

    segTree[idx] = min(segTree[2 * idx + 1], segTree[2 * idx + 2]);
}

void update(vector<ll> &v, vector<ll> &segTree, int idx, int low, int high, int k)
{
    if (low == high)
    {
        segTree[idx] = v[k];
        return;
    }

    ll mid = (low + high) >> 1;

    if (k <= mid)
        update(v, segTree, 2 * idx + 1, low, mid, k);
    else
        update(v, segTree, 2 * idx + 2, mid + 1, high, k);

    segTree[idx] = min(segTree[2 * idx + 1], segTree[2 * idx + 2]);
}

ll ansQueries(vector<ll> &segTree, int idx, int low, int high, int ql, int qh)
{
    // If completely overlapping
    if (low >= ql and high <= qh)
        return segTree[idx];

    // If not overlapping at all
    if (low > qh or high < ql)
        return INT_MAX;

    // If there is a parital overlap
    ll mid = (low + high) >> 1;
    ll left = ansQueries(segTree, 2 * idx + 1, low, mid, ql, qh);
    ll right = ansQueries(segTree, 2 * idx + 2, mid + 1, high, ql, qh);

    return min(left, right);
}

// Segment Tree Code Ends

#define print(...) cerr << #__VA_ARGS__ << " : ", printer(__VA_ARGS__)
//////////////////////////// END OF HELPER FUNCTIONS ////////////////////////////
