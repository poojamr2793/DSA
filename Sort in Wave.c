def sortInWave(arr):
    
    n = len(arr)
   
    # swap adjacent elements
    for i in range(0,n-1,2):
        arr[i], arr[i+1] = arr[i+1], arr[i]

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    sortInWave(arr)
    for i in range(0,len(arr)):
        print (arr[i],end=" ")
