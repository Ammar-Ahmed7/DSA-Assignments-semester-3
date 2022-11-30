#include <iostream>

using namespace std;

void dis(int arr[],int sizze){

for(int i=0;i<sizze;i++){
    cout<<endl<<arr[i];
}

}




void addvall(int arr[],int sizze){

    cout<<endl;
    dis(arr,sizze);


for(int i=0;i<sizeof arr;i++){
    if(arr[i]==arr[sizze-1]){
       cout<<endl<<"Enter the your value = ";
       cin>>arr[i+1];
       sizze++;
       dis(arr,sizze);
    }
}
cout<<endl<<"No more space left in array";
}


void remvall(int arr[],int sizze){

   cout<<endl;
   cout<<"After removing last value"<<endl;
   for(int i=0; i<sizeof (arr); i++){
    cout<<endl<<arr[i];
   }

}


/*void addvalf(int arr[],sizze){
for(int i=0;i<=sizeof arr


}*/





int main()
{
    int arr[10],sizze;
    cout<<"Enter the number of elements you want to input = ";
    cin>>sizze;
    cout<<endl;
for(int i=0;i<sizze;i++){
    cin>>arr[i];
}


    addvall(arr,sizze);
    cout<<endl;

    //remvall(arr,sizze);
    cout<<endl;





    return 0;
}
