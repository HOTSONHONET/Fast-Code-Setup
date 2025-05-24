import itertools

def calculate_mex(grid):
    """Calculates the MEX of a grid (subgrid)."""
    seen = set()
    for row in grid:
        for num in row:
            seen.add(num)
    mex = 0
    while mex in seen:
        mex += 1
    return mex

def generate_subgrids(grid):
    """Generates all possible subgrids from a given grid."""
    rows = len(grid)
    cols = len(grid[0])
    subgrids = []
    for r_start in range(rows):
        for c_start in range(cols):
            for r_end in range(r_start, rows):
                for c_end in range(c_start, cols):
                    subgrid = [row[c_start:c_end+1] for row in grid[r_start:r_end+1]]
                    subgrids.append(subgrid)
    return subgrids

def grid_permutations_with_mex(grid):
    """Generates all permutations of a grid and calculates MEX for each subgrid."""
    elements = [num for row in grid for num in row]
    permutations_list = list(itertools.permutations(elements))

    grid_size = len(grid)
    results = []

    for permutation in permutations_list:
        
        permuted_grid = [list(permutation[i*grid_size:(i+1)*grid_size]) for i in range(grid_size)]
        
        subgrids = generate_subgrids(permuted_grid)
        
        mex_values = [calculate_mex(subgrid) for subgrid in subgrids]
        
        results.append({
            "permutation": permuted_grid,
            "mex_values": mex_values
        })

    return results

#Example usage:
grid = []
n = 4
j = 0
for i in range(n):
    row = [j+d for d in range(n)]
    j += n
    grid.append(row)

from pprint import pprint
pprint(grid)

results = grid_permutations_with_mex(grid)

highest = 0
for result in results: highest = max(result["mex_values"], highest)
print(highest)
for result in results:
    if result["mex_values"] == highest:
        print("Permutation:", result["permutation"])
        print("-" * 20)