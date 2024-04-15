#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[max];
int top=-1;
void push(){
    if(top==max-1)
        printf("Overflow");
    else{
        top++;
        printf("Enter data: ");
        scanf("%d",&stack[top]);
    }    
}
void pop(){
    if(top==-1)
        printf("Underflow");
    else
        top--; 
}
void display(){
    int i=top;
    if(top==-1)
        printf("Underflow");
    else{
        while(i>=0){
            printf("%d ",stack[i]);
            i--;
        }
    }    
}
int main(){
    int n;
    while(1){
        printf("\nEnter choice\n1. push\n2. pop\n3. display\n4. exit : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                push();
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