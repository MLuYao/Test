#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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
    long long int a=9223372036854775807;
    char i='a';
    printf("%lld\n",a);
    printf("%hhd\n",i);
}
