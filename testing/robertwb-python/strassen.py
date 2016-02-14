from random import xorshift128plus as rand
import copy


def generateMatrix(rows, columns, mask):
    matrix = []
    for i in range(rows):
        row = []
        for j in range(columns):
            row.append(rand() & mask)
        matrix.append(row)
    return matrix


def printMatrix(matrix):
    for row in matrix:
        for val in row:
            print('{:10}'.format(val), end="")
        print()


def matrixMultiplication(A, B):
    # A = nxm, B = mxp, C = nxp
    n = len(A)
    m = len(A[0])
    p = len(B[0])
    C = [[0]*p for i in range(n)]
    for i in range(n):
        for j in range(p):
            theSum = 0
            for k in range(m):
                theSum += A[i][k] * B[k][j]
            C[i][j] = theSum
    return C


def addMatrix(A, B):
    C = copy.deepcopy(A)
    for i in range(len(C)):
        for j in range(len(C[i])):
            C[i][j] += B[i][j]
    return C


def subtractMatrix(A, B):
    C = copy.deepcopy(A)
    for i in range(len(C)):
        for j in range(len(C[i])):
            C[i][j] -= B[i][j]
    return C


def strassen(A, B):
    if len(A) <= 128:
        return matrixMultiplication(A, B)
    mid = len(A)//2
    A11 = [A[i][:mid] for i in range(0, mid)]
    A12 = [A[i][mid:] for i in range(0, mid)]
    A21 = [A[i][:mid] for i in range(mid, len(A))]
    A22 = [A[i][mid:] for i in range(mid, len(A))]
    # print()
    # printMatrix(A11)
    # print()
    # printMatrix(A12)
    # print()
    # printMatrix(A21)
    # print()
    # printMatrix(A22)
    B11 = [B[i][:mid] for i in range(0, mid)]
    B12 = [B[i][mid:] for i in range(0, mid)]
    B21 = [B[i][:mid] for i in range(mid, len(B))]
    B22 = [B[i][mid:] for i in range(mid, len(B))]
    S1 = addMatrix(A21, A22)
    S2 = subtractMatrix(S1, A11)
    S3 = subtractMatrix(A11, A21)
    T1 = subtractMatrix(B12, B11)
    T2 = subtractMatrix(B22, T1)
    T3 = subtractMatrix(B22, B12)
    S4 = subtractMatrix(A12, S2)
    T4 = subtractMatrix(T2, B21)
    P1 = strassen(A11, B11)
    P2 = strassen(A12, B21)
    P3 = strassen(S4, B22)
    P4 = strassen(A22, T4)
    P5 = strassen(S1, T1)
    P6 = strassen(S2, T2)
    P7 = strassen(S3, T3)
    U1 = addMatrix(P1, P2)
    U2 = addMatrix(P1, P6)
    U3 = addMatrix(U2, P7)
    U4 = addMatrix(U2, P5)
    U5 = addMatrix(U4, P3)
    U6 = subtractMatrix(U3, P4)
    U7 = addMatrix(U3, P5)

    # printMatrix(U1)
    # print()
    # printMatrix(U6)
    # print()
    # printMatrix(U5)
    # print()
    # printMatrix(U7)

    U1.extend(U6)
    U5.extend(U7)

    # print()
    # printMatrix(U1)
    # print()
    # printMatrix(U5)
    # print()
    for i in range(len(U1)):
        U1[i].extend(U5[i])
    # printMatrix(U1)
    return U1


def main():
    print(rand())
    m1 = generateMatrix(512, 512, 10)
    m2 = generateMatrix(512, 512, 10)
    # print()
    # printMatrix(m1)
    # print()
    # printMatrix(m2)
    res = matrixMultiplication(m1, m2)
    printMatrix(res)
    # C = strassen(m1, m2)
    # printMatrix(C)

if __name__ == '__main__':
    main()
