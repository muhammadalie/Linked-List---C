#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;};

struct node* build1(){
        struct node* head ;//=NULL;
        struct node* second ;//=NULL;
        struct node* third ;//=NULL;
	struct node* fourth;

        head =malloc(sizeof (struct node));
        second=malloc(sizeof (struct node));
        third=malloc(sizeof (struct node));
	fourth=malloc(sizeof(struct node));
        head->data=2;
        head->next=second;

        second->data=3;
        second->next=third;

        third->data=5;
        third->next=fourth;

	fourth->data=10;
	fourth->next=NULL;
	return head;
}
struct node* build2(){
        struct node* head ;//=NULL;
        struct node* second ;//=NULL;
        struct node* third ;//=NULL;
        struct node* fourth;

        head =malloc(sizeof (struct node));
        second=malloc(sizeof (struct node));
        third=malloc(sizeof (struct node));
        fourth=malloc(sizeof(struct node));
        head->data=1;
        head->next=second;

        second->data=3;
        second->next=third;

        third->data=8;
        third->next=fourth;

        fourth->data=9;
        fourth->next=NULL;
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

void movenode(struct node** dest,struct node** src)
{       struct node* h=*src;
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = h->data;
        free(h);
        *src=h->next;
        newNode->next = *dest;
        *dest = newNode;

}

struct node* mrgsrt(struct node* a,struct node* b)
{
	struct node* h=a;
	struct node* k=b;
	struct node* m=NULL;
	struct node* t=NULL;
	while(h!=0&&k!=0){
		if(h->data < k->data){
			movenode(&m,&h);}
		else {
			movenode(&m,&k);}
	}
	while(k!=0)
	{
		movenode(&m,&k);
	}
	while(h!=0)
	{
		movenode(&m,&h);
	}
	while(m!=0)
		movenode(&t,&m);
	return t;
}


main(){
	struct node* h;
	struct node* t;
	struct node* m;
	h=build1();
	t=build2();
	disp(h);
	disp(t);
	m=mrgsrt(h,t);
	disp(m);
}
















