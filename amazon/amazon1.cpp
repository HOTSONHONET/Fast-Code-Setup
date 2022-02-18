#include <bits/stdc++.h>
using namespace std;

Node *ans;
double maxx = 0;
void dfs(Node *src, map<int, int> &nodes, map<int, int> &sum)
{

    nodes[src.val] = 1;
    sum[src.val] = src.val;
    for (auto &ele : src.subEmployeeNode)
    {
        dfs(ele, nodes, sum);
        nodes[src.val] += nodes[ele.val];
        sum[src.val] += sum[ele.val];
        double tmp_ans = (double)sum[src.val] / nodes[src.val];
        if (maxx < tmp_ans)
        {
            ans = src;
            maxx = tmp_ans;
        }
    }
}

Node *solve(Node *presidesnt)
{
    map<int, int> nodes, sum;
    dfs(president, nodes, sum);
    return ans.val;
}

int main()
{
    return 0;
}