def decodedString(s):
    numStack = []
    charStack = []
    temp = ""
    res = ""

    i = 0
    while i < len(s):
        cnt = 0

        # If Digit, convert it into number and
        # push it into integer stack.
        if s[i].isdigit():
            while i < len(s) and s[i].isdigit():
                cnt = cnt * 10 + int(s[i])
                i += 1
            i -= 1
            numStack.append(cnt)

        # If closing bracket ']' is encountered
        elif s[i] == ']':
            temp = ""

            cnt = numStack.pop()

            # Pop element till opening bracket '[' is not found
            # in the character stack.
            while charStack[-1] != '[':
                temp = charStack.pop() + temp
            charStack.pop()

            # Repeating the popped string 'temp' count number of times.
            res = temp * cnt

            # Push it in the character stack.
            for c in res:
                charStack.append(c)

            res = ""
        else:
            charStack.append(s[i])
        i += 1

    # Pop all the elements, make a string and return.
    while charStack:
        res = charStack.pop() + res

    return res


if __name__ == "__main__":
    s = "3[b2[ca]]"
    print(decodedString(s))
