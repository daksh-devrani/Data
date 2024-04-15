#include<stdio.h>
void swap(int *a,int *b){
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
void bubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(arr+j)>*(arr+j+1))
                swap((arr+j),(arr+j+1));
        }
    }
}
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter %d term: ",i);
        scanf("%d",&arr[i]);
    } 
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}