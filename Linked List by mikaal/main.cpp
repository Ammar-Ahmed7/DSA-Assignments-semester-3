#include <iostream>

using namespace std;
struct Node{
    int data;
    Node *next;
    };
struct Node *first,*temp,*current;
void delete_at_first(){
    temp=first;
    first=first->next;
    delete (temp);
}
void delete_at_last(){
    current=first;
    while(current->next!=NULL){
            temp=current;
            current=current->next;
        }
        temp->next=NULL;
    delete (current);
}
void create_at_last(){
    cout<<"Enter data";
    int d;
    cin>>d;
    current=first;
    temp=new Node;
    temp->data=d;
    temp->next=NULL;
    if(first==NULL){
        first=temp;
    }
    else{
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
    }
}
void create_at_first(){
    cout<<"Enter data"<<endl;
    int d;
    cin>>d;
    temp=new Node;
    temp->data=d;
    temp->next=first;
    first=temp;
}
void delbypos(){
    cout<<"Enter position"<<endl;
    int pos=0;
    cin>>pos;
    if(pos==0){
        delete_at_first();
        return;
    }
    current=first;
    Node *prev=current;
    for(int i=0;i<pos;i++){
        prev=current;
        if(current==NULL){
        cout<<"Position never exist"<<endl;
        return;
    }
        current=current->next;
    }
    prev->next=current->next;
    delete(current);
}
void insertbypos(){
    cout<<"Enter position"<<endl;
    int pos=0;
    cin>>pos;
    if(pos==0){
        create_at_first();
        return;
    }
    current=first;
    Node *prev=current;
    for(int i=0;i<pos;i++){
        prev=current;
        if(current==NULL){
        cout<<"Position never exist"<<endl;
        return;
    }
        current=current->next;
    }

    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    temp=new Node;
    temp->data=data;
    if(current->next==NULL)
        temp->next=NULL;
    temp->next=current;
    prev->next=temp;
    }
void printing(){
    current=first;
    while(current->next!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<current->data;
}

int main()
{
    int x=0;
    int choice;
        cout<<"Enter 1 for insert at last\nEnter 2 to add at first\nEnter 3 to Delete at first\nEnter 4 to delete at last\nEnter 5 to insert by position\nEnter 6 for delete by position"<<endl;
        cin>>choice;
    while(choice>=1&&choice<=6){

        if(choice==1){
            create_at_last();
        }
        else if(choice==2){
            create_at_first();
        }
        else if (choice==3){
            delete_at_first();
        }
        else if (choice==4){
            delete_at_last();
        }

        else if (choice==5){
            insertbypos();
        }
        else if (choice==6){
            delbypos();
        }
        cout<<endl;
        printing();
        cout<<endl;
        cout<<"Enter 1 for insert at last\nEnter 2 to add at first\nEnter 3 to Delete at first\nEnter 4 to delete at last\nEnter 5 to insert by position\nEnter 6 for delete by position"<<endl;
        cin>>choice;
    }
    return 0;
}