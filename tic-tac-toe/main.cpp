#include <iostream>
using namespace std;

char num[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int choice;
int row,column;
char turn = 'X';
bool val = false;


void display()
{
    cout<<"\n";
    cout<<"\t\t  "<<num[0][0]<<"  |  " <<num[0][1]<<"  |  "<<num[0][2]<<" \n";
    cout<<"\t\t-----|-----|-----\n";
    cout<<"\t\t  "<<num[1][0]<<"  |  " <<num[1][1]<<"  |  "<<num[1][2]<<" \n";
    cout<<"\t\t-----|-----|-----\n";
    cout<<"\t\t  "<<num[2][0]<<"  |  " <<num[2][1]<<"  |  "<<num[2][2]<<" \n";
    cout<<"\t\t     |     |     \n\n";
}


void player_turn()
{
    if(turn == 'X')
    {
        cout<<"\n\tPlayer - 1 (X) \t place number : ";
    }
    else if(turn == 'O')
    {
        cout<<"\n\tPlayer - 2 (O) \t place number : ";
    }

    cin>> choice;


    switch(choice){
        case 1:
             row=0; column=0;
              break;
        case 2:
             row=0; column=1;
         break;
        case 3:
             row=0; column=2;
              break;
        case 4:
             row=1; column=0;
              break;
        case 5:
             row=1; column=1;
              break;
        case 6:
             row=1; column=2;
              break;
        case 7:
             row=2; column=0;
              break;
        case 8:
             row=2; column=1;
              break;
        case 9:
             row=2; column=2;
              break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && num[row][column] != 'X' && num[row][column] != 'O')
    {
        num[row][column] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && num[row][column] != 'X' && num[row][column] != 'O')
    {
        num[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout<<"Choose other place.\n\n";
    }
    display();
}

bool gameover()
{
    for(int i=0; i<3; i++)
    if(num[i][0] == num[i][1] && num[i][0] == num[i][2] || num[0][i] == num[1][i] && num[0][i] == num[2][i])
    return false;


    if(num[0][0] == num[1][1] && num[0][0] == num[2][2] || num[0][2] == num[1][1] && num[0][2] == num[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(num[i][j] != 'X' && num[i][j] != 'O')
    return true;

    val = true;
    return false;
}


int main()
{
    cout<<"\t\tPlayer 1 - X\t\t Player 2 - O\n\n";
    while(gameover())
    {
        player_turn();
        gameover();
    }

     if(turn == 'O' && val == false)
    {
        cout<<"\n\nPlayer 1 won.";
    }

    else if(turn == 'X' && val == false)
    {
        cout<<"\n\nPlayer 2 won.";
    }
    else
    cout<<"\t\t Draw\n\n";
}
