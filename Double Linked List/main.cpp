#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
struct  Node{
    int data;
    Node *next;
    Node *prev;
};
Node *start,*l ,*temp;

void insert(){
    int data;
    cout << "Enter the data which you want to insert : ";
    cin    >> data;
    l=start;
    if(start==NULL){
        start = new Node;
        start -> data=data;
        start -> next =NULL;
        start -> prev=NULL;
    }else {
        while (l->next != NULL) {
            l = l->next;
        }
        if (l->next == NULL) {
            temp = new Node;
            temp->data = data;
            temp->next = NULL;
            l->next = temp;
            temp -> prev=l;
        }
    }
}

void insertAtSpecificLocation(){
    int data,nodeData;
    cout << "Enter the location where you want to insert your data : ";
    cin    >> nodeData;
    cout << "Enter the data which you want to insert : ";
    cin    >> data;
    l=start;
    while(l -> data != nodeData){
        l=l->next;
    }
    if (l -> data == nodeData)
    {
        temp= new Node;
        temp -> data = data;
        temp -> next=l -> next;
        l -> next= temp;
        temp->prev=l;
    }
}

void deletee(){
    int delData;
    cout << "Enter the location where you want to delete your data : ";
    cin    >> delData;
    l=start;
    if(l -> data==delData){
        start= l -> next;
        delete(l);
    }else{
        while (l -> data!=delData){
            l=temp;
            l=l -> next;
        }
        if(l -> data==delData){
            temp -> next = l-> next;
            delete(l);
        }
    }
}

void display(){
    l=start;
    while (l -> next!=NULL){
        cout << l->data<<endl;
        l=l -> next;
    }
    if(l -> next==NULL){
        cout << l->data<<endl;
    }
}
int main() {
    int choice;
    while (1){
        system("cls");
        cout << "Press 1 to insert : " <<endl;
        cout << "Press 2 to insert at specific location : " << endl;
        cout << "Press 3 to delete : "<<endl;
        cout << "Press 4 to display the linked list : "<<endl;
        cout << "Press 5 to exit : "<<endl;
        cout << "Enter your choice : ";
        cin    >> choice;
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                insertAtSpecificLocation();
                main();
                break;
            case 3:
                deletee();
                break;
            case 4:
                display();
                getch();
                break;
            case 5:
                exit(0);
                break;
        }
    }
    return 0;
}