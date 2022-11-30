#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <time.h>

using namespace std;
bool gameOver;
const int width = 40;
const int height =20 ;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
void playEasy();
void playHard();
//rand() % (max_number + 1 - minimum_number) + minimum_number
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
time_t start, finish;

void exitGame(){
    system("cls");
    char input;
    cout << "\n\n\n\n\n\n\t\t\t\t\tDo you want to exit or play again";
    cout << "\n\t\t\t\t\tPress 1 to exit and 2 to continue";
    cout << "\n\t\t\t\t\tEnter your choice : ";
    cin  >> input;
    while (input != '1' && input !='2'){
        cout << "\nEnter Again :";
        cin  >> input;
    }
    if (input == '1'){
            system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tGame Over";
    cout << "\n\t\t\t\t\t\tYour Score is : " << score;
    gameOver = true;}
    if (input == '2'){
        playEasy();
    }
}
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
//    time(&start);
    system("cls"); //system("clear");
    srand(time(0));
    char foo= rand() % (90+1-65)+65;
    for (int i = 0; i < width+2; i++)
        cout << "@";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "@";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << foo;
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }


            if (j == width - 1)
                cout << "@";
        }
        cout << endl;
    }

    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;

}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 75:
            dir = LEFT;
            break;
        case 77:
            dir = RIGHT;
            break;
        case 72:
            dir = UP;
            break;
        case 80:
            dir = DOWN;
            break;
        case 27:
            exitGame();
            break;
        }
    }
}

void easyLogic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
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
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
    time(&finish);
    cout<<"                                        Time: "<<difftime(finish, start)<<endl;
    if(difftime(finish, start)>=30){
        exitGame();
    }
}

void hardLogic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
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
    exitGame();
     }
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
    time(&finish);
    cout<<"                                        Time: "<<difftime(finish, start)<<endl;
    if(difftime(finish, start)>=30){
        exitGame();
    }
}

int main()
{
    time(&start);
    Setup();
    char input;
    cout << "\n\n\n\n\n\n\t\t\t\t\tWelcome to Snake Game";
    cout << "\n\n\t\t\t\t\t1. Easy";
    cout << "\n\n\t\t\t\t\t2. Hard";
    cout << "\n\n\t\t\t\t\tEnter your choice: ";
    cin  >> input;
    while (input != '1' && input !='2'){
        cout << "\nEnter Again :";
        cin  >> input;
    }
    if (input == '1'){
     playEasy();
    }
    if (input == '2'){
        playHard();
    }

    return 0;
}

void playEasy(){

    while (!gameOver)
    {
        Draw();
        Input();
        easyLogic();
        Sleep(50); //sleep(10);
    }
    }
void playHard(){
    while (!gameOver)
    {
        Draw();
        Input();
        hardLogic();
        Sleep(50); //sleep(10);
    }
}
