//counting the number of inversions in O(nlogn)
#include <stdio.h>
#include <stdlib.h>
//to store number of inversions
int counter = 0;

void arrPrinter(int* A,int l,int h){
    for(int i = l;i<=h;i++){
        printf("%d,",A[i]);
    }
}

//we are dividing the array based on the indexes
void splitInvCounter(int* A,int l,int mid,int h){
    //index to traverse temp array
    int k = 0;
    //number of elements
    int n = (mid - l + 1) + (h - (mid+1) + 1);
    int* temp = (int*)malloc(sizeof(int)*n);

    int i = l;
    int j = mid+1;
    while(i<=mid && j<=h){
        //copying from right half => there is an inversion
        if(A[i]>A[j]){
            //the elements on the left sub array are greater
            printf("\n**************************\n");
            printf("\nLow %d\n",l);
            printf("\nMid %d\n",mid);
            printf("\nHigh %d\n",h);
            printf("\n%d > %d\n",A[i],A[j]);
            printf("\n# curr Invs = %d\n",(mid-i) + 1);
            printf("\n**************************\n");
            counter = counter + (mid-i) + 1;
            temp[k] = A[j];
            j++;
            k++;
        }else{ //copying from left half => standard
            temp[k] = A[i];
            i++;
            k++;
        }
    }
    
    while(i<=mid){
        temp[k] = A[i];
        i++;
        k++;
    }

    while(j<=h){
        temp[k] = A[j];
        j++;
        k++;
    }

    printf("\nSoted sub array is :\n");
    for(int i = 0;i<n;i++){
        printf("%d,",temp[i]);
    }

    //copy the sorted array
    for(int i = 0;i<n;i++){
        A[l+i] = temp[i];
    }
}

void invCounter(int* A,int l,int h){
    //if only one element,then no inversions
    if(l == h){
        printf("\n-------------------\n");
        printf("\nSingle element\n");
        arrPrinter(A,l,h);
        printf("\nLow %d\n",l);
        printf("\nHigh %d\n",h);
        //int x;
        //scanf("%d",&x);
        printf("\n-------------------------\n");
        return;
    }

    //divide the array until only one element is left
    int mid = l + ((h-l)/2);

    printf("\n---------------------\n");
    arrPrinter(A,l,h);
    printf("\nLow %d\n",l);
    printf("\nMid %d\n",mid);
    printf("\nHigh %d\n",h);
    //int x;
    //scanf("%d",&x);
    printf("\n---------------------\n");

    invCounter(A,l,mid);//first and mid index passed
    invCounter(A,mid+1,h);//mid+1 index and last index passed
    splitInvCounter(A,l,mid,h);
}

int main(){
    int n;
    printf("\nEnter the number of elements in the array\n");
    scanf("%d",&n);
    int* A = (int*)malloc(sizeof(int)*n);
    printf("\nEnter the elements\n");
    for(int i = 0;i<n;i++){
        scanf("%d",(A+i));
    }
    
    //call the recursive function
    invCounter(A,0,n-1); //passing the first and last index of the array
    printf("\nThe sorted array is\n:");
    arrPrinter(A,0,n-1);
    printf("\nThe number of inversions are %d\n",counter);
}