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
#include <cctype>


using namespace std;

void restart();
void won();
void drowned();
void player();

bool gameOver;
const int MAX=3;
char ch[MAX]={'_','+','o'};
int score=0;
string Pname;


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
  score=0;
}


void blocset(){
    system("cls");
    int no=0;
 while(no<=25){
    int tempt=rand()% MAX;                   // Creating 25 blocks of Node
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
      for(int i=0;i<8;i++){
    cout<<endl;
    }
    cout<<"\t\t\t\t";
      l=start;
    for(int i=0; i<5; i++){                           //  Printing Blocks of Nodes
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
            cout.width(9);
            cout<<"F";
              l=l->next;

                }

          else{
            cout.width(9);
            cout<<l->data;
            l=l->next;
              if(l->next==NULL){
              cout.width(9);
              l->prev->data='@';

             }
           }

     }

      cout<<endl<<endl;
      cout<<"\t\t\t\t";
    }


}

void boundary(){

 if(x>4 || x<0 || y>4 || y<0){
     system("CLS");
  for(int i=0;i<10;i++){
    cout<<endl;
    }
    cout<<"\t\t\t\t\t" <<Pname<<" YOU DROWNED AS YOU WERE OUT OF BOUND :( ";     //Creating Boundary
    Sleep(2000);
    gameOver=true;
 }

}



void Input_and_Logic(){                        //Input movements with Logic

  if(_kbhit()){

    switch(_getch()){

       case 'a':
        x--;
        l=start;
for(int i=0; i<5; i++){
     for(int j=0 ; j<5; j++){
           if(i==y && j==x){
                if(l->data==' '){
                   drowned();
                }
               else if(l->data=='@'){
                 won();
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
                   drowned();
                }
             else  if(l->data=='@'){
                 won();
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
                   drowned();
                }

             else  if(l->data=='@'){
                 won();
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
                   drowned();
                }

              else if(l->data=='@'){
                won();

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



void drowned(){
  system("CLS");
  for(int i=0;i<10;i++){
    cout<<endl;
    }
    cout<<"\t\t\t\t\t\t"<<Pname<<" YOU DROWNED :( ";
    Sleep(2000);
    gameOver=true;


}

void won(){
  system("CLS");
  for(int i=0;i<10;i++){
    cout<<endl;
    }
    cout<<"\t\t\t\t\t\t"<<Pname<<" YOU WIN :) ";
    Sleep(1500);
    gameOver=true;

}


void instruct(){
   system("CLS");
  for(int i=0;i<10;i++){
    cout<<endl;
    }
    cout<<"\t\t\t\t\t\t Instructions";
    cout<<"\n\t\t\t In this Frog Jump game you have to navigate your frog 'F'\n\t\t\t to end point '@' through different Blocks (Rock,Flower,Leaf)\n\t\t\t with everystep taken on flower it will change into leaf and\n\t\t\t with everystep taken on a leaf it will disappers meanwhile the\n\t\t\t rocks remains the same. Be careful of Drownig.\n\n\t\t\t\t\t Press any key to continue";
   getch();
}

void sc(){
cout<<"\n\n\t\t\t\t\tScore: "<<score<<endl;
}

void controlInstruct(){
  cout<<"\n\t\t\t\t\tPress W,A,S,D to control Frog 'F' movement";
  cout<<"\n\t\t\t\t\t(NOTE: Don't move outside the blocks boundary or you will Drown)";
}



int main()
{

    system("cls");
    reset();
    blocset();
    setup();
    player();
    instruct();

    while(!gameOver){
    blocks();
    Input_and_Logic();
    boundary();
    sc();
    controlInstruct();
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

     if((ch!='Y') && (ch!='N')&&(ch!='y')&&(ch!='n')){
       cout<<endl<<"\t\t\t\t\t NOTE: Invalid input enter Y or N ";
       Sleep(500);
       cin.clear();
       cin.ignore();
        restart();
      }
     switch(ch){

     case 'Y':
     case 'y':
       main();
        break;

     case 'N':
     case 'n':
        cout<<endl<<"\t\t\t\t\t THANK YOU FOR PLAYING! "<<endl;
        break;
     }
}
 void player(){
   system("CLS");
   string input;
  for(int i=0;i<10;i++){
    cout<<endl;
    }
    cout<<"\t\t\t\t\t Enter Your name =  ";
    cin>>input;

    bool is_notvalid=false;  // Assume the input is valid until proven otherwise

    for (char c : input) {
      if (!isalpha(c) || !isupper(c) && !islower(c)) {
        // Check if the character is not alphabetical or not uppercase or lowercase
        is_notvalid = true;  // The input is not valid
        break;  // No need to check the rest of the string
      }
    }
      Pname=input;
    if (is_notvalid) {
      cout << "\n\t\t\t\t\t Invalid input Please try again(Alphabets Only)" << endl;
      Sleep(1000);
      player();
    }


}
