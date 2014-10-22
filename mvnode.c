#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;};

struct node* build2(){
	struct node* head ;//=NULL;
	struct node* second ;//=NULL;
	struct node* third ;//=NULL;
	head =malloc(sizeof (struct node));
	second=malloc(sizeof (struct node));
	third=malloc(sizeof (struct node));
	struct node* fourth=malloc(sizeof(struct node));
	head->data=1;
	head->next=second;

	second->data=2;
	second->next=third;

	third->data=3;
	third->next=fourth;

	fourth->data=3;
	fourth->next=NULL;
	return head;
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
        head->data=4;
        head->next=second;

        second->data=5;
        second->next=third;

        third->data=6;
        third->next=fourth;

	fourth->data=3;
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
{	struct node* h=*src;
 	struct node* newNode = malloc(sizeof(struct node));
        newNode->data = h->data;
	free(h);
	*src=h->next;
        newNode->next = *dest;
        *dest = newNode;

}
main(){
int n;
struct node* h;
struct node* t;
struct node* m;
//h=build1();
h=NULL;
disp(h);
t=build2();
disp(t);
movenode(&h,&t);
disp(h);
disp(t);
movenode(&h,&t);
disp(h);
disp(t);



}
