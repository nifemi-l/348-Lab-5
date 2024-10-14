#include <stdio.h> 

// define size macro
#define SIZE 5

// define the add matrices function
// the function returns a pointer to a 1D array of SIZE integers (row of matrix), use pointer arithmetic to get subsequent rows
int (*addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE] { 
    // create variable to return
    static int result[SIZE][SIZE]; 

    // loop through the indices of array of arrays
    for (int i = 0; i < SIZE; i++) { 
        // loop through the indices of each array
        for (int j = 0; j < SIZE; j++) { 
            // write the addition to the result variable
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return result;
}

// define the multiply matrices function
int (*multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE] { 
    // create variable to return
    static int result[SIZE][SIZE]; 

    // check if dimensions are compatible
    if (SIZE != SIZE) {  // trivial here since they are both SIZE x SIZE, but included per instructions
        printf("Error: Matrix dimensions are incompatible for multiplication.\n");
        return NULL;  // return null for error
    }

    // loop through the indices of the array of arrays
    for (int i = 0; i < SIZE; i++) { 
        // loop through the indices of each array
        for (int j = 0; j < SIZE; j++) { 
            // write the multiplication to the result variable
            result[i][j] = m1[i][j] * m2[i][j];
        }
    }

    return result;
}

// define the transpose matrix function
int (*transposeMatrix(int matrix[SIZE][SIZE]))[SIZE] { 
    // create variable to return
    static int result[SIZE][SIZE]; 

    // loop through the indices of the array
    for (int i = 0; i < SIZE; i++) { 
        // loop through the indices of the array
        for (int j = 0; j < SIZE; j++) { 
            // write the transpose to the result variable
            result[i][j] = matrix[j][i]; 
        }
    }

    return result;
}

void printMatrix(int matrix[SIZE][SIZE]){ 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) { 
            // implicitly dereference the pointer
            printf("%d ", matrix[i][j]); 

            // print a new line
            if ((j + 1) == SIZE) { 
                printf("\n");
            }
        }
    }
}

int main() { 
    // define the first matrix
    int m1[SIZE][SIZE] = { 
        { 1, 2, 3, 4, 5 }, 
        { 6, 7, 8, 9, 10 }, 
        { 11, 12, 13, 14, 15 }, 
        { 16, 17, 18, 19, 20 }, 
        { 21, 22, 23, 24, 25 }
    };

    // define the second matrix
    int m2[SIZE][SIZE] = {
        { 25, 24, 23, 22, 21 },
        { 20, 19, 18, 17, 16 },
        { 15, 14, 13, 12, 11 },
        { 10, 9, 8, 7, 6 },
        { 5, 4, 3, 2, 1 }
    };

    // obtain addition of matrices
    // declare variable that is a pointer to array
    int (*result)[SIZE] = addMatrices(m1, m2); 

    // print the result of the add operation
    printf("Sum of Matrices:\n");
    printMatrix(result);

    // obtain multiplication of matrices
    int (*result1)[SIZE] = multiplyMatrices(m1, m2);

    // print the result of the multiply operation
    printf("\nMultiplication of Matrices:\n"); 
    printMatrix(result1);

    // obtain transpose of matrix 1
    int (*result2)[SIZE] = transposeMatrix(m1); 

    // print the transpose
    printf("\nTranspose of Matrix:\n");
    printMatrix(result2);
}