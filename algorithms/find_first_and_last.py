def find_left_index(nums, target):
    left, right = 0, len(nums)
    while left < right:
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid
    if left != len(nums) and nums[left] == target:
        return left
    return -1

def find_right_index(nums, target):
    left, right = 0, len(nums)
    while left < right:
        mid = (left + right) // 2
        if nums[mid] <= target:
            left = mid + 1
        else:
            right = mid
    if nums[left-1] == target:
        return left - 1
    return -1

class Solution(object):
    def search_range(self, nums, target):

        def search_left():
            left, right = 0, len(nums)
            while left < right:
                mid = (left + right) // 2
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid
            if left != len(nums) and nums[left] == target:
                return left
            return -1

        def search_right():
            left, right = 0, len(nums)
            while left < right:
                mid = (left + right) // 2
                if nums[mid] <= target:
                    left = mid + 1
                else:
                    right = mid
            if nums[left-1] == target:
                return left - 1
            return -1
        
        return [search_left(), search_right()]

if __name__ == '__main__':
    data = [5,5,7,7,7]
    key = 4
    #print(find_left_index(data, key))
    #print(find_right_index(data, key))

    s = Solution()
    print(s.search_range(data, key))

