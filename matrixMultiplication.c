#include <stdio.h>

void main(){
    int row1, row2, col1, col2, sum=0;

    printf("Enter number of rowns in Matrix 1: ");
    scanf("%d", &row1);
    printf("Enter number of columns in Matrix 1: ");
    scanf("%d", &col1);

    printf("Enter number of rowns in Matrix 2: ");
    scanf("%d", &row2);
    printf("Enter number of columns in Matrix 2: ");
    scanf("%d", &col2);

    if(col1 != row2){
        printf("Matrix cannot be multiplied. To multiply matrix A to B, size of A should be axb and size of B should be bxc.");
        return;
    }

    int mat1[row1][col1], mat2[row2][col2], resultMat[row1][col2];

    printf("Enter elements for matrix 1:\n");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements for matrix 2:\n");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for(int row = 0; row<row1; row++){
        for(int col=0; col<col2; col++){
            for(int ele=0; ele<col1; ele++){
                sum += mat1[row][ele]*mat2[ele][col];
            }
            resultMat[row][col] = sum;
            sum = 0;
        }
    }

    printf("Result of matrix multiplication is:\n");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            printf("\t%d\t", resultMat[i][j]);
        }
        printf("\n");
    }
}