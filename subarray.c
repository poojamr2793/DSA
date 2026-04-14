arr = [1, 2, 3, 7, 5]
target = 12

start = 0
current_sum = 0

for end in range(len(arr)):
    current_sum += arr[end]
    
    while current_sum > target:
        current_sum -= arr[start]
        start += 1
    
    if current_sum == target:
        print("Subarray found from index", start, "to", end)
