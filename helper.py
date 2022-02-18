"""
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
   /___\   \______/

"""

from collections import Counter, defaultdict
from math import *
from bisect import *
from itertools import permutations, combinations, product
import sys
import os


def givePerms(s, r=None):
    if(r == None):
        return list(permutations(s))
    return list(permutations(s, r))


def giveCombination(s, r=None):
    if(r == None):
        return list(combinations(s))
    return list(combinations(s, r))


def self_cartesian(v, r):
    """
    e.g#1 : v = [1, 2], r = 1
    op#1 : [(1, 2)]

    e.g#2 : v = [1, 2], r = 2
    o/p#2 : [(1, 1), (1,2), (2, 1)]
    """
    return list(product(v, repeat=r))


def cartesian_product(*args):
    """
    args = v1, v2
    e.g : v1 = [1, 2], v2 = [2, 3]
    o/p : [(1, 2), (1, 3), (2, 3)]
    """
    return list(product(*args))


def factorial(n, mod=1):
    if(n < 1):
        return 1
    ans = 1
    for i in range(2, n+1):
        ans = (ans*i) % mod
    return ans


MOD = 1e9


def SieveOfEratosthenes(n):
    ans = []
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):

        if (prime[p] == True):

            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1

    for p in range(2, n+1):
        if prime[p] and p != 0:
            ans.append(p)
    return ans


def lessThanPowerOf2(n):
    p = int(math.log(n, 2))
    return int(pow(2, p))


def calXorSum(a):
    s = 0
    for i in a:
        s ^= i
    return s


def solve():
    

if __name__ == "__main__":
    tcs = int(input())
    for tc in range(tcs):
        solve()
