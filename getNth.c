#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* build(){
	struct node* head ;//=NULL;
	struct node* second ;//=NULL;
	struct node* third ;//=NULL;
	head =malloc(sizeof (struct node));
	second=malloc(sizeof (struct node));
	third=malloc(sizeof (struct node));
	head->data=5;
	head->next=second;

	second->data=2;
	second->next=third;

	third->data=9;
	third->next=NULL;
	return head;
}

int getNth(struct node* head,int t){
	int l=0;
	struct node* n=head;
	while(t>0){
		n=n->next;
		t--;
	}
	//printf("%d",n->data);
	return n->data;
}
main(){
	int t;
	struct node* h;
	h=build();
	t=getNth(h,2);
	printf("%d",t);
}
