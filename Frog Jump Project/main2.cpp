#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>

using namespace std;

bool gameEnd;
const int height=20;
const int width=20;
int x,y;

enum Direction{STOP=0,UP,DOWN,LEFT,RIGHT};
Direction dir;


void setup(){

 gameEnd=false;
 x=width/2;
 y=height/2;
 dir=STOP;

}


void draw(){

system("CLS");

for(int i=0;i<width;i++){
    cout<<"#";
}cout<<endl;

  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        if(j==0||j==width-1){
           cout<<"#";
        }
         if(i==y && j==x){
        cout<<"O";
        }
         else{
            cout<<" ";
         }   

    }
    cout<<endl;
  }


  for(int i=0;i<width;i++){
    cout<<"#";
}cout<<endl;

}

void input(){

if(_kbhit()){

    switch(_getch()){
 case 'w':
    dir=UP;
    break;

     case 'a':
    dir=LEFT;
    break;

     case 's':
    dir=DOWN;
    break;

     case 'd':
    dir=RIGHT;
    break;

     case '':
        gameEnd=true;
    
        break;


    }
}


}

void logicE(){

switch(dir){

      case UP:
       y--;
       break;

       case DOWN:
       y++;
       break;

       case LEFT:
       x--;
       break;

       case RIGHT:
       x++;
       break;

       default:
        break;
}


}

void logicH()
{
    switch (dir)
    {
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
   while(!gameEnd){
    draw();
    input();
    logicE();
    Sleep(100);
   }

    

}

