#include <iostream>
#include <conio.h>
using namespace std;



struct stk{

  string a;
  int top;

}s;

void insert(char x){
if(s.top>22){
    cout<<"Overflow";
}
else{
  s.top++;
  s.a[s.top]=x;
}
}

void display(){

for(int i=s.top; i>=0; i--){
    if((s.a[i]=='{'&& s.a[i-1]=='{')||(s.a[i]=='}'&& s.a[i-1]=='}')||(s.a[i]=='['&& s.a[i-1]=='[')||(s.a[i]==']'&& s.a[i-1]==']')||(s.a[i]=='('&& s.a[i-1]=='(')||(s.a[i]==')'&& s.a[i-1]==')')){
    cout<<'\n'<<s.a[i];
    }
}


}

void increaseOrdecrease(int a[]){
    int val;
 for(int i=0;i<12;i++){
      if(a[i]<a[i+1]<a[i+2]){
       cout<<"\n"<<a[i]<<" increasing";
    }
       if(a[i]>a[i+1]>a[i+2]){
        cout<<"\n"<<a[i]<<" decreasing";
       }

    }
 }





int main()
{
    s.top=-1;
    int a[12]={1,2,3,9,8,7,10,11,12,6,5,4};
   // increaseOrdecrease(a);
    int ch;
    char v;
   while(true){
    system("CLS");
     cout<<"Enter \n 1.Insert Character \n 2.Display \n 3.Exit = ";
    cin>>ch;
    switch(ch){
        case 1:
        while(true){
          system("CLS");
        cout<<"\n Enter Character or press ! to stop = ";
        cin>>v;
        if(v=='!'){
            break;
        }
        else{
        insert(v);
        }
        }
        break;

        case 2:
        display();
        getch();
        break;

        case 3:
        exit(0);
        break;

    }
    
   }   
   
    return 0;
}