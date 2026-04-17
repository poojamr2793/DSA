arr = [10, 20, 30, 40, 50]

# Insert
arr.append(60)
arr.insert(2, 25)

# Delete
arr.remove(40)
arr.pop(0)

# Update
arr[1] = 99

# Traverse
for x in arr:
    print(x, end=" ")

print()

# Sorting
arr.sort()

# Reverse
arr.reverse()

# Output
print("Final Array:", arr)
print("Max:", max(arr))
print("Min:", min(arr))
print("Sum:", sum(arr))
