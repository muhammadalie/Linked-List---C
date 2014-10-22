#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;};

int Pop(struct node** headRef) {
	struct node* newNode=*headRef ;
	if(newNode!=NULL){
		int n=newNode->data;
		free(*headRef);
		*headRef=newNode->next;
		return n;
	}
	else return 0;
}

struct node* build(){
	struct node* head ;//=NULL;
	struct node* second ;//=NULL;
	struct node* third ;//=NULL;
	head =malloc(sizeof (struct node));
	second=malloc(sizeof (struct node));
	third=malloc(sizeof (struct node));
	head->data=1;
	head->next=second;

	second->data=2;
	second->next=third;

	third->data=3;
	third->next=NULL;
	return head;
}


void disp(struct node* head){
        struct node* n=head;
        while(n!=0){
                printf("%d",n->data);
                n=n->next;
        }
//      return count;
}


main(){
	int t;
	struct node* h;
	h=build();
	disp(h);
	printf("\n");

	int a=Pop(&h);
	disp(h);
	printf("\t a= %d\n",a);

	Pop(&h);
	disp(h);
	printf("\n");

	Pop(&h);
	disp(h); 
	printf("\n");

	Pop(&h);
	disp(h); 
}
