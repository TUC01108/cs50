def flip(arr, k):
    start = 0
    finish = k
    while start < finish:
        arr[start], arr[finish] = arr[finish], arr[start]
        start += 1
        finish -= 1
    return arr

def pancake_sort(arr):
    for i in reversed(range(len(arr))):
        max_index = find_max_index(arr, i)
        flip(arr, max_index)
        flip(arr, i)
    return arr

def find_max_index(arr,i):
    max_val = arr[0]
    max_index = 0
    for j in range(i + 1):
        if arr[j] > max_val:
            max_val = arr[j]
            max_index = j
    return max_index

arr = [10, 3, 1, 0, 8]
k = 3
print(pancake_sort(arr))