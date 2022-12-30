#include <iostream>
#include <thread>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iomanip>


using namespace std;

void restart();


bool gameOver;
const int MAX=3;
char ch[MAX]={'_','+','o'};
int score=0;

int x,y;


struct Node{
    char data;
    Node *next;
    Node *prev;
};
Node *start,*l,*temp;

void reset(){
  start=NULL;
  l=NULL;
  temp=NULL;
}

void blocset(){
    system("cls");
    int no=0;
 while(no<=25){   
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
  x= 0;
  y= 0;

  


}


void blocks(){
     system("cls");
      for(int i=0;i<10;i++){
    cout<<endl;
    }
    cout<<"\t\t\t\t\t";
      l=start;
    for(int i=0; i<5; i++){
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
            cout.width(5);
             cout.widen(5);
            cout<<"F";    
              l=l->next;

                }

          else{ 
            cout.width(5);
            cout.widen(5);
            cout<<l->data;
            l=l->next;
              if(l->next==NULL){
              cout.width(6);
              cout.widen(5);
              l->prev->data='@';
              
             } 
           }
      
     }
    
      cout<<endl;
      cout<<"\t\t\t\t\t";
    }
    
    
}

void boundary(){

 if(x>4 || x<0 || y>4 || y<0){
    gameOver=true;
 }

  
}
  

void Input_and_Logic(){
  
  if(_kbhit()){

    switch(_getch()){

       case 'a':
        x--;
        l=start;
for(int i=0; i<5; i++){
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){ 
                   gameOver=true;
                } 
               else if(l->data=='@'){
                gameOver=true;
               } 
               
              else  if(l->data=='_'){
                l=l->next;
                l->prev->data=' '; 
                
               }
            else if(l->data=='+'){
                 l=l->next;
                l->prev->data='_'; 
                
            } 

           }
          else{  
            l=l->next;    
           }
           
     }
      cout<<endl;
    }
      if((x>0 && x<24)||(y>0 && y<24)){
              score+=10;
            }
        break;



        case 'd':
        x++;
        l=start;
        for(int i=0; i<5; i++){
         for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){
                   gameOver=true;
                }
             else  if(l->data=='@'){
                gameOver=true;
               } 
               
            else   if(l->data=='_'){
                l=l->next;
                l->prev->data=' '; 
                
            }
             else if(l->data=='+'){
                l=l->next;
                l->prev->data='_'; 
                
            }

           }
          else{  
            l=l->next;  
           }
           
      
     }
      cout<<endl;
    }
       if((x>0 && x<24)||(y>0 && y<24)){
              score+=10;
            }
        break;



        case 'w':
        y--;

         l=start;
        for(int i=0; i<5; i++){
        for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){
                   gameOver=true;
                }
         
             else  if(l->data=='@'){
                gameOver=true;
               } 
               

            else  if(l->data=='_'){
                l=l->next;
                l->prev->data=' '; 
                
                
            }
          else  if(l->data=='+'){
                l=l->next;
                l->prev->data='_'; 
            }

           }
          else{  
            l=l->next;
            
           }
           
     }
      cout<<endl;
    }
       if((x>0 && x<24)||(y>0 && y<24)){
              score+=10;
            }
   
        break;



        case 's':
        y++;

         l=start;
        for(int i=0; i<5; i++){
        for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){
                   gameOver=true;
                }
    
              else if(l->data=='@'){
                gameOver=true;
               } 
              else if(l->data=='_'){
                  l=l->next;
                l->prev->data=' ';  
              }
            else if(l->data=='+'){
               l=l->next;
                l->prev->data='_'; 
               
            }
                
           }
          else{  
            l=l->next;
            
           }
           
      
     }
      cout<<endl;
    }
        if((x>0 && x<24)||(y>0 && y<24)){
              score+=10;
            }
        break;
     

        case '':
       gameOver=true;
        break;
    }

  }

  
}

  

  

 



void sc(){
cout<<"\n\n\t\t\t\t\tScore: "<<score<<endl;  
}




int main()
{
    system("cls");
    reset();
    blocset(); 
    setup();
     
    while(!gameOver){
    blocks();
    Input_and_Logic();
    boundary();
    sc();
    }
    restart();


    return 0;
}

void restart(){
   system("CLS");
  char ch;
  for(int i=0;i<10;i++){
    cout<<endl;
    }
     cout<<"\t\t\t\t\t YOUR FINAL SCORE IS = "<<score<<endl;
     cout<<" \t\t\t\t\t Wanna restart (Y/N) = ";
     cin>>ch;

     if((ch!='Y') && (ch!='N')){
       cout<<endl<<"\t\t\t\t\t NOTE: Invalid input enter Y or N ";
       Sleep(1000);
       cin.clear();
       cin.ignore();
        restart();
      }
     switch(ch){

     case 'Y':
       main();
        break;

     case 'N':
        cout<<endl<<"\t\t\t\t\t THANK YOU FOR PLAYING! "<<endl;
        break;
     }
}

