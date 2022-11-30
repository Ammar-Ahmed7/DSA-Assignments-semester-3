#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Node{
     public:
     int data;
     Node * next;
};
Node * start,* l,* temp;

void insertatEnd(int d){
  l=start;
  if(start==NULL){
    start=new Node;
    start->data=d;
    start->next=NULL;
  }

  else
  {

   while(l->next!=NULL){
    l=l->next;
  }

   if (l->next==NULL){
    temp=new Node;
    temp->data=d;
    temp->next=NULL;
    l->next=temp;
  }

  }


}

  void printing(){
    l=start;
   if(start==NULL){
   cout<<"Empty";
   }
  while(l->next!=NULL){
    cout<<l->data;
    l=l->next;
  }
  if(l->next==NULL){
    cout<<l->data;
  }

  }





  void insertatPoint(int d){
     l=start;
     int p;
     cout<<"Enter your position = ";
     cin>>p;
     while(l->data!=p){
      l=l->next;
     }
     if(l->data==p){
      temp=new Node;
      temp->data=d;
      temp->next=l->next;
      l->next=temp;
     }
  }

  void del(int d){
   l=start;
   if(l->data==d){
    start=l->next;
    delete(l);
   }
    else{
      while(l->data!=d){
        temp=l;
        l=l->next;
      }
      if(l->data==d){
        temp->next=l->next;
        free(l);
        delete(l);
      }

    }
   }

  


  




int main()
{
    int ch,x,y,z;
 while(true){
    system("cls");
    cout << "Enter \n 1.Insert at End \n 2.To display \n 3.Insert at point \n 4.Delete \n 5.Exit = ";
    cin>>ch;
    while(ch!=1 && ch!=2 && ch!=3 && ch!=4 && ch!=5){
      cout<<"\n Invalid";
      Sleep(500);
      cin.clear();
      cin.ignore();
      main();
    }
    switch(ch){
   case 1:
    while(true){
     system("cls");
     cout<<"Enter value or press -1 to exit = ";
     cin>>x;
     if(x==-1){
        break;
     }
     else{
     insertatEnd(x);
     }
    }
    break;

   case 2:
    system("cls");
    printing();
    getch();
    break;
    

   case 3:    
     while(true){
     system("cls");
     cout<<"Enter value you want to insert or press -1 to exit = ";
     cin>>y;
     if(y==-1){
        break;
     }
     else{
     insertatPoint(y);
     }
    }
    
    break;

    case 4:
    while(true){
     system("cls");
     cout<<"Enter value or press -1 to exit = ";
     cin>>z;
     if(z==-1){
        break;
     }
     else{
     del(z);
     }
    }
    break;

    case 5:
    exit(0);
    break;
 }
}

    return 0;
}
