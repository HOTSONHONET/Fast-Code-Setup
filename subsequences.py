from collections import deque


for _ in range(int(input())):
    s = [input(), input()]
    t, q = map(int, input().split())

    block = deque()
    mis_match = set()

    for i in range(len(s[0])):
        if s[0][i] != s[1][i]:
            mis_match.add(i)

    for i in range(q):
        while block and block[0][1] == i:
            mis_match.add(block[0][0])
            block.popleft()

        qry = list(map(int, input().split()))
        type = qry[0]
        if type == 1:
            x = qry[1] - 1
            if x in mis_match:
                block.append((x, i + t))
                mis_match.remove(x)
        elif type == 2:
            x, px, y, py = qry[1], qry[2], qry[3], qry[4]
            px -= 1
            py -= 1
            x -= 1
            y -= 1
            if s[0][px] != s[1][px]:
                mis_match.remove(px)
            if s[0][py] != s[1][py]:
                mis_match.remove(py)

            c1 = s[x][px]
            c2 = s[y][py]
            s[x] = s[x][:px] + c2 + s[x][px + 1 :]
            s[y] = s[y][:py] + c1 + s[y][py + 1 :]

            if s[0][px] != s[1][px]:
                mis_match.add(px)
            if s[0][py] != s[1][py]:
                mis_match.add(py)
        else:
            print("YES" if not mis_match else "NO")