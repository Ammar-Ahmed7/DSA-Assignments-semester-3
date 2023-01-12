#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Node{
   public:
   int data;
   Node *left;
   Node *right;

   Node (int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;
}

};


//INSERTION
Node* insertIntoBST(Node* root,int d){
   //base case
   if(root == NULL){
       root=new Node(d);
       return root;
   }

   if(d > root->data){
    // right part insert
    root->right = insertIntoBST(root->right,d);
   }
   else{
    // left part insert
    root->left = insertIntoBST(root->left,d);
   }
   
   return root;
}



//SEARCH
Node* searhinBST(Node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    //data > key
    if(root->data > key){
        return searhinBST(root->left,key);
    }

    //data<key
    return searhinBST(root->right,key);
}
 





Node* inorderSucc(Node *root){
    Node* curr= root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
//DELETION
Node* deleteinBST(Node *root, int key){
    if(key < root->data){
        root->left=deleteinBST(root->left,key);
    }
    else if(key > root->data){
        root->right=deleteinBST(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }

        //case 3
        Node* temp= inorderSucc(root->right);
        root->data=temp->data;
        root->right= deleteinBST(root->right,temp->data);
    }

    return root;
}




//inorder 
void inorder(Node *root){
  if(root == NULL){
     return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

//preorder
void preorder(Node *root){
  if(root == NULL){
     return;
  }
  cout<<root->data<<" ";
  inorder(root->left);
  inorder(root->right);
}

//postorder
void postorder(Node *root){
  if(root == NULL){
     return;
  }
  inorder(root->left);
  inorder(root->right);
  cout<<root->data<<" ";
}



int main()
{
   Node *root=NULL;
   int ch,key;
 while(true){
    system("CLS");
   cout<<"Enter the options \n1.Insert \n2.Search \n3.Delete \n4.Display \n5.Exit = ";
   cin>>ch;

   switch(ch){
      
      case 1:
      //Insertion
      system("CLS");
     root=insertIntoBST(root,5);
     insertIntoBST(root,8);
     insertIntoBST(root,69);
     insertIntoBST(root,7);
     insertIntoBST(root,1);
     insertIntoBST(root,6);
     insertIntoBST(root,2);
     cout<<"Inserted";
     Sleep(1000);
      break;
     
      case 2:
       //search 
       system("CLS");
       cout<<"Enter the key you want to search = ";
       cin>>key;
       if(searhinBST(root,key)==NULL){
       cout<<"\nkey does not exist ";
       }
       else{
       cout<<"\nkey exists";
       cout<<endl;
       }
       getch();
      break;

      case 3:
      //Delete
      system("CLS");
       cout<<"Enter the key you want to delete = ";
       cin>>key;
      root=deleteinBST(root,key);
      cout<<"Deleted";
      Sleep(1000);
      break;

     case 4:
     //print inorder
     system("CLS");
     cout<<"Inorder\n";
     inorder(root);
     cout<<endl;

     //print preorder
     cout<<"Preorder\n";
     preorder(root);
     cout<<endl;

     //print postorder
     cout<<"Postorder\n";
     postorder(root);
     cout<<endl;

     getch();
     break;

     case 5:
     exit(0);
     break;

   }
 }
    return 0;
}