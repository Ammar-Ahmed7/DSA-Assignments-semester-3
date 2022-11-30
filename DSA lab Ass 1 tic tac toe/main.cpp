#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
void restart();

void setboard(string sb[][3]){

 for (int i = 0; i < 3; i++) {
     for (int j = 0; j < 3; j++) {
               sb[i][j]=" ";
            }
        }
}

void gameboard(string gb[][3]){
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
                 cout<<"\t"<<gb[i][j];
                cout<<" |";

            }
               cout<<endl;
               cout<<"\t"<<"-----------------------";
               cout<<endl;
        }

}


void player(string n,string gp[][3]){
  int turn;
 cout<<endl<<"\t"<<n<<" enter a number (1-9) = ";
 cin>>turn;
 cout<<endl;

switch(turn){

   case 1:
       gp[0][0]="X";
       break;

   case 2:
       gp[0][1]="X";
       break;

   case 3:
       gp[0][2]="X";
       break;

   case 4:
       gp[1][0]="X";
       break;

   case 5:
       gp[1][1]="X";
       break;

    case 6:
        gp[1][2]="X";
       break;


     case 7:
         gp[2][0]="X";
       break;

     case 8:
         gp[2][1]="X";
       break;


      case 9:
          gp[2][2]="X";
       break;

}

}

void comp(string cp[][3]){

cout<<endl;
cout<<endl<<"\t Computer's turn"<<endl<<endl;
while(true){
int compturn=(rand()%9)+1;
 int row =(compturn-1)/3;
 int col = (compturn-1)%3;

 string grid_position= cp[row][col];
  if(grid_position=="X" || grid_position=="O"){
    continue;
  }
  else{
    cp[row][col]="O";
    break;
  }

}

}

int checkwinner(string cw[][3],string na2){

 if((cw[0][0] == "X" && cw[0][1]== "X" && cw[0][2]=="X"))
             {
                 cout<<endl;
                 cout<<"Congrats "<<na2<<" wins";
                 restart();
             }
        if((cw[0][0] == "O" && cw[0][1]== "O" && cw[0][2]=="O"))
             {
                 cout<<endl;
                 cout<<"Computer wins";
                 restart();
             }
        if((cw[1][0] == "X" && cw[1][1]== "X" && cw[1][2]=="X"))
        {
                 cout<<endl;
                 cout<<"Congrats "<<na2<<"wins";
                 restart();
        }
        if((cw[1][0] == "O" && cw[1][1]== "O" && cw[1][2]=="O"))
        {
                   cout<<endl;
                 cout<<"Computer wins";
                 restart();
        }
        if((cw[2][0] == "X" && cw[2][1]== "X" && cw[2][2]=="X"))
        {
            cout<<endl;
                 cout<<"Congrats "<<na2<<"wins";
                 restart();
        }
        if((cw[2][0] == "O" && cw[2][1]== "O" && cw[2][2]=="O"))
        {
             cout<<endl;
                 cout<<"Computer wins";
                 restart();
        }


        if((cw[0][0] == "X" && cw[1][0]== "X" && cw[2][0]=="X"))
        {
            cout<<endl;
                 cout<<"Congrats "<<na2<<"wins";
                 restart();
        }
        if((cw[0][0] == "O" && cw[1][0]== "O" && cw[2][0]=="O"))
        {
            cout<<endl;
                 cout<<"Computer wins";
                 restart();
        }
        if((cw[0][1] == "X" && cw[1][1]== "X" && cw[2][1]=="X"))
        {
            cout<<endl;
                 cout<<na2<<"wins";
                 restart();
        }
        if((cw[0][1] == "O" && cw[1][1]== "O" && cw[2][1]=="O"))
        {
             cout<<endl;
                 cout<<"Computer wins";
                 restart();

        }
        if((cw[0][2] == "X" && cw[1][2]== "X" && cw[2][2]=="X"))
        {
            cout<<endl;
                 cout<<"Congrats "<<na2<<"wins";
                 restart();
        }
        if((cw[0][2] == "O" && cw[1][2]== "O" && cw[2][2]=="O"))
        {
            cout<<endl;
                 cout<<"Computer wins";
                 restart();
        }


        if((cw[0][0] == "X" && cw[1][1]== "X" && cw[2][2]=="X"))
        {
            cout<<endl;
                 cout<<"Congrats "<<na2<<"wins";
                 restart();
        }
        if((cw[0][0] == "O" && cw[1][1]== "O" && cw[2][2]=="O"))
        {
             cout<<endl;
                 cout<<"Computer wins";
                 restart();
        }
        if((cw[0][2] == "X" && cw[1][1]== "X" && cw[2][0]=="X"))
        {
           cout<<endl;
                 cout<<"Congrats "<<na2<<"wins";
                 restart();
        }
        if((cw[0][2] == "O" && cw[1][1]== "O" && cw[2][0]=="O"))
        {
            cout<<endl;
                 cout<<"Computer wins";
                 restart();
        }

        return 1;

}


int main()
{
    system("CLS");
    string board[3][3],nam;
     cout<<"Player enter your name = ";
     cin>>nam;
     setboard(board);
while(checkwinner(board,nam)==1)
     {
     player(nam,board);
     gameboard(board);
     checkwinner(board,nam);
     comp(board);
     gameboard(board);
     checkwinner(board,nam);
     }

    return 0;
}

void restart(){
char c;
cout<<endl<<"\t"<<"Wanna play again (Y/N)";
cin>>c;

if(c=='y' || c=='Y'){
    main();
}
if(c=='n' || c=='N'){
    cout<<endl<<"Thanks for Playing!!!"<<endl;
    exit(0);
}

}


