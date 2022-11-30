#include <iostream>

using namespace std;

int main()
{
   int a,sum=0,avg;
   /*for(int i=1;i<=4;i++){
        cout<<endl<<"Student no. "<< i;
    for(int j=1;j<=4;j++){
        cout<<endl<<" enter your marks of " <<j<< " subject = ";
        cin>>a;
        sum=sum+a;
    }

   }
   avg=sum/16;
   cout<<endl<<"The average is = "<<avg;*/

   int age,mini=10000,maxi=0;
   for(int i=1;i<=10;i++){
    cout<<"Enter "<<i<<" age = ";
    cin>>age;
     if(maxi<=age){
        maxi=age;
     }
     if(age<mini)
        mini=age;
   }

   cout<<"Maximum = "<<maxi;
   cout<<endl<<"minimum = "<<mini;
   cout<<endl<<"So the range is from "<<mini<<" and "<<maxi;

    return 0;
}
