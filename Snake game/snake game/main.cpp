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
int x,y,foodX,foodY,score=0;

enum Direction{STOP=0,UP,DOWN,LEFT,RIGHT};
Direction dir;

int tailX[100],tailY[100];
int ntail;
time_t start, finish;

void restart();
void setup();
void draw();
void logicE();
void logicH();
void input();
void playE();
void playH();


void setup(){

gameEnd=false;
x=width/2;
y=height/2;
foodX= rand() %width;
foodY= rand() %height;
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
        else if(i==y && j==x){
        cout<<"O";
        }
        else if(i==foodY && j==foodX){
           cout<<"F";
        }
        else
        {
             bool print=false;
            for(int k=0;k<ntail;k++){


                if(tailX[k]==j && tailY[k]==i)
                {
                    cout<<"o";
                    print=true;
                }

            }
             if(!print){
                    cout<<" ";
                }

        }

    }
    cout<<endl;
  }


  for(int i=0;i<width;i++){
    cout<<"#";
}cout<<endl;
  cout<<"Score: "<<score<<endl;
  cout<<endl<<"Press W for UP, A for LEFT, S for DOWN, D for RIGHT";
}

void input(){

if(_kbhit()){

    switch(_getche()){
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
        restart();
        break;


    }
}


}

void logicE(){

int prevX=tailX[0];
int prevY=tailY[0];
tailX[0]=x;
tailY[0]=y;
int prev2X,prev2Y;

for(int i=1;i<ntail;i++){

    prev2X=tailX[i];
    prev2Y=tailY[i];
    tailX[i]=prevX;
    tailY[i]=prevY;
    prevX=prev2X;
    prevY=prev2Y;

}

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
if(x > width || x < 0 || y > height || y < 0){
    gameEnd=true;
}

for(int i=0;i<ntail;i++){
  if(tailX[i]==x && tailY[i]==y){
      gameEnd=true;
  }
}

if(x==foodX && y==foodY){

    score+=10;
  foodX= rand() %width;
  foodY= rand() %height;
   ntail++;
}
  time(&finish);
    cout<<"                                        Time: "<<difftime(finish, start)<<endl;
    if(difftime(finish, start)>=30){
        restart();


}
}

void logicH()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < ntail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
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
    if(x > width || x < 0 || y > height || y < 0){
    restart();
     }


    for (int i = 0; i < ntail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameEnd = true;

    if (x == foodX && y == foodY)
    {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
        ntail++;
    }
    time(&finish);
    cout<<"                                        Time: "<<difftime(finish, start)<<endl;
    if(difftime(finish, start)>=30){
        restart();
    }
}


int main()
{


    system("CLS");
     time(&start);
int c;
for(int i=0;i<10;i++){
cout<<endl;
}

cout<<"\t\t\t\t\t WELCOME TO SNAKE GAME!!! "<<endl;
cout<<endl<<"\t\t\t\t\t Enter your difficulty mode : "<<endl;
cout<<"\t\t\t\t\t\t 1.Easy "<<endl;
cout<<"\t\t\t\t\t\t 2.Hard "<<endl;
cout<<"\t\t\t\t\t Enter your Choice = ";
cin>>c;

 if(c!=1 && c!=2){
       cout<<endl<<"\t\t\t\t\t NOTE: Invalid input enter 1 or 2  ";
      cin.clear();
       cin.ignore();
       Sleep(1000);
       main();
      }
 switch(c){

   case 1:
     playE();
    break;


   case 2:
       playH();
    break;

   }
    return 0;
}


void playagain(){

  main();

}
 void playE(){

    setup();
    while(!gameEnd){
    draw();
    input();
    logicE();
    Sleep(50);
    }
    restart();


 }

 void playH(){


   setup();
    while(!gameEnd){
    draw();
    input();
    logicH();
    }
    restart();

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
        playagain();
        break;

     case 'N':
        cout<<endl<<"\t\t\t\t\t THANK YOU FOR PLAYING! "<<endl;
        break;
     }

}

