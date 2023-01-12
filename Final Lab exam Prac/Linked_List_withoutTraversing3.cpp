#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node *l, *temp, *start;
void insert(int d)
{
    temp = new Node();
    temp->data = d;
    temp ->next = start;
    start = temp;
}
void del()
{
    start=temp->next;
}
void display()
{
    l = start;
    while(l->next!=NULL)
    {
        cout<<l->data<<"\t";
        l=l->next;
    }
    cout<<l->data<<"\t";


}
int main () 
{
    insert(5);
    insert(8);
    insert(4);
    insert(3);
    insert(2);
    del();
    display();

}