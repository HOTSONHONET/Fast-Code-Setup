"""

2 2 2              2 2
|   |   |
L ->m + 1   m   R

"""


def findMyIndex(arr, ele):
    """
    
    Function to perform binary search over the give array
    
    """
    l, r = 0, len(arr) - 1
    ans = -1
    while(l <= r):
        mid = l + (r - l)//2
        if arr[mid] == ele:
            ans = mid
            l = mid + 1
        elif arr[mid] < ele:
            l = mid + 1
        else:
            r = mid - 1
    
    return ans


if __name__ == '__main__':
    a = [d for d in range(100)]
    print(a)

    # Case - 1: Element is there
    print(findMyIndex(a, 71))

    # Case - 2: Element is not there
    print(findMyIndex(a, 101))