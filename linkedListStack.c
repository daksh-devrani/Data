#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;

void push(struct node *new1){
    if(top == NULL)
			top = new1;
		else{
			new1->next = top;
			top = new1;
		}
}

void pop(){
    struct node *temp=top;
    if(top == NULL)
			printf("UNDERFLOW\n");
		else
			top = top->next;    
            free(temp);
            temp=NULL;
}

void display(){
    struct node *temp = top;
		if(top == NULL)
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
        printf("\nEnter choice\n1. push\n2. pop\n3. display\n4. exit : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                new1 = (struct node*)malloc(sizeof(struct node));
				printf("enter the data\n");
				scanf("%d",&new1->data);
				new1->next = NULL;
                push(new1);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;        
            default:
                exit(1);    
        }
    }
}