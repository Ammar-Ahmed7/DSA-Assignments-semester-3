#include <iostream>
#include <conio.h>
using namespace std;

struct Node{
  int data;
  Node *next;
}*head,*current,*last,*temp,*Previous;

void insert(int d){
    if(head==NULL){
       head=new Node;
       head->data=d;
       head->next=NULL;
        last=head;
    }
    else{
        Previous=last;
     temp=new Node;
     temp->data =d;
     temp->next=NULL;
     last->next =temp;
     last=temp;
    }

}

void del(){
   
    Previous->next=NULL;
    delete(last);
}

void display(){
    current=head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current=current->next;
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