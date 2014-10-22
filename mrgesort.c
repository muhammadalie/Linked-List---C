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

        second->data=1;
        second->next=third;

        third->data=0;
        third->next=fourth;

	fourth->data=2;
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


struct node* srtmrg(struct node* a,struct node* b)
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

void mrgesort(struct node** head)
{
	struct node* h=*head;
	struct node* a=NULL;
	struct node* b=NULL;
	if(h!=0){
		if(h->next==NULL)
			return ;
		split(&h,&a,&b);
		mrgesort(&a);
		mrgesort(&b);
		*head=srtmrg(a,b);
	}
}

main(){
	struct node* h;
	struct node* t;
	h=build1();
	//h=NULL;
	disp(h);
	mrgesort(&h);
	disp(h);
}
















