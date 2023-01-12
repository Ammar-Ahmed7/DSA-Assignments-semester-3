#include <iostream>
#include <conio.h>
using namespace std;

struct Node{
  int data;
  Node *next;
};
Node *l,*start,*temp,*secondlast;

void insert(int d){
if(start==NULL){
    start=new Node;
    start->data=d;
    start->next=NULL;
  //  l=start;
   
   
}else
{
   // while(l->next!=NULL){
   //     l=l->next;
    }
    if(l->next==NULL){
        secondlast=l;

        temp=new Node;
        temp->data=d;
        temp->next=NULL;
        l->next=temp;
        l=temp;
      
    }
}



 void del(){
     secondlast->next=NULL;
     free(l);
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
   // cout<<"Enter value to delete = ";
   // cin>>e;
    del();
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