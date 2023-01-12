#include <iostream>
using namespace std;

class Node{
   public:
   int data;
   Node *next;

};
Node *start,*l,*temp;

void Cinsert(int d){
 l=start;
 if(start==NULL){
  start=new Node;
  start->data=d;
  start->next=NULL;
 }
 else{
    while(l->next!=NULL){
        l=l->next;
    }
    if(l->next==NULL){
        temp=new Node;
        temp->data=d;
        temp->next=NULL;
        l->next=temp;
    }
    while(temp->next!=NULL){
        l=l->next;
    }
    if(temp->next==NULL){
        temp=new Node;
        temp->data=d;
        temp->next=start;
        l->next=temp; 
    }

 } 



}
int main()
{
    return 0;
}