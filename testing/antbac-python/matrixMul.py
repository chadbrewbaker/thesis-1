import random
import copy

def add(m1, m2):
    result = copy.deepcopy(m1)
    for y in range (0, len(m1)):
        for x in range (0, len(m1[0])):
            result[y][x] += m2[y][x]
    return result

def sub(m1, m2):
    result = copy.deepcopy(m1)
    for y in range (0, len(m1)):
        for x in range (0, len(m1[0])):
            result[y][x] -= m2[y][x]
    return result


# No error checking is performed!
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

# No error checking is performed!
# Make sure the matrices are of the correct sizes
def strassen(A, B):
    mid = len(A) // 2
    if len(A) <= 256:
        return naive(A, B)
    else:
        A11 = [A[i][:mid] for i in range(0, mid)]
        A12 = [A[i][mid:] for i in range(0, mid)]
        A21 = [A[i][:mid] for i in range(mid, len(A))]
        A22 = [A[i][mid:] for i in range(mid, len(A))]
        B11 = [B[i][:mid] for i in range(0, mid)]
        B12 = [B[i][mid:] for i in range(0, mid)]
        B21 = [B[i][:mid] for i in range(mid, len(B))]
        B22 = [B[i][mid:] for i in range(mid, len(B))]
        P1 = strassen(A11, sub(B12,B22))
        P2 = strassen(add(A11, A12), B22)
        P3 = strassen(add(A21, A22), B11)
        P4 = strassen(A22, sub(B21,B11))
        P5 = strassen(add(A11, A22), add(B11,B22))
        P6 = strassen(sub(A12, A22), add(B21,B22))
        P7 = strassen(sub(A11, A21), add(B11,B12))
        C11 = add(sub(add(P5, P4), P2), P6)
        C12 = add(P1, P2)
        C21 = add(P3, P4)
        C22 = sub(sub(add(P1, P5), P3), P7)
        C11.extend(C21)
        C12.extend(C22)
        for i in range(0, len(C11)):
            C11[i].extend(C12[i])
        return C11


def generate(x, y):
    matrix = []
    for i in range (0, x):
        matrix.append([])
        for j in range (0, y):
            matrix[i].append(random.randint(0, 10))
    return matrix


def printMatrix(matrix):
    for row in matrix:
        for val in row:
            print('{:10}'.format(val), end="")
        print()
    print()

random.seed(1)
a = generate(512,512)
b = generate(512,512)
#print("a")
#printMatrix(a)
#print("b")
#printMatrix(b)
#print("naive")
#printMatrix(naive(a, b))
#print("strassen")
#printMatrix(strassen(a, b))
strassen(a,b)
#naive(a, b)
