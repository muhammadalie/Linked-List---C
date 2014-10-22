#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;};

void Push(struct node** headRef, int data) {
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = *headRef;
        *headRef = newNode;
}



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

        third->data=3;
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


struct node* srtins(struct node** head,int n)
{

        struct node* h=*head;

        if(h!=NULL){
                if(n<= h->data)
                        Push(&*head,n);
                else if(n>h->data){

                        while(h->next!=NULL&&n>(h->next->data) ){
                                h=h->next;
                        }
                        struct node* ali=malloc(sizeof(struct node));
                        ali->data=n;
                        ali->next=h->next;
                        h->next=ali;
                        ali->data=n;
                }
        }
        else{
                *head=malloc(sizeof(struct node));
                struct node* h= *head;
                h->data=n;
                h->next=NULL;
        }
}
struct node* mrgsrt(struct node* a,struct node* b)
{
	struct node* h=a;
	struct node* k=b;
	int t=0;
	struct node* m=NULL;
	while(h!=0){
		t=h->data;
		srtins(&m,t);
		h=h->next;
	}
	while(k!=0){
		t=k->data;
		srtins(&m,t);
		k=k->next;
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
	m=mrgsrt(h,t);
	disp(m);
	//disp(t);
	//disp(m);
}
















