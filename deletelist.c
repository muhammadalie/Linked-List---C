#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;};

struct node* build(){
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

int length(struct node* head){
	int count =0;
        struct node* n=head;
        while(n!=0){
		count++;
                n=n->next;
        }
      return count;
}

void disp(struct node* head){
	int c=length(head);
        struct node* n=head;
        while(c>0){
                printf("%d\n",n->data);
                n=n->next;
		c--;
        }
}


void deletelist(struct node** head){
	int c=length(*head);
	struct node* n=*head;
	while(c>0){
		free(n);
		n->data=0;
		n=n->next;
		c--;
	}
}
main(){
	int t;
	struct node* h;
	h=build();
	disp(h);
	printf("\n");
	deletelist(&h);
	disp(h);
}
