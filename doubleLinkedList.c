#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *temp=NULL;
int count=0;
void ins_beg(struct node*);
void ins_end(struct node*);
void del_beg();
void del_end();
void traverse();
void traverse2();
void ins_specific(struct node *new1,int n){
    int i=1;
    temp=head;
    struct node *temp1=head;
    if(n<=count)
    {
        if(head==NULL)
            head=new1;
        else{
            if(n==1){
                ins_beg(new1);
            }
            else{
                temp1=temp->next;
                while(i<n-1)
                {
                    temp=temp->next;
                    temp1=temp1->next;
                    i++;
                }    
                new1->next=temp1;
                temp1->prev=new1;
                temp->next=new1; 
                new1->prev=temp;   
            }
        } 
        count+=1; 
    }
    else if(n==count+1){
        ins_end(new1);
    }
    else
        printf("Numnber of nodes exceeded\n");        
}

void del_specific(int n){
    int i=1;
    temp=head;
    struct node *temp1=head;
    struct node *temp2=head;
    if(n<count){
        if(head==NULL)
            printf("UNDERFLOW");
        else{
            temp1=temp1->next;
            while(i<n){
                temp1=temp1->next;
                i++;
            }
            temp=temp1->prev;
            temp2=temp->prev;
            temp2->next=temp1;
            temp1->prev=temp2;
            free(temp);
            temp=NULL;
            count--;
        }   
    }
    else if(n==count){
        del_end();
    }
    else{
        printf("Index Out of order");
    }
}


int main(){
	int choice, n;
	struct node *new1;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. ins_beg\n2. ins_end\n3. del_beg\n4. del_end\n5. traverse\n6. traverse2\n7. ins specific\n8. del specific\n9. exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					ins_beg(new1);
					break;
			case 2:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					ins_end(new1);
					break;
			case 3:
					del_beg();
					break;
			case 4:
					del_end();
					break;
			case 5: 
					traverse();
					break;
            case 6:
                    traverse2();
                    break;  
            case 7:
                    printf("Enter value of n: ");
                    scanf("%d",&n);
                    new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
                    ins_specific(new1,n);
                    break;
			case 8:
                    printf("Enter value of n: ");
                    scanf("%d",&n);
                    del_specific(n);
                    break;			
            default:
					exit(1);
		}
	}
}
void ins_beg(struct node *new1){
    if(head==NULL)
        head=new1;
    else{
        head->prev=new1;
        new1->next=head;
        head=new1;
    }
    count++;    
}
void ins_end(struct node *new1){
    struct node *temp=head;
    if(head==NULL)
        head=new1;
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new1;
        new1->prev=temp;    
    }
    count++;    
}
void del_beg(){
    struct node *temp=head;
    if(head==NULL)
        printf("No item");
    else{
        head=head->next;
        head->prev=NULL;
        free(temp);
        temp=NULL;
        count--;
    }     
}
void del_end(){
    struct node *temp=head;
    struct node *temp1=head;
    if(head==NULL)
        printf("No item");
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp1=temp->prev;
        temp1->next=NULL;
        temp->prev=NULL;
        free(temp);
        temp=NULL; 
        count--;   
    }    
}
void traverse(){
    struct node *temp = head;
	if(head == NULL)
	    printf("no item to traverse\n");
    else{    
	    while(temp != NULL){
		    printf("%d\t",temp->data);
		    temp = temp->next;
	    }
    }
}
void traverse2(){
    struct node *temp=head;
    if(head == NULL)
		printf("no elements in the list\n");    
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->prev;
        }    
    }    
}
