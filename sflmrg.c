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
        third->next=NULL;

	//fourth->data=5;
	//fourth->next=NULL;
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


struct node* sflmrg(struct node* a,struct node* b)
{
	struct node* h= a;
	struct node* t= b;
	//struct node* m=NULL;
	struct node *m=malloc(sizeof(struct node));
	struct node *k=m;
	while(h!=0||t!=0){
		if(h!=0){
		//m->next=malloc(sizeof(struct node));
		k->data=h->data;
		h=h->next;
		//k=k->next;
		if(t!=0||h!=0)
		k=k->next=malloc(sizeof(struct node));}
		if(t!=0){
		k->data=t->data;
		t=t->next;
		//if(t!=NULL)
		if(h!=0||t!=0)//||h!=0)
		k=k->next=malloc(sizeof(struct node)) ;}
		//m->next=malloc(sizeof(struct node));
		//m->next->data=t->data;
		//t=t->next;
		//movenode(&m,&h);
		//movenode(&m,&t);
	}
	return m;
}

main(){
	struct node* h;
	struct node* t;
	struct node* m;
	h=build1();
	t=build2();
	disp(h);
	disp(t);
	m=sflmrg(h,t);
	disp(m);
	//disp(t);
	//disp(m);
}
















