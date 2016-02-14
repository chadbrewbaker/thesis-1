from random import randint

# No error checking is made!
# Make sure the matrices are of the correct sizes
def naive(m1, m2):
    result = []
    for i in range (0, len(m1)):
        result.append([])
    for y1 in range (0, len(m1)): # Loop through the rows in matrix 1
        for x2 in range (0, len(m2[0])): # Loop through the columns in matrix 2
            temp = 0
            for x1 in range (0, len(m1[y1])): # Loop through the columns in matrix 1
                temp += (m1[y1][x1] * m2[x1][x2])
            result[y1].append(temp)
    return result


def generate(x, y):
    matrix = []
    for i in range (0, x):
        matrix.append([])
        for j in range (0, y):
            matrix[i].append(randint(0, 100))
    return matrix


def printMatrix(matrix):
    for row in matrix:
        for val in row:
            print('{:10}'.format(val), end="")
        print()
    print()

a = generate(4,4)
b = generate(4,4)
printMatrix(a)
printMatrix(b)
printMatrix(naive(a, b))
