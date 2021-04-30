#include <iostream>

using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn  = 'X';
int draw = 0;
int row = 0,col = 0;
void board_display()
{
    cout<<"\t           |     |     "<<endl;
    cout<<"\t        "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"   "<<endl;
    cout<<"\t      _____|_____|_____"<<endl;
    cout<<"\t           |     |     "<<endl;
    cout<<"\t        "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"   "<<endl;
    cout<<"\t      _____|_____|_____"<<endl;
    cout<<"\t           |     |     "<<endl;
    cout<<"\t        "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"   "<<endl;
    cout<<"\t           |     |     "<<endl;
    cout<<endl<<endl<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
}
void playerturn()
{
    char choice;
    cout<<"\t\t Enter Your choice"<<endl;
    cin >> choice;
    switch(choice)
    {
        case '1' : row = 0 , col = 0;
        break;
        case '2' : row = 0 , col = 1;
        break;
        case '3' : row = 0 , col = 2;
        break;
        case '4' : row = 1 , col = 0;
        break;
        case '5' : row = 1 , col = 1;
        break;
        case '6' : row = 1 , col = 2;
        break;
        case '7' : row = 2 , col = 0;
        break;
        case '8' : row = 2 , col = 1;
        break;
        case '9' : row = 2 , col = 2;
        break;
        default : {
                   cout<<"Invalid choice:"<<endl;

                   playerturn();
                  }
    }
    if(turn == 'X'&&board[row][col]!='X'&&board[row][col]!='O')
    {
        board[row][col] = 'X';
        turn = 'O';
    }
    else if(turn == 'O'&&board[row][col]!='X'&&board[row][col]!='O')
    {
        board[row][col] = 'O';
        turn = 'X';
    }
    else
    {
        cout<<"\t\t Invalid choice"<<endl<<endl;
        playerturn();
    }

}
int gameover()
{
    if(board[0][0] == board[1][1] && board[1][1]==board[2][2])
    {
        return 0;
    }
    if(board[0][2] == board[1][1] && board[1][1]==board[2][0])
    {
        return 0;
    }
    for(int i = 0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 0;
        }
    }
    for(int i = 0;i<3;i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 0;
        }
    }
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            if(board[i][j]!='X'||board[i][j]!='O')
            {
                return 1;
            }
        }
    }
    draw = 1;
    return draw;

}
int main()
{
    cout << "     @!!!<- T I C - C R O S S  G A M E ->!!!@" << endl<<endl;
    cout << "      P L A Y E R - 1 = X    "<<endl;
    cout << "      P L A Y E R - 2 = O    "<<endl<<endl;
    string s,d;
    cout<<"\t\t Enter name of player 1"<<endl;
    cin >> s;
    cout<<"\t\t Enter name of player 2"<<endl;
    cin >>d;
    board_display();
    while(gameover())
    {
        cout<<"\t\t T U R N : "<<turn<<endl;
        playerturn();
        board_display();
    }

    if(turn == 'X'&&draw == 0)
    {
        cout<<"\t\t :) player 2 "<<d<<" is W I N N E R !!!!!!"<<endl<<endl<<endl;
    }
    else if(turn == 'O' && draw == 0)
    {
        cout<<"\t\t :) player 1 "<<s<<" is W I N N E R !!!!!!"<<endl<<endl<<endl;
    }
    else if(draw == 1)
    {
        cout<<"\t\t !!!! G A M E - D R A W !!!!"<<endl<<endl<<endl;

    }
    return 0;
}
