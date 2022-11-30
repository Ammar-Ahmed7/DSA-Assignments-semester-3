#include <iostream>
#include<time.h>

using namespace std;

int main()
{
int k=0;
   string arr[5][1];
   while(k!=5){
   for(int i=0;i<5;i++){
    for(int j=0;j<1;j++){
        arr[i][j]="ada";
        cout<<arr[i][j];
        arr[i][j]="";
        cout<<endl;
        k++;
    }
    cout<<arr;
   }
  }









    return 0;
}
