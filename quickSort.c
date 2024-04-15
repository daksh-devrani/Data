#include<stdio.h>
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int partition(int *arr,int left,int right){
    int pivot=*(arr+right);
    int a=(left-1);
    for(int i=left;i<right;i++){
        if(*(arr+i)<=pivot){
            a++;
            swap(arr+a,arr+i);
        }
    }
    swap(arr+a+1,arr+right);
    return(a+1);
}
void quickSort(int *arr,int left,int right){
    if(left<right){
        int pivot=partition(arr,left,right);
        quickSort(arr,left,pivot-1);
        quickSort(arr,pivot+1,right);
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
    int left=0,right=n-1; 
    quickSort(arr,left,right);
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}