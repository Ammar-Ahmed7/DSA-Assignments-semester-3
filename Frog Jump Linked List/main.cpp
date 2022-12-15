#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>


using namespace std;

bool gameOver;
const int MAX=3;
char ch[MAX]={'_','+','o'};


int x,y;
enum eDirection{ STOP =0, LEFT,RIGHT,UP,DOWN};
eDirection dir;

struct Node{
    char data;
    Node *next;
};
Node *start,*l,*temp;

void blocset(){
    system("cls");
    int no=0;
 while(no!=10){   
    int tempt=rand()% MAX;
   l=start;
   if(start==NULL){
    start=new Node;
    start->data=ch[tempt];
    start->next=NULL;
   }
   else{
    while(l->next!=NULL){
        l=l->next;
    }
    int tempt2=rand()% MAX;
    if(l->next==NULL){
        temp=new Node;
        temp->data=ch[tempt2];
        temp->next=NULL;
        l->next=temp;
    }
   }
   no++;
 }

}

void blocPrint(){
 

  
}

void setup(){
 gameOver= false;
 dir = STOP;
  x= 10 /  2 ;
  y= 10 / 2 ;

  


}


void blocks(){
     system("cls");
     l=start;
    for(int i=0; i<10; i++){
       
     for(int j=0 ; j<10; j++){
         
           if(i==y && j==x){
               cout.width(3);
                cout<<"F";
                l=l->next;
            }

          else{   
            cout.width(3);
            cout<<l->data;
            l=l->next; 
          }
          
     }
     
     l=start;
     cout<<endl;
    }
    
}

void input(){
  if(_kbhit()){

    switch(_getch()){

       case 'a':
        dir= LEFT;
        break;

        case 'd':
        dir= RIGHT;
        break;

        case 'w':
        dir= UP;
        break;

        case 's':
        dir= DOWN;
        break;

        case '':
        gameOver=true;
        break;
    }

  }
}

void logic(){
  switch(dir){

     case LEFT:
     x--;
     break;

     case RIGHT:
     x++;
     break;

     case UP:
     y--;
     break;

     case DOWN:
     y++;
     break;

     default:
     break;

  }
}


int main()
{
    system("cls");

   srand (time(NULL));
   
    setup();
     blocset(); 
    while(!gameOver){
    blocks();
    input();
    logic();
    Sleep(40);
    }


    return 0;
}
