output = open("./input_output/output.txt", 'r').readlines()

for line in output:
    ele = list(map(int, line.split()))
    if -1 in ele: continue

    mapper = {}
    for idx, item in enumerate(ele): 
        if item not in mapper: mapper[item] = [idx]
        else: mapper[item].append(idx)
    
    for key, val in mapper.items():
        print(key, val)