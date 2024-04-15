#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *temp;
char count='1';

void ins_beg(struct node *new1);
void ins_specific(struct node *new1,int n);
void ins_end(struct node *new1);
void del_beg();
void del_specific(int n);
void del_end();
void traverse();

int main(){
	int choice, n;
	struct node *new1;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. ins_beg\n2. ins_specific\n3. ins_end\n4. del_beg\n5. del_specific\n6. del_end\n7. traverse\n8. exit: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
                    printf("\nenter the data: ");
					scanf("%d",&new1->data);
					new1->next = NULL;
					ins_beg(new1);
                    break;
            case 2:
                    new1 = (struct node*)malloc(sizeof(struct node));
                    printf("\nEnter n: ");
                    scanf("%d",&n);
					printf("\nenter the data: ");
					scanf("%d",&new1->data);
					new1->next = NULL;
                    ins_specific(new1,n);
                    break;
			case 3:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("\nenter the data: ");
					scanf("%d",&new1->data);
					new1->next = NULL;
					ins_end(new1);
					break;
			case 4:
					del_beg();
					break;
            case 5:
                    printf("\nEnter n: ");
                    scanf("%d",&n);
                    del_specific(n);
                    break;        
			case 6:
					del_end();
					break;
			case 7:
					traverse();
					break;
			default:
					exit(1);
		}
	}
}

void ins_beg(struct node *new1)
{
    temp=head;
    if(head==NULL)
    {
        head=new1;
        head->next=head;
    }
    else
    {
        while(temp->next!=head)
            temp=temp->next;
        new1->next=head;
        temp->next=new1;
        head=new1;    
    }
    count++;
}
void ins_specific(struct node *new1,int n)
{
    int i=1;
    temp=head;
    struct node *temp1=head;
    if(n<=count)
    {
        if(head==NULL)
        {
            head=new1;
            head->next=head;
        }
        else
        {
            temp1=temp1->next;
            while(i<n-1)
            {
                temp=temp->next;
                temp1=temp1->next;
            }
            temp->next=new1;
            new1->next=temp1;
        }
        count++;
    }
    else
        printf("\nInvalid n\n");    
}
void ins_end(struct node *new1)
{
    temp=head;
    if(head==NULL)
    {
        head=new1;
        head->next=head;
    }
    else
    {
        while(temp->next!=head)
            temp=temp->next;
        temp->next=new1;
        new1->next=head;    
    }
    count++;
}
void del_beg()
{
    struct node *temp1=head;
    temp=head;
    if(head==NULL)
        printf("No elements");
    else if(head->next==head){
        printf("Item deleted = %d",head->data);
        head=NULL;
        count--;
    }
    else
    {
        while(temp->next!=head)
            temp=temp->next;
        printf("Item deleted = %d",head->data);
        head=head->next;
        temp->next=head;
        free(temp1);
        temp1=NULL;    
        count--;
    }
}
void del_specific(int n)
{
    int i=1;
    temp=head;
    struct node *temp1=head;
    if(n<=count)
    {
        if(head==NULL)
            printf("No nodes to delete\n");
        else{
            temp1=temp->next;
            while(i<n-1)
            {
                temp=temp->next;
                temp1=temp1->next;
                i++;
            }    
            temp->next=temp1->next;
            printf("item deeted = %d",temp1->data);
            temp1->next=NULL;    
        }
        count--;
    }
    else
        printf("Numnber of nodes exceeded\n"); 
}
void del_end()
{
    struct node *temp1=head;
    temp=head;
    if(head==NULL)
        printf("No elements");
    else if(head->next==head)
    {
        printf("Item deleted = %d",head->data);
        head=NULL;
        free(temp);
        count--;
    }
    else
    {
        while(temp1->next!=head)
            temp1=temp1->next;
        while(temp->next!=temp1)
            temp=temp->next;
        temp1->next=NULL;
        temp->next=head;
        free(temp1);
        temp1=NULL;    
        count--;    
    }
}
void traverse()
{
    temp=head;
    if(temp==NULL)
        printf("No Data");
    else
    {
        do{
            printf("\t%d",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }    
}
