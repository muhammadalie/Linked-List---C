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

        second->data=5;
        second->next=third;

        third->data=6;
        third->next=fourth;

	fourth->data=0;
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

        fourth->data=7;
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


struct node* reverse(struct node* a)
{
	struct node* h= a;
	struct node* m=NULL;
	while(h!=0){
		movenode(&m,&h);
	}
	return m;
}
main(){
	struct node* h;
	struct node* t;
	struct node* m;
	h=build1();
	//t=build2();
	disp(h);
	m=reverse(h);
	disp(m);
	//disp(t);
	//disp(m);
}
















