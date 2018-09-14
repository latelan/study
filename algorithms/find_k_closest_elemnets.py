def find_closest_elements(arr, k, x):
    left, right = 0, len(arr)-k
    while left < right:
        mid = (left + right) // 2
        if x - arr[mid] > arr[mid+k] - x:
            left = mid + 1
        else:
            right = mid
    return arr[left:left+k]

def test_find_closest_elements():
    data = [1,2,3,4,5]
    k = 4
    x = 3
    print(find_closest_elements(data, k, x))

if __name__ == '__main__':
    test_find_closest_elements()
