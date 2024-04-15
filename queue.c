#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
void enqueue(){
    if(rear==max-1)
        printf("Overflow\n");
    else{
        if(front==-1){
            rear=0;
            front=0;
            printf("Enter data: ");
            scanf("%d",&queue[rear]);
        }       
        else{
            rear++;
            printf("Enter data: ");
            scanf("%d",&queue[rear]);
        }
    }    
}
void dequeue(){
    if(rear==-1)
        printf("Underflow\n");
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }        
        else{
            front++;
        }
    }         
}
void display(){
    int i=0;
    if(rear==-1)
        printf("Underflow\n");
    else{
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }    
}
int main(){
    int n;
    while(1){
        printf("\nEnter choice\n1. Enqueue\n2. Dequeue\n3. Display\n4. exit : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;        
            default:
                exit(1);    
        }
    }
}
