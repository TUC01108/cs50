def move_zero(nums):
    not_zero = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[not_zero] = nums[i]
            not_zero += 1
    while not_zero != len(nums):
        nums[not_zero] = 0
        not_zero += 1
    return nums

arr = [0,1,0,3,12,]
print(move_zero(arr))