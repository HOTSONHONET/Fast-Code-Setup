#include <bits/stdc++.h>
using namespace std;

#define MAXX 1000000007

void buildSieve()
{
    for (auto &i : primes)
        i = true;

    primes[0] = false;
    primes[1] = false;

    for (int p = 2; p * p <= 1000000;
         p++)
    {

        if (primes[p] == true)
        {
            for (int i = p * p; i <= 1000000;
                 i += p)
                primes[i] = false;
        }
    }
}

bool isPrime(string number)
{
    int num = stoi(number);
    return primes[num];
}

int rec(string &number, int i,
        vector<int> &dp)
{
    if (dp[i] != -1)
        return dp[i];

    int cnt = 0;

    for (int j = 1; j <= 6; j++)
    {
        if (i - j >= 0 && number[i - j] != '0' && isPrime(number.substr(i - j, j)))
        {

            cnt += rec(
                number, i - j, dp);
            cnt %= MOD;
        }
    }
    return dp[i] = cnt;
}

int solve(string &number)
{
    int n = number.length();
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    return rec(number, n, dp);
}

bool primes[1000000];
int main()
{
    buildSieve();
    string s;
    cin >> s;

    cout << solve(s) << "\n";

    return 0;
}
