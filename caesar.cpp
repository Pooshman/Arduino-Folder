#include <iostream>
#include <iomanip>
#include <random>
#include <string>
using namespace std;
//*Program Name: Caesar Cipher
//* Created Date: 29 November 2022
//* Created By: Purush Ram
//* Purpose: C++ Assignment 5
//* Acknowledgements: N/A

//*Function Name: encoder()
//* Parameters: int key,string txtSize, string newMsg, string dummy
//* Return Value: void
//* Purpose: encodes user message by an integer cipher key
void encoder(int key,string txtSize, string newMsg, string dummy);

//*Function Name: decoder()
//* Parameters: int key,string txtSize, string newMsg, string dummy
//* Return Value: void
//* Purpose: decodes user message by an integer cipher key
void decoder(int key,string txtSize, string newMsg, string dummy);

//*Function Name: main()
//* Parameters: 
//* Return Value: int
//* Purpose: starts the program
int main(){
    string txtSize,newMsg,dummy,decider; //initializing strings for program
    int key;
    int a=0;

    //initializing strings that are acceptable user commands for input
    string restarter;
    string yRestarter = "Yes"; 
    string yRestarter2= "yes";
    string eDecider = "Encode";
    string eDecider2= "encode";
    string dDecider = "Decode";
    string dDecider2 = "decode";

//looped to restart program
    while (a==0) {
        cout<<"Welcome to the Caesar Cipher! Would you like to Encode/Decode?\n";
        //asks user for encode or decode
        getline(cin, decider);
        if (decider==eDecider|| decider==eDecider2) {
            //runs function encoder
            encoder(key,txtSize,newMsg,dummy);
        }
        else if (decider==dDecider || decider==dDecider2) {
            //runs function encoder
            decoder(key,txtSize,newMsg,dummy);
        }
        else {
            //if their command doesn't match acceptable responses
            continue;
        }
        //restart program
        cout << "Start Again, Yes/No? "; 
        cin >> restarter;
        if (restarter == yRestarter || restarter == yRestarter2) {
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}

void encoder(int key,string txtSize, string newMsg, string dummy) {
    //Asks user for int key they want to scramble message by
    cout<<"What integer cipher key would you like to use (1-25)?\n";
    cin>>key;
    getline(cin, dummy); //grabs floating endline from the cin
    
    cout<<"Enter the message you'd like to encode:\n";
    getline(cin,txtSize);

    for(int i=0;i<txtSize.size();i++){
        //if character is space then enters space
        if (isspace(txtSize[i])) {
            newMsg+=' ';
            continue;
        }
        if (isalpha(txtSize[i])==false) {
            //if character isn't character then enters that character
            newMsg+=txtSize[i];
            continue;
        }
        if (isupper(txtSize[i])) {
            //if character is uppercase it returns uppercase
        newMsg+=(txtSize[i]-'A'+key)%26+'A';
        }
        else {
        newMsg+=(txtSize[i]-'a'+key)%26+'a';
        }
    }
    cout<<"\n\nYour Encrypted message is:\n\n"<<newMsg<<'\n';
}

void decoder(int key,string txtSize, string newMsg, string dummy) {
    //Asks user for int key they want to decode message by
    cout<<"What integer cipher key would you like to use (1-25)?\n";
    cin>>key;
    getline(cin, dummy); //grabs floating endline from the cin
    
    cout<<"Enter the message you'd like to decode:\n"; 
    getline(cin,txtSize);

    for(int i=0;i<txtSize.size();i++){
        if (isspace(txtSize[i])) {
            //if character is space then enters space
            newMsg+=' ';
            continue;
        }
        if (isalpha(txtSize[i])==false) {
            //if character isn't character then enters that character
            newMsg+=txtSize[i];
            continue;
        }
        if (isupper(txtSize[i])) {
            //if character is uppercase it returns uppercase
        newMsg+=(txtSize[i]-'A'+key)%26+26+'A';
        }
        else {
        newMsg+=(txtSize[i]-'a'+26+key)%26+26+'a';
        }
    }
    cout<<"\n\nYour Decrypted message is:\n\n"<<newMsg<<'\n';
}