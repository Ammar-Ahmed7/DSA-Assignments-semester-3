#include <iostream>

using namespace std;

struct stk{

int a[10];
int top;
}s;




void push(char x){

if(s.top>=9){
  cout<<"\nStack is full";
}else{
    s.top++;
s.a[s.top]=x;
}

}

void pop(){
  if(s.top==-1){
    cout<<"\nStack is empty";
  }else{
s.top--;
  }

}

void display(){

for(int i=s.top ;i>=0; i--)
    {
    cout<<endl<<s.a[i]<<endl;
}

}

int main()
{
    int x,ch;
    s.top=-1;

   do{
    cout<<"\n 1.Push \n 2.Pop \n 3.Display\n 4.Exit \n";
    cin>>ch;

    switch(ch){
  case 1:
   do{ cout << "\nEnter value or press -1 to end " << endl;
    cin>>x;
    if(x==-1){
       break;
    }
    push(x);
   }while(x!=-1);
     break;

  case 2:
     pop();
     break;


  case 3:
    display();
     break;

  case 4:
    exit(0);
    break;
    }
  }while(ch==1||ch==2||ch==3);

    return 0;
}
