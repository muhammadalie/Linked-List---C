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

struct node* build(){
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

//      return count;
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


struct node* insrt(struct node* head)
{
	struct node* h=head;
	struct node* newnode=malloc(sizeof(struct node));
	newnode=NULL;
	while(h !=NULL){
		//h=h->next;
		srtins(&newnode,h->data);
		//n->next;
		h=h->next;
		//disp(ne);
	}
	disp(newnode);
}



main(){
int t;
struct node* h;
h=build();
disp(h);
insrt(h);
}
