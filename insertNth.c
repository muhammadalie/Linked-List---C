#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;};

void ins(struct node* headRef,int intex,  int data) {
	int m=0;
	struct node* newNode = malloc(sizeof(struct node));
	struct node* n=headRef;
	struct node* t;
	while(intex>1){
		n=n->next;
		intex--;

	}
	//ins(n,intex--,data);
	t=n->next;
	n->next=newNode;
	newNode->data = data;
	newNode->next =t ;
}

struct node* build(){
	struct node* head ;//=NULL;
	struct node* second ;//=NULL;
	struct node* third ;//=NULL;
	head =malloc(sizeof (struct node));
	second=malloc(sizeof (struct node));
	third=malloc(sizeof (struct node));
	head->data=5;
	head->next=second;

	second->data=1;
	second->next=third;

	third->data=9;
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
	disp(h);
	printf("\n");
	ins(h,1,3);
	disp(h);
	printf("\n");
	ins(h,2,5);
	disp(h);
}
