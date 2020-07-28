def flip(arr, k):
    start = 0
    while start < k:
        temp = arr[start]
        arr[start] = arr[k]
        arr[k] = temp
        start += 1
        k -= 1
    return arr

arr = [3,1,4,5,2]
print(flip(arr, 1))