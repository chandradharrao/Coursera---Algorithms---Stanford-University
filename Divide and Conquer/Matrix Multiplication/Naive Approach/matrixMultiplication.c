#include <stdio.h>
#include <stdlib.h>

void print2dMatrix(int** X,int n){
    printf("\nPrinting the matrix ....\n");
    for(int i = 0;i<n;i++){
        printf("|");
        for(int j = 0;j<n;j++){
            if(j == n-1){
                printf("%d",X[i][j]);
            }
            else{
                printf("%d\t",X[i][j]);
            }
        }
        printf("|\n");
    }
}

int** init2dMatrix(int n){
    int** X = (int**)malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        X[i] = (int*)malloc(sizeof(int)*n);
    }

    //fill in with zeroes initially
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            X[i][j] = 0;
        }
    }
    //printf("\nThe matrix Created is \n");
    //print2dMatrix(X,n);
    return X;
}

void fill2dMatrix(int** X,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("\nEnter %dth row and %dth col vals\n",i,j);
            scanf("%d",&X[i][j]);
        }
    }

    print2dMatrix(X,n);
}

int** mul2dMatrix(int** X,int** Y,int n){
    printf("\nStarting Matrix Multiplication.....\n");
    int** Z = (int**)malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        Z[i] = (int*)malloc(sizeof(int)*n);
        //initialize with zeroes
        for(int q = 0;q<n;q++){
            Z[i][q] = 0;
        }
        for(int j = 0;j<n;j++){
            for(int k = 0;k<n;k++){
                //printf("\nProd is %d\n",X[i][k]*Y[k][j]);
                Z[i][j] = Z[i][j] +  (X[i][k]*Y[k][j]);
                printf("\nRunning Sum is %d\n",Z[i][j]);
            }
        }
    }
    return Z;
}

int main(){
    int n;
    printf("\nEnter the dim of sqr matrix\n");
    scanf("%d",&n);
    
    int** X = init2dMatrix(n);
    int** Y = init2dMatrix(n);

    printf("\nEnter the Values of matrix X\n");
    fill2dMatrix(X,n);
    printf("\nEnter the values of matrix Y\n");
    fill2dMatrix(Y,n);

    int** Z = mul2dMatrix(X,Y,n);
    printf("\nThe result of matrix multiplication is:\n");
    print2dMatrix(Z,n);

}