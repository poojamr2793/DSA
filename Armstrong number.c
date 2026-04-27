def power(x, y):
    if y == 0:
        return 1
    if y % 2 == 0:
        return power(x, y // 2) * power(x, y // 2)
    return x * power(x, y // 2) * power(x, y // 2)

# Function to count number of digits in n
def order(n):
    t = 0
    while n:
        t += 1
        n //= 10
    return t

# Function to check whether the given 
# number is Armstrong number or not
def armstrong(n):
    
    # Calling order function
    x = order(n)
    temp = n
    sum_ = 0
    while temp:
        r = temp % 10
        sum_ += power(r, x)
        temp //= 10

    # If satisfies Armstrong condition
    return sum_ == n
    
if __name__ == "__main__":
    n = 153
    if armstrong(n):
        print("true")
    else:
        print("false")
