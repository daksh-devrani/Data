#include<stdio.h>
void merge(int arr[],int l,int m,int r){
    int n=m-l+1;
    int n2=r-m;
    int L[n];
    int R[n2];
    for(int i=0;i<n;i++)
        L[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    int k=l,i=0,j=0;
    while(i<n && j<n2){
        if(L[i]<R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];       
    }        
    while(i<n)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int n,l=0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter %d term: ",i);
        scanf("%d",&arr[i]);
    } 
    mergeSort(arr,l,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}