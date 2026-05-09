def findUnion(a, b):
    res = []

    # Traverse through a[] and search every element
    # a[i] in result
    for i in range(len(a)):

        # check if the element is already
        # in the result to avoid duplicates
        j = 0
        while j < len(res):
            if res[j] == a[i]:
                break
            j += 1

        if j == len(res):
            res.append(a[i])

    # Traverse through b[] and search every element
    # b[i] in result
    for i in range(len(b)):

        # check if the element is already
        # in the result to avoid duplicates
        j = 0
        while j < len(res):
            if res[j] == b[i]:
                break
            j += 1
        if j == len(res):
            res.append(b[i])

    return res


if __name__ == "__main__":
    a = [1, 2, 3, 2, 1]
    b = [3, 2, 2, 3, 3, 2]

    res = findUnion(a, b)

    for value in res:
        print(value, end=" ")
