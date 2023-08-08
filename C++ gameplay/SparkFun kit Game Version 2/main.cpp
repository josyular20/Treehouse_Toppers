#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void MusicSong(int a);

string player1,player2,player3;
int main() {
    srand(time(0));
    cout << "What is the name of the first player?";
    cin >> player1;
    cout << "What is the name of the second player?";
    cin >> player2;
    cout << "What is the name of the third player?";
    cin >> player3;

    int player1_space = 0;
    int player2_space = 0;
    int player3_space = 0;
    int answer;

    while (player1_space < 60 && player2_space < 60 && player3_space < 60) {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        int dice3 = rand() % 6 + 1;

        cout << endl;
        cout << player1 << ", type in 1 to roll the dice";
        cin >> answer;
        cout << player1 << " moves " << dice1 << " spaces forward" << endl;
        player1_space = player1_space + dice1;

        if (player1_space > 60) {
            player1_space = player1_space - dice1;
            cout << "Number is too big. You stay on space " << player1_space << " and do not need to complete a challenge. Try again next time." << endl;
        }
        else {
            cout << player1 << " is now on space " << player1_space << ", which corresponds to a ";
            if (player1_space == 8 || player1_space == 27 || player1_space == 38 || player1_space == 49) {
                player1_space = player1_space - dice1;
                cout << "turn being skipped. Your turn is skipped and you will move back to space " << player1_space << endl;
            }
            else if(player1_space==21 || player1_space == 44)
            {
                int challenge;
                cout<<" a JINX Challenge !!!"<<endl;
                cout<<"Type 2 to challenge "<<player2<<" or Type 3 to challenge "<<player3;
                cin>>challenge;
                if(challenge==2)
                {
                    cout<<player1<<" has chosen to challenge "<<player2<<". The winner moves forward 4 spaces. The loser moves backward 3 spaces."<<endl;
                    int whowon;
                    cout<<"Who won the challenge? Type 1 for "<<player1<<" or Type 2 for "<<player2<<".";
                    cin>>whowon;
                    if(whowon==1)
                    {
                        player1_space=player1_space+4;
                        player2_space=player2_space-3;
                        cout<<"Since "<<player1<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player1_space<<endl;
                        cout<<"Since "<<player2<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player2_space<<endl;
                    }
                    else if(whowon==2)
                    {
                        player1_space=player1_space-3;
                        player2_space=player2_space+4;
                        cout<<"Since "<<player1<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player1_space<<endl;
                        cout<<"Since "<<player2<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player2_space<<endl;
                    }
                }
                else if(challenge==3)
                {
                    cout<<player1<<" has chosen to challenge "<<player3<<". The winner moves forward 4 spaces. The loser moves backward 3 spaces."<<endl;
                    int whowon;
                    cout<<"Who won the challenge? Type 1 for "<<player1<<" or Type 3 for "<<player3<<".";
                    cin>>whowon;
                    if(whowon==1)
                    {
                        player1_space=player1_space+4;
                        player3_space=player3_space-3;
                        cout<<"Since "<<player1<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player1_space<<endl;
                        cout<<"Since "<<player3<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player3_space<<endl;

                    }
                    else if(whowon==3)
                    {
                        player1_space=player1_space-3;
                        player3_space=player3_space+4;
                        cout<<"Since "<<player1<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player1_space<<endl;
                        cout<<"Since "<<player3<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player3_space<<endl;
                    }
                }
            }
            else {
                if (player1_space % 4 == 1) {
                    cout << "Hover Game " << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player1_space = player1_space - dice1;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player1_space << endl;
                    } else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player1_space << endl;
                    }
                }
                else if (player1_space % 4 == 2) {
                    cout << "Music Challenge" << endl;
                    int songNumber;
                    cout << "What is the number of the song that was outputted to the Serial Monitor?";
                    cin >> songNumber;
                    MusicSong(songNumber);
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player1_space = player1_space - dice1;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player1_space << endl;
                    }
                    else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player1_space << endl;
                    }
                }
                else if (player1_space % 4 == 3) {
                    cout << "Memory Game" << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player1_space = player1_space - dice1;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player1_space << endl;
                    }
                    else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player1_space << endl;
                    }
                }
                else if (player1_space % 4 == 0) {
                    cout << "Fitness Challenge" << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player1_space = player1_space - dice1;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player1_space << endl;
                    }
                    else if (gameWon == 1) {
                        if (player1_space == 12) {
                            cout<< "Since you won the game, move your piece across the slide. You moved 4 spaces forward and your new space is 16 !!!"<< endl;
                            player1_space = 16;
                        }
                        else if (player1_space == 36) {
                            cout << "Since you won the game, move your piece across the crosswalk. You moved 3 spaces forward and your new space is 39 !!!" << endl;
                            player1_space = 39;
                        }
                        else {
                            cout << "Since you won the game, you remain at space " << player1_space << endl;
                        }
                    }
                }
            }
            if (player1_space == 60) {
                cout << "Congrats " << player1 << ", you have won the game!!!" << endl;
                return (0);
            }
        }


        cout << endl;
        cout << player2 << ", type in 1 to roll the dice";
        cin >> answer;
        cout << player2 << " moves " << dice2 << " spaces forward" << endl;
        player2_space = player2_space + dice2;

        if (player2_space > 60) {
            player2_space = player2_space - dice2;
            cout << "Number is too big. You stay on space " << player2_space << " and do not need to complete a challenge. Try again next time." << endl;
            }
        else {
            cout << player2 << " is now on space " << player2_space << ", which corresponds to a ";
            if (player2_space == 8 || player2_space == 27 || player2_space == 38 || player2_space == 49) {
                player2_space = player2_space - dice2;
                cout << "turn being skipped. Your turn is skipped and you will move back to space " << player2_space << endl;
            }

            else if(player2_space==21 || player2_space == 44)
            {
                cout<<" a JINX Challenge !!!"<<endl;
                int challenge;
                cout<<"Type 1 to challenge "<<player1<<" or Type 3 to challenge "<<player3;
                cin>>challenge;
                if(challenge==1)
                {
                    cout<<player2<<" has chosen to challenge "<<player1<<". The winner moves forward 4 spaces. The loser moves backward 3 spaces."<<endl;
                    int whowon;
                    cout<<"Who won the challenge? Type 1 for "<<player1<<" or Type 2 for "<<player2<<".";
                    cin>>whowon;
                    if(whowon==1)
                    {
                        player1_space=player1_space+4;
                        player2_space=player2_space-3;
                        cout<<"Since "<<player1<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player1_space<<endl;
                        cout<<"Since "<<player2<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player2_space<<endl;

                    }
                    else if(whowon==2)
                    {
                        player1_space=player1_space-3;
                        player2_space=player2_space+4;
                        cout<<"Since "<<player1<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player1_space<<endl;
                        cout<<"Since "<<player2<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player2_space<<endl;
                    }
                }
                else if(challenge==3)
                {
                    cout<<player2<<" has chosen to challenge "<<player3<<". The winner moves forward 4 spaces. The loser moves backward 3 spaces."<<endl;
                    int whowon;
                    cout<<"Who won the challenge? Type 2 for "<<player2<<" or Type 3 for "<<player3<<".";
                    cin>>whowon;
                    if(whowon==2)
                    {
                        player2_space=player2_space+4;
                        player3_space=player3_space-3;
                        cout<<"Since "<<player2<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player2_space<<endl;
                        cout<<"Since "<<player3<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player3_space<<endl;

                    }
                    else if(whowon==3)
                    {
                        player2_space=player2_space-3;
                        player3_space=player3_space+4;
                        cout<<"Since "<<player2<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player2_space<<endl;
                        cout<<"Since "<<player3<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player3_space<<endl;
                    }
                }
            }
            else {
                if (player2_space % 4 == 1) {
                    cout << "Hover Game " << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player2_space = player2_space - dice2;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player2_space << endl;
                    }
                    else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player2_space << endl;
                    }
                }
                else if (player2_space % 4 == 2) {
                    cout << "Music Challenge" << endl;
                    cout << "What is the number of the song that was outputted to the Serial Monitor?";
                    int songNumber;
                    cin >> songNumber;
                    MusicSong(songNumber);
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player2_space = player2_space - dice2;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player2_space << endl;
                    }
                    else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player2_space << endl;
                    }
                }
                else if (player2_space % 4 == 3) {
                    cout << "Memory Game" << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player2_space = player2_space - dice2;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player2_space << endl;
                    }
                    else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player2_space << endl;
                    }
                }
                else if (player2_space % 4 == 0) {
                    cout << "Fitness Challenge" << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player2_space = player2_space - dice2;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player2_space << endl;
                    }
                    else if (gameWon == 1) {
                        if (player2_space == 12) {
                            cout << "Since you won the game, move your piece across the slide. You moved 4 spaces forward and your new space is 16 !!!" << endl;
                            player2_space = 16;
                        }
                        else if (player2_space == 36) {
                            cout << "Since you won the game, move your piece across the crosswalk. You moved 3 spaces forward and your new space is 39 !!!" << endl;
                            player2_space = 39;
                        }
                        else {
                            cout << "Since you won the game, you remain at space " << player2_space << endl;
                        }
                    }
                }
            }
            if (player2_space == 60) {
                cout << "Congrats " << player2 << ", you have won the game!!!" << endl;
                return (0);
            }
        }


        cout << endl;
        cout << player3 << ", type in 1 to roll the dice";
        cin >> answer;
        cout << player3 << " moves " << dice3 << " spaces forward" << endl;
        player3_space = player3_space + dice3;

        if (player3_space > 60) {
            player3_space = player3_space - dice3;
            cout << "Number is too big. You stay on space " << player3_space << " and do not need to complete a challenge. Try again next time." << endl;
        }
        else {
            cout << player3 << " is now on space " << player3_space << ", which corresponds to a ";
            if (player3_space == 8 || player3_space == 27 || player3_space == 38 || player3_space == 49) {
                player3_space = player3_space - dice3;
                cout << "turn being skipped. Your turn is skipped and you will move back to space " << player3_space << endl;
            }

            else if(player3_space==21 || player3_space == 44)
            {
                cout<<" a JINX Challenge !!!"<<endl;
                int challenge;
                cout<<"Type 1 to challenge "<<player1<<" or Type 2 to challenge "<<player2;
                cin>>challenge;
                if(challenge==1)
                {
                    cout<<player3<<" has chosen to challenge "<<player1<<". The winner moves forward 4 spaces. The loser moves backward 3 spaces."<<endl;
                    int whowon;
                    cout<<"Who won the challenge? Type 1 for "<<player1<<" or Type 3 for "<<player3<<".";
                    cin>>whowon;
                    if(whowon==1)
                    {
                        player1_space=player1_space+4;
                        player3_space=player3_space-3;
                        cout<<"Since "<<player1<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player1_space<<endl;
                        cout<<"Since "<<player3<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player3_space<<endl;

                    }
                    else if(whowon==3)
                    {
                        player1_space=player1_space-3;
                        player3_space=player3_space+4;
                        cout<<"Since "<<player1<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player1_space<<endl;
                        cout<<"Since "<<player3<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player3_space<<endl;
                    }
                }
                else if(challenge==2)
                {
                    cout<<player3<<" has chosen to challenge "<<player2<<". The winner moves forward 4 spaces. The loser moves backward 3 spaces."<<endl;
                    int whowon;
                    cout<<"Who won the challenge? Type 2 for "<<player2<<" or Type 3 for "<<player3<<".";
                    cin>>whowon;
                    if(whowon==2)
                    {
                        player2_space=player2_space+4;
                        player3_space=player3_space-3;
                        cout<<"Since "<<player2<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player2_space<<endl;
                        cout<<"Since "<<player3<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player3_space<<endl;

                    }
                    else if(whowon==3)
                    {
                        player2_space=player2_space-3;
                        player3_space=player3_space+4;
                        cout<<"Since "<<player2<<" has lost the challenge, they move 3 spaces back. Their new space is -->"<<player2_space<<endl;
                        cout<<"Since "<<player3<<" has won the challenge, they move 4 spaces forward. Their new space is -->"<<player3_space<<endl;
                    }
                }
            }
            else {
                if (player3_space % 4 == 1) {
                    cout << "Hover Game " << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player3_space = player3_space - dice3;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player3_space << endl;
                    }
                    else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player3_space << endl;
                    }
                }
                else if (player3_space % 4 == 2) {
                    cout << "Music Challenge" << endl;
                    int gameWon;
                    cout << "What is the number of the song that was outputted to the Serial Monitor?";
                    int songNumber;
                    cin >> songNumber;
                    MusicSong(songNumber);
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player3_space = player3_space - dice3;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player3_space << endl;
                    }
                    else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player3_space << endl;
                    }
                }
                else if (player3_space % 4 == 3) {
                    cout << "Memory Game" << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player3_space = player3_space - dice3;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player3_space << endl;
                    }
                    else if (gameWon == 1) {
                        cout << "Since you won the game, you remain at space " << player3_space << endl;
                    }
                }
                else if (player3_space % 4 == 0) {
                    cout << "Fitness Challenge" << endl;
                    int gameWon;
                    cout << "Type 1 if you won the game. Type 2 if you lost the game";
                    cin >> gameWon;
                    if (gameWon == 2) {
                        player3_space = player3_space - dice3;
                        cout << "Since you did not win the game, you go back to your previous space, which is " << player3_space << endl;
                    }
                    else if (gameWon == 1) {
                        if (player3_space == 12) {
                            cout << "Since you won the game, move your piece across the slide. You moved 4 spaces forward and your new space is 16 !!!" << endl;
                            player3_space = 16;
                        }
                        else if (player3_space == 36) {
                            cout << "Since you won the game, move your piece across the crosswalk. You moved 3 spaces forward and your new space is 39 !!!" << endl;
                            player3_space = 39;
                        }
                        else {
                            cout << "Since you won the game, you remain at space " << player3_space << endl;
                        }
                    }
                }
            }
            if (player3_space == 60) {
                cout << "Congrats " << player3 << ", you have won the game!!!" << endl;
                return (0);
            }
        }
    }
}

void MusicSong(int a)
{
    if(a==0)
    {
        cout<<"The song that was played is ---->  Tetris Song"<<endl;
    }
    if(a==1)
    {
        cout<<"The song that was played is ---->  Game of Thrones"<<endl;
    }
    if(a==2)
    {
        cout<<"The song that was played is ---->  Take on Me"<<endl;
    }
    if(a==3)
    {
        cout<<"The song that was played is ---->  Harry Potter"<<endl;
    }
    if(a==4)
    {
        cout<<"The song that was played is ---->  The Mii Song"<<endl;
    }
    if(a==5)
    {
        cout<<"The song that was played is ---->  Never gonna give you up"<<endl;
    }
    if(a==6)
    {
        cout<<"The song that was played is ---->  Super Mario Theme Song"<<endl;
    }
    if(a==7)
    {
        cout<<"The song that was played is ---->  Pink Panther Theme Song"<<endl;
    }
    if(a==8)
    {
        cout<<"The song that was played is ---->  We Wish You A Merry Christmas"<<endl;
    }
    if(a==9)
    {
        cout<<"The song that was played is ---->  Ode to Joy"<<endl;
    }
    if(a==10)
    {
        cout<<"The song that was played is ---->  Imperial March"<<endl;
    }
    if(a==11)
    {
        cout<<"The song that was played is ---->  Fur Elise"<<endl;
    }
    if(a==12)
    {
        cout<<"The song that was played is ---->  Minuet in G Major"<<endl;
    }
    if(a==13)
    {
        cout<<"The song that was played is ---->  Pac Man"<<endl;
    }
    if(a==14)
    {
        cout<<"The song that was played is ---->  Canon in D"<<endl;
    }
}
