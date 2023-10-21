#include <stdio.h>
#include <stdlib.h>
struct  node
{
    int data;
    struct node *next;
};
void init_node(struct node* p){
    p->data=0;
    p->next=NULL;
}
void insert_node(struct node* p,int data){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=p->next;
    p->next=temp;
}
void print_list(struct node* p){
    p=p->next;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}
void main()
{
    struct node head;
    init_node(&head);
    insert_node(&head,10);
    insert_node(&head,20);
    insert_node(&head,30);
    print_list(&head);
    printf("Hello World!");
}
