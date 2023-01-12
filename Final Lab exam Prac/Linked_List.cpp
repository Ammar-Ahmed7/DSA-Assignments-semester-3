#include <iostream>
#include <conio.h>
using namespace std;

struct Node{
  int data;
  Node *next;
  Node *prev;
};
Node *l,*start,*temp;

void insert(int d){
l=start;
if(start==NULL){
    start=new Node;
    start->data=d;
    start->next=NULL;
    start->prev=NULL;
}else
{
    while(l->next!=NULL){
        l=l->next;
    }
    if(l->next==NULL){
        temp=new Node;
        temp->data=d;
        temp->next=NULL;
        l->next=temp;
        temp->prev=l;
    }
}

}

 void del(int d){
   l=start;
   if(l->data==d){
    start=l->next;
    delete(l);
   }
    else{
      while(l->data!=d){
        temp=l;
        l=l->next;
      }
      if(l->data==d){
        temp->next=l->next;
        free(l);
        delete(l);
      }

    }
   }

void display(){
    l=start;
   while(l->next!=NULL){
    cout<<l->data<<" ";
    l=l->next;
   }
   if(l->next==NULL){
    cout<<l->data;
   }
}




int main()
{
    int ch;
    int d,e;
   while(true){ 
    system("CLS");
    cout<<"Enter your Option \n1.Insert at end \n2.Delete \n3.Display \n 4.Exit =  ";
    cin>>ch;

    switch(ch){

    case 1:
    system("CLS");
    cout<<"Enter value to insert = ";
    cin>>d;
    insert(d);
    break;


    case 2:
    system("CLS");
    cout<<"Enter value to delete = ";
    cin>>e;
    del(e);
    break;

    case 3:
    display();
    getch();
    break;

    case 4:
    exit(0);
    break;

    }
   }
    return 0;
}