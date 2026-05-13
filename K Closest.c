def printKClosest(arr, k, x):
    # Custom sort using absolute difference and tie-breaking
    # -a to prefer larger on tie
    arr.sort(key=lambda a: (abs(a - x), -a))  

    result = []
    count = 0

    # Pick first k elements not equal to x
    for num in arr:
        if num == x:
            continue  # skip if element is equal to x
        result.append(num)
        count += 1
        if count == k:
            break

    return result

if __name__ == "__main__":
    arr = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56]
    k = 4
    x = 35
    
    closest = printKClosest(arr, k, x)
    print( *closest)
