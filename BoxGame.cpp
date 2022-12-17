#include <iostream>
#include <iomanip>
#include <random>
using namespace std;
//This code is a game show, where the user picks between 3 boxes
//1 box has a million dollars, the other two have rotten apples
//After the user's choice, a box that has a rotten apple and is
//not the user's choice will be revealed
//The user can then choose to stay or switch their choice

//makes sure User picks 1-3 boxes for their first choice
void invalidInput (int &userBox) { 
    cout<<"Invalid input. Try again.\n";
    cout<< "Pick box 1, 2, or 3: ";
    cin>>userBox;
}

//makes sure User picks the remaining two boxes for their second choice
void invalidInput2 (int &userBox, int ogBox, int remainBox) {
    while ((userBox!=ogBox)&&(userBox!=remainBox)) {
        cout<<"Invalid input. Try again.\n";
        cout <<"Choose:\nbox "<<ogBox<<"\nor\nbox "<<remainBox<<": ";
        cin>>userBox;
    }
    return;
}

//Reveals 1 box then makes user pick again between two remaining boxes
void finalChoice (int &userBox, int winBox, int &remainBox) {
    cout <<"You've chosen box "<<userBox<<"!\n";

    //box to be revealed
    int shownBox=1;

    //saves original (first) user choice
    int ogBox=userBox;
    
    //loop to figure out which box to reveal
    for (; true; ) {

        if ((shownBox!=userBox)&&(shownBox!=winBox)) {

            //This is the box not shown and not the user's choice
            remainBox=6-(userBox+shownBox);

            cout <<"Let me show you what's in box "<<shownBox<<": ";
            cout <<"A rotten apple!\nWould you like to stay with your choice or switch?\n\n";
            cout <<"Choose: \nbox "<<userBox<<"\nor\nbox "<<remainBox<<": ";
            cin>>userBox;

            //If second input is not one of the remaining two choices
            if ((userBox!=ogBox)&&(userBox!=remainBox)) {
                invalidInput2(userBox, ogBox, remainBox); 
            
            }

            //If user stayed with original choice
            if (userBox==ogBox) {
                cout <<"You stayed with your original choice: Box "<<userBox<<"!";
                return; 
            }

            //If user stayed switched choice
            else {
                cout <<"You switched to "<<userBox<<"!";
                return;
            }
        }

        else {
        shownBox++;
        continue;
        }
    }
}

//Figures out if user won or lost
void winLose(int userBox, int winBox) {
    if (userBox==winBox) {
            cout << " You won...\n\nONE MILLION DOLLARS!!!";
            return;
        }
    else {
            cout << " You won...\n\na rotten apple :(";
            return;
        }
}

//This is where game starts
int main() {

    //User's choice
    int userBox;

    //Winning Box
    int winBox=(rand() % 3) + 1;

    //Remaining Box
    int remainBox;

    cout<<"Welcome to my game show! There are 3 boxes:\n";
    cout<< "Two boxes have a rotten apple :(.\n";
    cout<< "But ONE has A MILLION DOLLARS!!\n\n";
    cout<< "Pick box 1, 2, or 3: ";
    cin>>userBox;

//Loop if user doesn't enter 1,2, or 3
for (; true; ) { 
    if ((userBox>3)||(userBox<1)) {
        invalidInput(userBox);
        continue;
    }

    //Enters second and final part of game
    else {

        finalChoice(userBox, winBox, remainBox);
        winLose(userBox,winBox);
        return 0;
    }
}

return 0;
}
