#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

void insert_end(int val){
    struct Node* newnode=malloc(sizeof(struct Node));
    newnode->data=val;newnode->next=NULL;
    if(!head){head=newnode;return;}
    struct Node* temp=head;
    while(temp->next)temp=temp->next;
    temp->next=newnode;
}

void delete_pos(int pos){
    if(!head)return;
    struct Node* temp=head;
    if(pos==0){head=head->next;free(temp);return;}
    for(int i=0;i<pos-1 && temp->next;i++)temp=temp->next;
    if(!temp->next)return;
    struct Node* del=temp->next;
    temp->next=del->next;
    free(del);
}

void display(){
    struct Node* temp=head;
    while(temp){printf("%d ",temp->data);temp=temp->next;}
    printf("\n");
}

int main(){
    insert_end(10);insert_end(20);insert_end(30);insert_end(40);
    delete_pos(2);
    display();
    return 0;
}
