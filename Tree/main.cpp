#include <iostream>
using namespace std;
//5,
//every block has a left, right smaller block. and it iself stores value
//
struct tree{
int value;
tree *Lt;
tree *Rt;
}*root, *L, *temp;

void insertBST(tree *L, int data){
    if(root == NULL){
        root = new tree;
        root->value = data;
        root->Lt = NULL;
        root->Rt = NULL;
        cout << "1";
    }
    else if(L == NULL){
        temp = new tree;
        temp->value = data;
        temp->Lt = NULL;
        temp->Rt = NULL;
        L = temp;
                cout << "2";

    }
    else if(L!=NULL){
        if(L->value  > data) insertBST(L->Lt, data);
        else if(L->value < data)insertBST(L->Rt, data);
                cout << "3";

    }
}

void print(tree L){

}

int main(){
    int switchcontroller, no1 = 0;
while(no1 != 27){  //how to put a check for character?
    cout << "\nEnter 1 to Insert, 2 to Delete, 3 to Print, 4 to exit : ";
    cin >> switchcontroller;
    switch(switchcontroller){
    case 1:
        int data;
cout << "\nEnter Data : ";
cin >> data;
        L = root;
          insertBST(L, data);
    break;

    case 2:
    break;

    case 3:
        L = root;
        //printBST(L);
        //print();
    break;

    case 4:
        no1 = 27;
    break;

    }
    }

}