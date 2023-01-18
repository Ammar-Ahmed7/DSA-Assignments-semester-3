#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Node{
     public:
     int data;
     Node *left=NULL;
     Node *right=NULL;

   Node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;
   }

};

Node* insertintoBST(Node *root,int d){
  
   if(root==NULL){
    root=new Node(d);
    return root;
   }

  if(d > root->data){
    root->right= insertintoBST(root->right,d);
  }
  else{
    root->left = insertintoBST(root->left,d);
  }

  return root;

}

void display(Node * root){
  if(root==NULL){
    return;
  }
  display(root->left);
  cout<<root->data<<" ";
  display(root->right);

}


bool isBST(Node * root, Node *min, Node *max ){
   
    max=NULL;
    min=NULL;

   if(root==NULL){
    return true;
   }
   if(max!=NULL && root->data >= max->data){
        return false;
    }
    if(min!=NULL && root->data <= min->data){
        return false;
    }
    
    bool leftIsValid=isBST(root->left, min, root);
    bool rightIsValid=isBST(root->right, root, max);

    return leftIsValid;
    return rightIsValid; 
}


int main()
{
  Node *tree=NULL;

       Node *tree2=new Node(1);
       tree2->left=new Node(2);
       tree2->right=new Node(3);
  
   int ch;
  while(true){
    system("CLS");
   cout<<"Enter the options \n1.Insert \n2.Check BST \n3.Display \n4.Exit = ";
   cin>>ch;
    
    switch(ch){
      case 1:
      system("cls");

      tree=insertintoBST(tree,5);
      insertintoBST(tree,9);
      insertintoBST(tree,55);
      insertintoBST(tree,3);
      insertintoBST(tree,7);
      insertintoBST(tree,1);
      insertintoBST(tree,2);

      cout<<"Inserted \n ";
      Sleep(800);

      system("cls");
      cout<<"Inorder(Increasing order)\n";
      display(tree);
      cout<<"\n\nPress any key to go back\n";
      getch();
      break;

      case 2:
      system("cls");
      if(isBST(tree,NULL,NULL)){
        cout<<"It is a valid BST"<<endl;
      }
      else{
        cout<<"Invalid BST(Not a BST)"<<endl;
      }
      cout<<"\n\nPress any key to go back\n";
      getch();
      break;

      case 3:
      system("cls");
      cout<<"Inorder(Increasing order)\n";
      display(tree);
      getch();
      break;

      case 4:
      exit(0);
      break;


    }
  }
    return 0;
}