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
	head->data=2;
	head->next=second;

	second->data=5;
	second->next=third;

	third->data=1;
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



int count(struct node* head)
{
	int count=0;
	struct node* h=head;
	while(h!=NULL){
		count++;
		h=h->next;
	}
	return count;
}
void split(struct node** head,struct node** front,struct node** back)
{
	int  x,y,t= count(*head);
	if(t%2==0) x=y=t/2;
	else x=t/2+1;
	*front=malloc(sizeof(struct node));
	*back=malloc(sizeof(struct node));
	struct node* h=*head;
	struct node* f=*front;
	struct node* b=*back;
	while(h!=NULL&&x>0){
		f->data=h->data;
		if(x>1)
		f=f->next=malloc(sizeof(struct node));
		h=h->next;
		x--;
	}
	while(h!=0){
		b->data=h->data;
		if(h->next!=NULL)
		b->next=malloc(sizeof(struct node));
		b=b->next;
		h=h->next;
	}
}

main(){
	int n;
	struct node* h;
	struct node* t;
	struct node* m;
	h=build2();
	split(&h,&t,&m);
	disp(t);
	disp(m);
}
