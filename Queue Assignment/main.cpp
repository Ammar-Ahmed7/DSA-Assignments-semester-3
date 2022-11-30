#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int a[5];
int front=0;
int back=0;


void EnQ(int x){
if((back>4) && (front==back)){
    cout<<"UnderFlow";
}
else
{
    a[back]=x;
    back++;
}

}


void DeQ(){
if(front<0){
    cout<<"OverFlow";
}
else
{
    front++;
    cout<<"First value has been deleted !!";
    Sleep(1000);
}


}

void display(){
 cout<<endl;

for(int i = front; i<back;i++){
    cout<<a[i]<<"\t";
}
getche();
}

void CEnQ(int x){


 if((front==0&&back==4)||back+1==front){
    cout<<"Queue is full";
 }
 if(a[0]=='\0'){
 for(int i = 0; a[i]!='\0'; i++){
    a[i]=x;
 }


 }
 else
 {
    if(back>4&&front!=0){
        a[back]=x;
    back++;
    }
    else{
    a[back]=x;
    back++;
    
    }
 }


}

 void CDeQ(){

if(front<0){
    cout<<"OverFlow";
  }
else
{
    front++;
    cout<<"First value has been deleted !!";
    Sleep(1000);
}

 }

 void Cdisplay(){
 cout<<endl;
 

 for(int i = 0; i<back; i++){
    cout<<a[i]<<"\t";
 }


getche(); 
 }





int main()
{

    int ch,x,cho;
   while(true){
    system("cls");
    cout << " Enter the 1,2,3 or 4" << endl;
    cout<<"1.Liner Queue\n2.Circular Queue\n3.Priority Queue\n4.Queue Game\n5.Exit\n = ";
     cin>>ch;
   if(ch!=1 && ch!=2 && ch!=3 && ch!=4 && ch!=5){
        cout<<"\n\n\t Invalid input!";
        Sleep(500);
        system("CLS");

        cin.clear();
        cin.ignore();

        main();
    }

    switch(ch){

    case 1:
     while(cho!=4)
     {

       system("CLS");
        cout<<" Chose your option \n1.Insert \n2.Delete \n3.Display \n4.Go to Previous Options \n =  ";
        cin>>cho;

        while(cho!=1 && cho!=2 && cho!=3 && cho!=4){
        cout<<"\n\n\t Invalid input!";
        Sleep(500);
        system("CLS");

        cin.clear();
        cin.ignore();

         cout<<" Chose your option \n1.Insert \n2.Delete \n3.Display \n4.Go to Previous Options \n = ";
        cin>>cho;

        }

        switch(cho){


     case 1:

        system("CLS");
         cout<<"Enter the value you want to insert = ";
         cin>>x;
       EnQ(x);

       break;

     case 2:
         DeQ();
         break;

     case 3:
        display();
        break;

     case 4:
        break;

        }
     }
    break;

    case 2:
    while(cho!=4)
     {

       system("CLS");
        cout<<" Chose your option \n1.Insert \n2.Delete \n3.Display \n4.Go to Previous Options \n =  ";
        cin>>cho;

        while(cho!=1 && cho!=2 && cho!=3 && cho!=4){
        cout<<"\n\n\t Invalid input!";
        Sleep(500);
        system("CLS");

        cin.clear();
        cin.ignore();

         cout<<" Chose your option \n1.Insert \n2.Delete \n3.Display \n4.Go to Previous Options \n = ";
        cin>>cho;

        }
         switch(cho){


     case 1:

        system("CLS");
         cout<<"Enter the value you want to insert = ";
         cin>>x;
       CEnQ(x);

       break;

     case 2:
         CDeQ();
         break;

     case 3:
        Cdisplay();
        break;

     case 4:
        break;

        }
      }
    
     break;

    case 3:
    break;

    case 4:
    break;

    case 5:
        exit(0);
    break;

    }
  }
    return 0;
}
