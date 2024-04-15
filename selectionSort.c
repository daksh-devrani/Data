#include<stdio.h>
void swap(int *a,int *b){
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
void selectionSort(int *arr,int n){
    int min=*arr,a=0;
    for(int i=0;i<n-1;i++){
        min=*(arr+i);
        for(int j=i+1;j<n;j++){
            if(min>*(arr+j)){
                min=*(arr+j);
                a=j;
            }
        }
        if(*(arr+i)>min){
            swap((arr+i),(arr+a));
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
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}