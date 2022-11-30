#include <iostream>

using namespace std;

/*int dep(int ac){

 int de;

        cout<<"Enter the amount you want to deposit = ";
        cin>>de;
        while(de<0){
           cout<<"Deposit cannot be negative"<<endl;
        cout<<"Enter the amount you want to deposit = ";
        cin>>de;

        }
        ac+=de;
        return ac;
         }


int wit(int ac){

 int wi;

        cout<<"Enter the amount you want to withdraw = ";
        cin>>wi;
        ac-=wi;
        return ac;
         }





int main()
{
    int acc1,acc2,acc3,acc4,op;

    cout << "Opening balance 1 = ";
    cin>>acc1;

    cout << "Opening balance 2 = ";
    cin>>acc2;

    cout << "Opening balance 3 = ";
    cin>>acc3;

    cout << "Opening balance 4 = ";
    cin>>acc4;
do{
    cout<<endl<<"Enter 1 to Deposit or 2 to withdraw or -1 to exit = ";
    cin>>op;

    switch(op){

     case 1:
        int ch;
         for(int i=1;i<=4;i++){
         cout<<"Press "<<i<<" for op "<<i<<endl;
         }
         cin>>ch;
        switch(ch){

        case 1:
            acc1=dep(acc1);
            cout<<"Your amount is = "<<acc1;
        break;


         case 2:
            acc2=dep(acc2);
             cout<<"Your amount is = "<<acc2;
        break;


         case 3:
            acc3=dep(acc3);
             cout<<"Your amount is = "<<acc3;
        break;


         case 4:
           acc4= dep(acc4);
             cout<<"Your amount is = "<<acc4;
        break;

        }

       break;

     case 2:
         int ch2;
         for(int i=1;i<=4;i++){
         cout<<"Press "<<i<<" for op "<<i<<endl;
         }
         cin>>ch2;
           switch(ch2){

        case 1:
           acc1= wit(acc1);
             cout<<"Your amount is = "<<acc1;
        break;


         case 2:
           acc2= wit(acc2);
             cout<<"Your amount is = "<<acc2;
        break;


         case 3:
           acc3= wit(acc3);
             cout<<"Your amount is = "<<acc3;
        break;


         case 4:
           acc4= wit(acc4);
             cout<<"Your amount is = "<<acc4;
        break;

        }

        break;

    }
   }while(op!=-1);

    return 0;
}*/

int main(){


 int id1,id2,p1,p2,s1,s2;
 string n1,n2;

 cout<<"Book Inventory"<<endl;

 cout<<"Enter ID of 1st Book = ";
 cin>>id1;

 cout<<endl<<"Enter name of 1st book = ";
 cin>>n1;

 cout<<endl<<"Enter price of 1st book = ";
 cin>>p1;

 cout<<endl<<"Enter stock of 1st book = ";
 cin>>s1;




  cout<<"Enter ID of 2nd Book";
 cin>>id1;

 cout<<endl<<"Enter name of 2nd book = ";
 cin>>n1;

 cout<<endl<<"Enter price of 2nd book = ";
 cin>>p1;

 cout<<endl<<"Enter stock of 2nd book = ";
 cin>>s1;

}


