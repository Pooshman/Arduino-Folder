#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <string>
using namespace std;
//*Program Name: Robot Wars
//* Created Date: 12 November 2022
//* Created By: Purush Ram
//* Purpose: C++ Assignment 6
//* Acknowledgements: N/A

//*Function Name: robotInfo
//* Parameters: N/A
//* Return Value: struct
//* Purpose: creates public class of robot
struct robotInfo {
    string name;
    //points for each stat
    int health;
    int damageCapacity;
    int wins;
    int losses;
};

//*Function Name: infoMaker()
//* Parameters: robotInfo& compBot, robotInfo& userBot
//* Return Value: void
//* Purpose: creates necessary information for each robot
void infoMaker(robotInfo& compBot,robotInfo& userBot);

//*Function Name: infoDisplay()
//* Parameters: robotInfo& compBot, robotInfo& userBot
//* Return Value: void
//* Purpose: Displays the information of each robot
void infoDisplay(robotInfo& compBot, robotInfo& userBot);

//*Function Name: keyContinue()
//* Parameters: N/A
//* Return Value: void
//* Purpose: asks user to enter key to continue
void keyContinue();

//*Function Name: damageGen()
//* Parameters: robotInfo Bot;
//* Return Value: int
//* Purpose: returns an attack value from 0 to robot's attack capacity
int damageGen(robotInfo Bot);

//*Function Name: attackerPick()
//* Parameters: N/A
//* Return Value: int
//* Purpose: returns 1 or 0 to choose which bot attacks
int attackerPick();

//*Function Name: main()
//* Parameters: N/A
//* Return Value: int
//* Purpose: starts the program
int main() {
    
    //boolian to loop game
    bool loop = true;

    //initialize bots
    robotInfo compBot;
    robotInfo userBot;

    //loop to ask user if they want to play again
    
    while(loop=true) {
    
        //boolian to loop rounds as long as bots' health>0
        bool fightValid = true;

        //ask user bot's name
        cout<<"\nWelcome to Robot Wars!\n In this game, you'll fight a Computer Bot.";
        cout<<"\n\nPick a name for your robot:\n";
        cin>>userBot.name;
        cout<<"\n\n";

        infoMaker(compBot,userBot); //make user and computer bots
        
        int roundNum = 1; //Set fight round number
        
        int whichAttacker; //set variable to hold attacker pick
        
        int tempDamage; //holds the temporary damage value

        //loop for fight rounds
        while(fightValid=true) {

            
            if (userBot.health<=0 || compBot.health<=0) {

                break;
            }
            else {
                //print attack number
                cout<<"Attack #" << roundNum << "\n\n\n";
                
                //Display robot stats
                infoDisplay(compBot, userBot);
                
                //Ask User to continue
                keyContinue();
                
                //pick between 0 and 1. compBot=0, userBot=1
                whichAttacker = attackerPick();
                
                if (whichAttacker==0) {
                    
                    //compBot attacks
                    cout<<compBot.name<<" attacks!\n";
                    
                    tempDamage = damageGen(compBot); //generate damage value
                    cout<<compBot.name<<" deals "<<tempDamage<<" damage.\n\n";
                    
                    //subtract damage from health
                    userBot.health = userBot.health-tempDamage;
                    keyContinue();
                    
                    
                }
                
                else if (whichAttacker==1) {
                    
                    //userBot attacks
                    cout<<userBot.name<<" attacks!\n";
                    
                    tempDamage = damageGen(userBot); //generate damage value
                    cout<<userBot.name<<" deals "<<tempDamage<<" damage.\n\n";
                    
                    //subtract damage from health
                    compBot.health = compBot.health-tempDamage;
                    keyContinue();
                }
                
            //increment round number
            roundNum = roundNum +1;
            continue;
            }
        
        }
        //ending messages
        
        //if userBot lost
        if (userBot.health<=0) {
            
            cout<<compBot.name<<" beat you. Sorry!\n\n";
        }
        
        //if compBot lost
        else if (compBot.health<=0) {
            
            cout<<userBot.name<<" has won! Great Job!\n\n";
        }
        
        //ask user if they want to play again
        char loopDecider;
        cout<<"Would you like to play again? (Y/N)";
        cin>>loopDecider;
        
        if (loopDecider=='y' || loopDecider=='Y') {
            
            continue;
            
        }
        
        else {
            
            break;
        }
    }
    
    return 0;
}

//creates info for bots
void infoMaker(robotInfo& compBot,robotInfo& userBot) {

    //Computer's name (Dave)
    compBot.name = "Dave";

    //computer and user health (100)
    compBot.health= 100;
    userBot.health=100;

    //computer and user max damage (random)
    compBot.damageCapacity = (rand() % 101) +1;
    userBot.damageCapacity = (rand() % 101) +1;
    
    //user bots wins and losses (0)
    userBot.wins = 0;
    userBot.losses = 0;
    
    //computer wins and losses (random)
    compBot.wins = (rand() % 10) +1;
    compBot.losses = (rand() % 10) +1;
}

//displays bot info
void infoDisplay(robotInfo& compBot, robotInfo&userBot) {

    //Stating userBot information
    cout<<"\n\nYour robot ("<< userBot.name << ") has:\n\n\n";
    cout<<"Health: "<<userBot.health;
    cout<<"\n\nDamage: "<<userBot.damageCapacity;
    cout<<"\n\nWins: "<<userBot.wins;
    cout<<"\n\nLosses: "<<userBot.losses;
    
    //stating compBot info now
    cout<<"\n\n\nThe Computer's robot ("<< compBot.name << ") has:\n\n\n";
    cout<<"Health: "<<compBot.health;
    cout<<"\n\nDamage: "<<compBot.damageCapacity;
    cout<<"\n\nWins: "<<compBot.wins;
    cout<<"\n\nLosses: "<<compBot.losses;
}

//asks user to press key to advance game
void keyContinue() {
    string dummy;
    char key;
    cout<< "\n\n\nPress any key to continue...";
    cin>>key;
    getline(cin, dummy); //grabs floating endline from cin
    cout<<"\n\n\n";
}

//returns attack value in bot's damage range
int damageGen(robotInfo Bot) {
    
     return ((rand() % Bot.damageCapacity) +1);

}

//returns 1 or 0 to pick which bot attacks
int attackerPick () {
    
    return (rand() % 2);
}
