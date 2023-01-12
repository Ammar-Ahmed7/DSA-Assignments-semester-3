#include <iostream>
#include <conio.h>
using namespace std;

struct Queue{
   int a[40];
   int front=-1;
   int rear=-1;  
}Q;

void EnQ(int d){
  if(Q.rear==sizeof(Q.a)){
    cout<<"Queue is Full";
  }
  else if(Q.front==-1 && Q.rear==-1){
    Q.front=Q.rear=0;
    Q.a[Q.rear]=d;
  }
  else{
    Q.rear++;
    Q.a[Q.rear]=d;
  }

}


void DeQ(){
  if(Q.front==-1 && Q.rear==-1){
    cout<<"Queue is Empty";
  }
  else if(Q.front==Q.rear){
    Q.front=Q.rear=-1;
  }
  else{
    Q.front++;
  }

}

void Display(){
    if(Q.front==-1 && Q.rear==-1){
        cout<<"Queue is Empty";
    }
    else{
        for(int i=Q.front; i<=Q.rear; i++){
            cout<<Q.a[i]<<" ";
        }
    }
}


int main()
{
    int ch,d;
   while(true){ 
    system("CLS");
    cout<<"Enter your Options or press 4 or exit = ";
    cin>>ch;

    switch(ch){

     case 1:
     system("CLS");
     cout<<"Enter your Value = ";
     cin>>d;
     EnQ(d);
     break;


     case 2:
     DeQ();
     break;

     case 3:
     system("cls");
     Display();
     getch();
     break;
     
     case 4:
     exit(0);
     break;

    }
   }
    return 0;
}