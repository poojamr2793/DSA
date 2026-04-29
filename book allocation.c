def check(arr, k, pageLimit):
    
    # starting from the first student
    cnt = 1
    pageSum = 0
    for pages in arr:
        
        # if adding the current book exceeds the page 
        # limit, assign the book to the next student
        if pageSum + pages > pageLimit:
            cnt += 1
            pageSum = pages
        else:
            pageSum += pages
    
    # if books can assigned to less than k students then
    # it can be assigned to exactly k students as well
    return cnt <= k

def findPages(arr, k):
    
    # if number of students are more than total books
    # then allocation is not possible
    if k > len(arr):
        return -1
    
    # minimum and maximum possible page limits
    minPageLimit = max(arr)
    maxPageLimit = sum(arr)

    # iterating over all possible page limits
    for i in range(minPageLimit, maxPageLimit + 1):
        
        # return the first page limit with we can
        # allocate books to all k students
        if check(arr, k, i):
            return i

    return -1

 
if __name__ == "__main__":
    arr = [12, 34, 67, 90]
    k = 2
    print(findPages(arr, k))
