#include <stdio.h>

void main(){
    int repeatBoolMatrix[9][9], board[9][9];

    //Example of solved board(correct)
    /*
    int board[9][9] = {{8,2,7,1,5,4,3,9,6},
                    {9,6,5,3,2,7,1,4,8},
                    {3,4,1,6,8,9,7,5,2},
                    {5,9,3,4,6,8,2,7,1},
                    {4,7,2,5,1,3,6,8,9},
                    {6,1,8,9,7,2,4,3,5},
                    {7,8,6,2,3,5,9,1,4},
                    {1,5,4,7,9,6,8,2,3},
                    {2,3,9,8,4,1,5,6,7}
                };
    */

    //To take user-input
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &board[i][j]);
            if(board[i][j] > 9 || board[i][j]<1){
                printf("Element should be between 1 and 9 (1 and 9 included).");
                return;
            }
        }
    }

    //Inetializing the resultant matrix
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            repeatBoolMatrix[i][j] = 0;
        }
    }
    //Row and column check
    for(int i=0; i<9; i++){
        int row[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int col[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int j=0; j<9; j++){
            int rowV = 0;
            int colV = 0;
            for(int k=0; k<=9 && (rowV==0 || colV==0); k++){
                if(k == 9 && rowV==0) repeatBoolMatrix[i][j] = 1;
                else if(board[i][j] == row[k]){
                    row[k] = 0;
                    rowV = 1;
                }

                if(k == 9 && colV==0) repeatBoolMatrix[j][i] = 1;
                else if(board[j][i] == col[k]){
                    col[k] = 0;
                    colV = 1;
                }
            }
        }
    }


    //3x3 check
    for(int i=0; i<9; i+=3){
        for(int j=i; j<9; j+=3){
            int bigCellrow[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            int bigCellcol[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            for(int row=i; row<i+3; row++){
                for(int col=j; col<j+3; col++){
                    int rowV = 0;
                    int colV = 0;
                    for(int k=0; k<=9 && (rowV==0 || colV==0); k++){
                        if(k == 9 && rowV==0) repeatBoolMatrix[row][col] = 1;
                        else if(bigCellrow[k] == board[row][col]){
                            bigCellrow[k] = 0;
                            rowV = 1;
                        }

                        if(k == 9 && colV==0) repeatBoolMatrix[col][row] = 1;
                        else if(bigCellcol[k] == board[col][row]){
                            bigCellcol[k] = 0;
                            colV = 1;
                        }
                    }
                }
            }
        }
    }

    //Printing the resultant matrix
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("\t%d\t", repeatBoolMatrix[i][j]);
        }
        printf("\n");
    }
}