#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void del(){

system("CLS");
   int c,n,ch,v1,v2,m;
   cout<<endl<<"Enter the number of elements for an array = ";
   cin>>c;
   int arr[c];

   cout<<endl<<"Enter any "<<c<<" values"<<endl;
   for(int i=0 ; i<c; i++){
    cout<<"Enter value for index "<<i<<" = ";
    cin>>arr[i];

   }
    cout<<endl;
    for(int j=0 ; j<c; j++){
    cout<<"index "<<j<<" = "<<arr[j]<<endl;

   }

   cout<<endl<<"Do you want to delete";
   cout<<endl<<"1. by value in array ";
   cout<<endl<<"2. by index in array ";
   cout<<endl<<" = ";
   cin>>ch;

   switch(ch){

     case 1:
         cout<<"Enter the value you want to delete = ";
         cin>>v1;
         for(int k=v1-1;k<c;k++){
              arr[k]=arr[k+1];
            }
           c--;
              cout<<endl;
              for(int m=0; m<c;m++){
                    cout<<"index "<<m<<" = "<<arr[m]<<endl;
         }


         break;

     case 2:
        cout<<"Enter the value you want to delete = ";
        cin>>v2;
        for(int i=0;i<c;i++){
                if(arr[i]==v2){
                    for(int k=v2-1;k<c;k++)
                        {
                     arr[k]=arr[k+1];
                        }
           c--;
        }
        }
         cout<<endl;
              for(int m=0; m<c;m++){
                    cout<<"index "<<m<<" = "<<arr[m]<<endl;
         }




       break;
   }





}

void rep(){

 system("CLS");
   int c2;
   cout<<endl<<"Enter the number of elements for an array = ";
   cin>>c2;
   int arr2[c2];

   cout<<endl<<"\nEnter any "<<c2<<" values"<<endl;
   for(int i=0 ; i<c2; i++){
    cout<<"Enter value for index "<<i<<" = ";
    cin>>arr2[i];
   }

   cout<<"\n Repeated values are ";
   for(int i=0 ; i<c2 ; i++){
    for(int j=i+1 ; j<c2 ; j++){
        if(arr2[i]==arr2[j]){
            cout<<"\n"<<arr2[i];
    }

    }

   }

}

void maxandmini(){
system("CLS");
   int arr3[20],c3,fm=0,sm=0,tm=0;


   for(int i=0;i<20;i++){
    cout<<"Enter value for index "<<i<<" = ";
    cin>>arr3[i];
   }

   for(int j=0;j<20;j++){
       if(fm<arr3[j]){
         tm=sm;
         sm=fm;
         fm=arr3[j];

       }
       else if(sm<arr3[j] && fm>arr3[j]){
        tm=sm;
        sm=arr3[j];

       }
       else if(tm<arr3[j] && sm>arr3[j]){
           tm=arr3[j];
       }
   }

   cout<<"\n 1st max value is = "<<fm;
   cout<<"\n 2nd max value is = "<<sm;
   cout<<"\n 3rd max value is = "<<tm;



 for(int j=0;j<20;j++){
       if(fm>arr3[j]){
         tm=sm;
         sm=fm;
         fm=arr3[j];

       }
       else if(sm>arr3[j] && fm<arr3[j]){
        tm=sm;
        sm=arr3[j];

       }
       else if(tm>arr3[j] && sm<arr3[j]){
           tm=arr3[j];
       }
   }



   cout<<"\n 1st min value is = "<<fm;
   cout<<"\n 2nd min value is = "<<sm;
   cout<<"\n 3rd min value is = "<<tm;




}






int main()
{

    //Login
    string user="";
    int pass;
    bool success=false;

   do{
    system("CLS");
    cout<< "\n\n\n\n\n\n\n\n   \t \t \t \t \t \t LOGIN"<< endl;
    cout<<endl<<"\t \t \t \t \t Username = ";
    cin>>user;
    cout<<endl<<"\t \t \t \t \t Password = ";
    cin>>pass;


    if(user=="Atif"||user=="atif" && pass==123){
        cout<<endl<<"\t \t \t \t \t Successfully Log in"<<endl;
        success=true;
    }
    else{
        cout<<endl<<"\t \t \t \t \t Invalid Username or Password";
         getch();

    }

   }while(success!=true);

        int cho;
   system("CLS");
   cout<<"Enter the program ";
   cout<<endl<<"1. Deletion ";
   cout<<endl<<"2. Repeated value ";
   cout<<endl<<"3. 3 max and 3 min ";
   cout<<endl;
   cin>>cho;
   switch(cho){
  case 1:
    del();
    break;

  case 2:
    rep();
    break;


  case 3:
    maxandmini();
    break;



   }

    return 0;
}
