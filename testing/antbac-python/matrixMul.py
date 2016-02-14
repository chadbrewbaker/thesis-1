from random import randint


def add(m1, m2):
    for y in range (0, len(m1)):
        for x in range (0, len(m1[0])):
            m1[y][x] += m2[y][x]
    return m1

def sub(m1, m2):
    for y in range (0, len(m1)):
        for x in range (0, len(m1[0])):
            m1[y][x] -= m2[y][x]
    return m1


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

# No error checking is made!
# Make sure the matrices are of the correct sizes
# -----------------------------------------------
# Strassen(A,B)
# If n = 1 Output AxB
# Else
# Compute A(11),B(11),...,A(22),B(22) by computing m = n/2
# P1 = Strassen(A(11),B(12)-B(22))
# P2 = Strassen(A(11)+A(12),B(22))
# P3 = Strassen(A(21)+A(22),B(11))
# P4 = Strassen(A(22),B(21)-B(11))
# P5 = Strassen(A(11)+A(22),B(11)+B(22))
# P6 = Strassen(A(12)-A(22),B(21)+B(22))
# P7 = Strassen(A(11)-A(21),B(11)+B(12))
# C11 = P5+P4-P2+P6
# C12 = P1+P2
# C21 = P3+P4
# C22 = P1+P5-P3-P7
# Output C
def strassen(m1, m2):
    if len(m1) <= 16:
        return naive(m1, m2)
    else:
        A11 = [] # A11 = [A[i][:mid] for i in range(0, mid)]
        A12 = []
        A21 = []
        A22 = []
        B11 = []
        B12 = []
        B21 = []
        B22 = []
        P1 = Strassen(A11, sub(B12,B22))
        P2 = Strassen(add(A11, A12), B22)
        P3 = Strassen(add(A21, A22), B11)
        P4 = Strassen(A22, sub(B21,B11))
        P5 = Strassen(add(A11, A22), add(B11,B22))
        P6 = Strassen(sub(A12, A22), add(B21,B22))
        P7 = Strassen(sub(A11, A21), add(B11,B12))
        C11 = add(sub(add(P5, P4), P2), P6)
        C12 = add(P1, P2)
        C21 = add(P3, P4)
        C22 = sub(sub(add(P1, P5), P3), P7)
        C = []
        return C


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

a = generate(128,128)
b = generate(128,128)
printMatrix(a)
printMatrix(b)
printMatrix(naive(a, b))
