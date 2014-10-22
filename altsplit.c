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


void altsplit(struct node* src,struct node** aref, struct node** bref) 
{
	int t=1;
	struct node* m= NULL;
	struct node* n= NULL;
	struct node* h=src;
	while(h!=0){
		t=h->data;
		if(t%2==0){
			movenode(&m,&h);}
		else
			if(h!=0)
				movenode(&n,&h);
	}
	*aref=m;

	*bref=n;
	//disp(aref);
}
main(){
	struct node* h;
	struct node* t;
	struct node* m;
	h=build1();
	disp(h);
	altsplit(h,&t,&m);
	disp(t);
	disp(m);
}
















