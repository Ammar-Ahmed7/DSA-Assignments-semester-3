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

int counter=0;

int x,y;


struct Node{
    char data;
    Node *next;
    Node *prev;
};
Node *start,*l,*temp;

void blocset(){
    system("cls");
    int no=0;
 while(no<=20){   
    int tempt=rand()% MAX;
   l=start;
   if(start==NULL){
    start=new Node;
    start->data=ch[tempt];
    start->next=NULL;
    start -> prev=NULL;
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
        temp -> prev=l;
    }
   }
   no++;
 }

}


void setup(){
 gameOver= false;
  x= 2;
  y= 2 ;

  


}


void blocks(){
     system("cls");
      l=start;
    for(int i=0; i<4; i++){
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
               cout.width(3);
                cout<<"F";
                l=l->next;
                l->prev->data=' ';
                   counter++;
                }
            

          else{  
            cout.width(3);
            cout<<l->data;
            l=l->next;
            
           }
      
     }
      cout<<endl;
    }
}

void logic(){

 if(x>4 || x<0 || y>3 || y<0){
    gameOver=true;
 }

 
    
    
}
  

void input(){
  
  if(_kbhit()){

    switch(_getch()){

       case 'a':
        x--;
        l=start;
for(int i=0; i<4; i++){
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){
                   gameOver=true;
                }
                }
            

          else{  
            l=l->next;
            
           }
      
     }
      cout<<endl;
    }
        break;

        case 'd':
        x++;
        l=start;
        for(int i=0; i<4; i++){
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){
                   gameOver=true;
                }
                }
            

          else{  
            l=l->next;
            
           }
      
     }
      cout<<endl;
    }
        break;

        case 'w':
        y--;

         l=start;
        for(int i=0; i<4; i++){
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){
                   gameOver=true;
                }
                }
            

          else{  
            l=l->next;
            
           }
      
     }
      cout<<endl;
    }
        break;

        case 's':
        y++;

         l=start;
        for(int i=0; i<4; i++){
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){
                   gameOver=true;
                }
                }
            

          else{  
            l=l->next;
            
           }
      
     }
      cout<<endl;
    }
        break;


        case '':
       gameOver=true;
        break;
    }

  }

 

}



int main()
{
    system("cls");
    blocset(); 
    setup();
   
    while(!gameOver){
    blocks();
    input();
    logic();
    }


    return 0;
}
