def main():
    # Number of rows and columns
    n, m = 3, 5

    # Loop through each row
    for i in range(1, n + 1):

        # Loop through each column in the current row
        for j in range(1, m + 1):
            # Print a star
            print("*", end=" ")

        # Move to the next row
        print()


if __name__ == "__main__":
    main()
