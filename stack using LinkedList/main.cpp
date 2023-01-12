#include <iostream>

using namespace std;
struct linkedlist{
    int data;
    linkedlist *next;
}*top,*temp;
void push(){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    temp=new linkedlist;
    temp->data=data;
    temp->next=top;
    top=temp;
}
void pop(){
    if(top==NULL){
        cout<<"stack is empty"<<endl;
        return;
    }
    temp=top;
    top=top->next;
    delete(temp);
}
void printing(){
    linkedlist *current;
    current=top;
    if(current!=NULL){
    while(current->next!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<current->data;
    }
}
int main()
{
    int choice;
    cout<<"Enter 1 to push\nEnter 2 to pop from stack"<<endl;
    cin>>choice;
    while (choice==1||choice==2){
        if (choice==1){
            push();
            printing();
        }
        else{
            pop();
            printing();
        }
        cout<<"Enter 1 to push\nEnter 2 to pop from stack"<<endl;
    cin>>choice;

    }
    return 0;
}