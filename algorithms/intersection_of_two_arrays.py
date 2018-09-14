def intersection(nums1, nums2):
    nums1_set = set(nums1)
    nums2.sort()
    res = set()
    for x in nums1_set:
        if binary_search(nums2, x):
            res.add(x)

    return  list(res)

def binary_search(nums, key):
    left, right = 0, len(nums)
    while left < right:
        mid = (left + right) // 2
        if nums[mid] == key:
            return True
        elif nums[mid] < key:
            left = mid + 1
        else:
            right = mid

    return False

def test_intersection():
    nums1 = [1,2,2,1]
    nums2 = [2,2,1]
    print(intersection(nums1, nums2))

if __name__ == '__main__':
    test_intersection()
