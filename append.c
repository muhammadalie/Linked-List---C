#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;};

struct node* build1(){
	struct node* head ;//=NULL;
	struct node* second ;//=NULL;
	struct node* third ;//=NULL;
	head =malloc(sizeof (struct node));
	second=malloc(sizeof (struct node));
	third=malloc(sizeof (struct node));
	head->data=2;
	head->next=second;

	second->data=5;
	second->next=third;

	third->data=1;
	third->next=NULL;
	return head;
}

struct node* build2(){
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
	printf("\n");
        while(n!=0){
                printf(" %d ",n->data);
                n=n->next;
        }
	printf("\n");

}

void append(struct node **aref,struct node** bref)
{
	struct node*a =*aref;
	struct node*b =*bref;
	if(a==NULL){
		*aref=malloc(sizeof(struct node));
		 struct node* h= *aref;
		h->data=b->data;
		h->next=b->next;
		}
	else{
		while(a->next!=NULL)
			a=a->next;
		a->next=b;
	}

}



main(){
struct node* h;
struct node* t;
h=build1();
t=build2();
append(&h,&t);
disp(h);

}
