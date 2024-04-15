#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(struct node *new1){
		if(rear == NULL){
			rear = new1;
            front = new1;
        }
		else{
			rear->next=new1;
            rear=new1;
		}
}

void dequeue(){
    struct node *temp=front;
    if(rear == NULL)
			printf("UNDERFLOW\n");
		else{
			front = front->next;
            free(temp);
            temp=NULL;
        }
}

void display(){
    struct node *temp = front;
		if(rear == NULL)
			printf("UNDERFLOW\n");
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
}

int main(){
    struct node *new1;
    int n;
    while(1){
        printf("\nEnter choice\n1. enqueue\n2. dequeue\n3. display\n4. exit : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                new1 = (struct node*)malloc(sizeof(struct node));
				printf("enter the data\n");
				scanf("%d",&new1->data);
				new1->next = NULL;
                enqueue(new1);
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