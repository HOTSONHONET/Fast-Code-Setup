def solve():
    """
    a = [1 2 3 4]
    n = 4

    0 0 0 0 = 0
    0 0 0 1 = 1
    1 0 0 1 = 9
    1 1 0 0 = 12
    
    {}
    1 
    2
    3
    1 2
    1 3
    2 3
    
    10 = 1 0 1 0
    x =  1 0 0 0
    10 & x = 1 0 0 0

    """ 
    a = [1, 2, 3, 4]
    for i in range(2**n):
        for j in range(32):
            if i & (1<<j):
                print(a[i], )




    n, k = list(map(int, input().split()))

    a = list(map(int, input().split()))
    b = sorted(list(map(int, input().split())))
    a_pairs = sorted([[a[i], i] for i in range(n)])

    ans = [-1]*n

    n = 100

    for i, pair in enumerate(a_pairs):
        ans[pair[1]] = b[i]
    
    for i in ans:
        print(i, end=" ")
    print()
    

if __name__ == "__main__":
    tc = int(input())
    for i in range(tc):
        solve()
