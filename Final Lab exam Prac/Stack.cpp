#include <iostream>
#include <conio.h>
using namespace std;

struct Stk
{
    int a[10];
    int top;
}s;


void push(int d){
if(s.top>=9){
  cout<<"OVERFLOW";
}
 else{
    s.top++;
    s.a[s.top]=d;
 }
}



void pop(){
if (s.top<0){
    cout<<"UNDERFLOW";
}
else{
    s.top--;
}

}


void display(){
 for(int i=s.top ; i>=0 ; i--){
    cout<<endl<<s.a[i];
 }
}
int main()
{
    s.top=-1;
    int ch,d;
    
 while(ch!=-1){  
    system("CLS");
   cout<<"Enter options = ";
   cin>>ch;
 
   switch(ch){
    case 1:
    system("CLS");
    cout<<"Enter value = ";
    cin>>d;
    push(d);
    break;


    case 2:
    pop();
    break;



    case 3:
    system("CLS");
    display();
    getch();
    break;

   }
 }  
    return 0;
}