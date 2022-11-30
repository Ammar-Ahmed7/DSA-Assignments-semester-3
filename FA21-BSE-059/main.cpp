#include <iostream>
#include<time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

int main()
{
    int hit=0,b=0;
     int a=rand()%(122+1-65)+65;
   char arr[26][19],row[25],column[18];

    srand(time(0));

   for(int i=0;i<24;i++){
    for(int j=0;j<19;j++){
        arr[i][j]=' ';
    }
    }
    for(int k=0;k<19;k++){
        arr[25][k]='-';
    }

      for(int k=0;k<10;k++){
        row[k]=(rand()%20)+1;
        column[k]=(rand()%17)+1;
        if(arr[row[k]][column[k]]=' '){

        int a=rand()%(122+1-65)+65;
        while(a>=91 && a<=96){
            a=rand()%(122+1-65)+65;
        }

        arr[row[k]][column[k]]=a;}
        cout << arr[row[k]][column[k]];


        if(kbhit()!=0){
            char b=getch();
            if(b==arr[row[k]][column[k]])
                 hit ++;
        }

    }
    cout <<hit;


    for(int i=0;i<=25;i++){
    for(int j=0;j<19;j++){
        cout << arr[i][j]<<"  ";
        }
        cout << endl;
        }

         Sleep(500);
       system("cls");


while(b!=6){
    for(int k=0;k<10;k++){
          row[k]++;
        cout << arr[row[k]][column[k]];

        if(kbhit()!=0){
            char b=getch();
            if(b==arr[row[k]][column[k]])
                 hit ++;
        }

    }
    cout <<hit;

    for(int i=0;i<=25;i++){
    for(int j=0;j<19;j++){
        cout << arr[i][j]<<"  ";
        }
        cout << endl;
        }


        Sleep(500);
        b++;
        system("cls");
}
    return 0;
}
