from random import xorshift128plus as rand


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
            print('{:4}'.format(val), end="")
        print()


def matrixMultiplication(m1, m2):
    for i in range(len(m1)):
        for j in range(len(m2))


def main():
    print(rand())
    m1 = generateMatrix(4, 4, 100)
    m2 = generateMatrix(4, 4, 100)
    print()
    printMatrix(m1)
    print()
    printMatrix(m2)
    res = matrixMultiplication(m1, m2)
    print()
    printMatrix(res)

if __name__ == '__main__':
    main()
