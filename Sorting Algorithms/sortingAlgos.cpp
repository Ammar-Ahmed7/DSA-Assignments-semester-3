#include <iostream>
#include <conio.h>
using namespace std;
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void insertionSort(int arr[], int sizee) {
  for (int step = 1; step < sizee; step++) {
    int key = arr[step];
    int j = step - 1;
    while (key > arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}


void bubbleSort(int arr[], int sizee) {
  for (int step = 0; step < sizee; ++step) {
    for (int i = 0; i < sizee - step; ++i) {
      if (arr[i] < arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
  
}
void swaps(int arr[],int i,int j){
int temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
int partitions(int arr[],int p,int r){
    int pivot = arr[r];
    int j;
    int i=p-1;
for( j=p;j<r;j++){
    if(arr[j]<=pivot){
        i++;
        swaps(arr,i,j);
    }
}
swaps(arr,i+1,r);
return i+1;
}
void quicksort(int arr[],int p,int r){
if(p<r){
    int q=partitions(arr,p,r);
    quicksort(arr,p,q-1);
    quicksort(arr,q+1,r);
}

}
void merge(int arr[],int l, int mid,int r)
{
  int B[100];
    int i = l;
    int k = l;
    int j = mid+1;
  while ( i<= mid && j<= r ){
        if (arr[i] <= arr[j]){
            B[k++] = arr[i++];
        }
        else{
            B[k++] = arr[j++];
        }
    }
    while ( i<= mid){

        B[k++] = arr[i++];
    }
    while ( j <= r ){
        B[k++] = arr[j++];
    }
    for(int i=l ;i<=r;i++){
        arr[i]=B[i];
    }
}

void mergesort(int arr[], int l, int r){
    if(l<r){
int mid=(l+r)/2;
mergesort(arr,l,mid);
mergesort(arr,mid+1,r);
merge(arr,l,mid,r);
}
}


int main()
{

    int arr[10]={2,4,6,3,7,5,1,9,8,11};
    int ch;
   while(true){ 
    system("Cls");
    cout<<"Enter options \n1.Print Array \n2.Insertion sort \n3.Bubblesort \n4.swaps \n5.Partition \n6.Quicksort \n7.merge \n8.mergesort \n9.Quit =  ";
    cin>>ch;

    switch(ch){
      case 1:
      system("Cls");
      printArray(arr,10);
      getch();
      break;

      case 2:
      system("Cls");
      insertionSort(arr,10);
      break;

      case 3:
      system("Cls");
      bubbleSort(arr,10);
      break;

      case 4:
      system("Cls");
      swaps(arr,4,7);
      break;

      case 5:
      system("Cls");
      partitions(arr,3,8);
      break;

      case 6:
      system("Cls");
      quicksort(arr,5,2);
      getch();
      break;

      case 7:
      system("Cls");
      merge(arr,0,4,9);
      break;

      case 8:
      system("Cls");
      mergesort(arr,8,1);
      break;

      case 9:
      exit(0);
      break;

    }
   }
    return 0;
}