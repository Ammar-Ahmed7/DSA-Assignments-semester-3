#include <iostream>
#include <conio.h>

using namespace std;

struct Queue{
    
    int a[50];
    int front=-1;
    int rear=-1;
}Q;

void EnQ(int x){
    if(Q.rear==sizeof(Q.a)){
      cout<<"OVERFLOW";
    }
    else if(Q.rear==-1 && Q.front==-1){
       Q.rear=Q.front=0;
       Q.a[Q.rear]=x;
    }
    else if((Q.rear+1)%sizeof(Q.a)==Q.front){
      cout<<"Queue is FUll";
    }
   else{
    Q.rear=(Q.rear+1)%sizeof(Q.a);
    Q.a[Q.rear]=x; 
   }
}

void DeQ(){
if(Q.rear==-1 && Q.front==-1){
    cout<<"UNDERFLOW";
}
else if(Q.front==Q.rear)
{
    Q.front=Q.rear=-1;
}
else{
    Q.front ++;
}
}

void display(){
if(Q.rear==-1 && Q.front==-1){
    cout<<"EMPTY";
}
else{
   for(int i=Q.front; i<Q.rear+1; i++){
    cout<<Q.a[i]<<" ";
   }
}
}

void peek(){
 if(Q.rear==-1 && Q.front==-1){
    cout<<"EMPTY";
}
 else{
    cout<<'\n'<<Q.a[Q.front];
 }
}

int main()
{
    int ch,x;
  while (true)
  {
    system("CLS");
    cout<<"Enter \n1.Insert \n2.Delete \n3.To Peek \n4.Display \n5.Exit = ";
    cin>>ch;
    switch (ch)
    {
    case 1:
        system("cls");
        cout<<"Enter the value you want to insert = ";
        cin>>x;
        EnQ(x);
        break;
    
    case 2:
       DeQ();
        break;

    case 3:
       peek();
       getch();
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