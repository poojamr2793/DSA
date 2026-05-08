def leftRotate(n, d):
    
    d = d % 32
    
    mask = ~((1 << (32 - d)) - 1)
    shift = (n & mask)
    
    n = (n << d)
    
    n += (shift >> (32 - d))

t
    return n & ((1 << 32) - 1)

def rightRotate(n, d):
    
    d = d % 32
    
    mask = (1 << d) - 1
    shift = (n & mask)
    
    n = (n >> d)
    
    n += (shift << (32 - d))

    return n & ((1 << 32) - 1)

def rotateBits(n, d):
    
    res = [0] * 2
    
    res[0] = leftRotate(n, d)
    res[1] = rightRotate(n, d)
    
    return res
if __name__ == "__main__":
    
    n, d = 28, 2

    result = rotateBits(n, d)
    
    print(result[0], result[1])
