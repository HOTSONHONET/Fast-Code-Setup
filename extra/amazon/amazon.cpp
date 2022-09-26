#include <bits/stdc++.h>
using namespace std;

long int getMaxUnit(int num, vector<int> boxes, int unitSize, vector<int> unitPerBox, long truckSize)
{
    vector<pair<int, int>> store;
    long int ans = 0;
    for (int i = 0; i < num; i++)
    {
        store.push_back({unitPerBox[i], boxes[i]});
    }

    sort(store.begin(), store.end(), greater<pair<int, int>>());
    for (int i = 0; i < num; i++)
    {
        if (store[i].second <= truckSize)
        {
            ans += (long int)(store[i].first * store[i].second);
            truckSize -= store[i].second;
        }
        else
        {
            ans += truckSize * store[i].first;
            break;
        }
    }
    return ans;
}

int main()
{
}