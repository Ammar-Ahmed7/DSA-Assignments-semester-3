#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>


using namespace std;

bool gameOver;
char blocX[10];
char blocY[10];
const int MAX=3;
char ch[MAX]={'_','+','o'};
int x,y;
enum eDirection{ STOP =0, LEFT,RIGHT,UP,DOWN};
eDirection dir;


void setup(){
 gameOver= false;
 dir = STOP;
  x= sizeof(blocX) /  2 ;
  y= sizeof(blocY) / 2 ;

  srand (time(NULL));
  for (int i=0; i<10; i++){
     int temp=rand()% MAX;
     blocX[i]=ch[temp];
 }
 for (int i=0; i<10; i++){
     int temp=rand()% MAX;
     blocY[i]=ch[temp];
 }


}


void blocks(){
  system("CLS");
    for(int i=0; i<10; i++){
       for(int j=0 ;j<10; j++){
         if(i==y && j==x){
            cout.width(5);
            cout<<"F";
         }
         else{
         cout.width(5); 
         cout<<blocX[j];
         }
       }
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

    setup();
    while(!gameOver){
    blocks();
    input();
    logic();
    delay(10);
    }


    return 0;
}
