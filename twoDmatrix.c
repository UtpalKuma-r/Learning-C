#include <stdio.h>

void main(){
    int row, col;

    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of columns: ");
    scanf("%d", &col);

    int arr[row][col];

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("Enter element at [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("\t%d\t", arr[i][j]);
        }
        printf("\n");
    }

}