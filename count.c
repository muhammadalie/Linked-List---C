#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;};

struct node* build(){
	struct node* head ;//=NULL;
	struct node* second ;//=NULL;
	struct node* third ;//=NULL;
	head =malloc(sizeof (struct node));
	second=malloc(sizeof (struct node));
	third=malloc(sizeof (struct node));
	head->data=2;
	head->next=second;

	second->data=2;
	second->next=third;

	third->data=2;
	third->next=NULL;
	return head;
}


int counts(struct node* head,int t){
	int count=0;
	struct node* n=head;
	while(n!=0){
		if((n->data)==t)
			count++;
		//printf("%d",n->data);
		n=n->next;
	}
	return count;
}
main(){
int t;
struct node* h;
h=build();
t=counts(h,2);
printf("%d",t);
}
