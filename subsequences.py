from itertools import permutations 
 
for n in range(1, 11):
    perm = permutations([d+1 for d in range(n)]) 
    
     
    finder = set()
    for p in list(perm): 
        s = 0
        for j in range(1, n + 1): s += abs(p[j - 1] -j)
        finder.add(s)
    
    print(sorted(list(finder)), n, len(finder))
    