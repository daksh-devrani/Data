#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1,rear=-1;
void enqueue(int n){
    if((rear+1)%max==front)
        printf("Overflow\n");
    else{
        if(rear==front && front==-1){
            front=0;
            rear=0;
            queue[rear]=n;
        }  
        else{
            rear=(rear+1)%max;
            queue[rear]=n;
        }
    } 
}

void dequeue(){
    if(rear==-1)
        printf("Underflow\n");
    else{
        if(rear==front){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%max;
        }
    }    
}

void traverse(){
    int i=front;
    if(front==-1)
        printf("Underflow\n");
    else{    
            while((i)!=rear){
                printf("%d ",queue[i]);
                i=(i+1)%max;
            }
            printf("%d ",queue[i]);
    }    
}

int main(){
    int n,a;
    while(1){
        printf("\nEnter choice\n1. enqueue\n2. dequeue\n3. traverse\n4. exit : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter data: ");
                scanf("%d",&a);
                enqueue(a);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;        
            default:
                exit(1);    
        }
    }
}
