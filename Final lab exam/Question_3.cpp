#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};
Node * start,* l,* temp;

void insertatEnd(int d){
  l=start;
  if
  (start==NULL){
    start=new Node;
    start->data=d;
    start->next=NULL;
  }

  else
  {

   while(l->next!=NULL){
    l=l->next;
 }

   if (l->next==NULL){
    temp=new Node;
    temp->data=d;
    temp->next=NULL;
    l->next=temp;
  }

  }


}

void deleteAfter(Node* current) {
    Node* temp = current->next;
    current->next = temp->next;
    temp->next->prev = current;
    delete temp;
}

void printing(){
    l=start;
    if(start==NULL){
   cout<<"Empty";
    }
  while(l->next!=NULL){
    cout<<l->data;
    l=l->next;
  }
  if(l->next==NULL){
    cout<<l->data;
  }
   }


int main() {
int ch,d;
while(true){
   system("cls"); 
  cout<<"Enter option \n1.Insert \n2.Delete= ";
  cin>>ch;

  switch(ch){

    case 1:
    system("cls");
    cout<<"Enter value you want to insert only 5 values = ";
    cin>>d;
    insert(d);
    break;

    case 2:
    Node* head = new Node;
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;

    Node* current = head;
    for (int i = 1; i < 5; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->prev = current;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    deleteAfter(current);

    current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    break;
  }

  case 3:
  display();
  break;
}
    return 0;
}