def cycleSort(arr):
    
    n = len(arr)
    
    # traverse array elements and put it to on the right place
    for cycle_start in range(0, n - 1):
        
        # initialize item as starting point
        item = arr[cycle_start]

        # Find position where we put the item. 
        # We basically count all smaller elements on right side of item.
        pos = cycle_start
        for i in range(cycle_start + 1, n):
            if arr[i] < item:
                pos += 1

        # If item is already in correct position
        if pos == cycle_start:
            continue

        # ignore all duplicate elements
        while item == arr[pos]:
            pos += 1

        # put the item to its right position
        if pos != cycle_start:
            arr[pos], item = item, arr[pos]

        # Rotate rest of the cycle
        while pos != cycle_start:
            pos = cycle_start

            # Find position where we put the element
            for i in range(cycle_start + 1, n):
                if arr[i] < item:
                    pos += 1

            # ignore duplicates
            while item == arr[pos]:
                pos += 1

            # put the item to its right position
            if item != arr[pos]:
                arr[pos], item = item, arr[pos]


if __name__ == "__main__":
    arr = [3,5,2,1,4]
    n = len(arr)

    cycleSort(arr)

    for x in arr:
        print(x, end=" ")
