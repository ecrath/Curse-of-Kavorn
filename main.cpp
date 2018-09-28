#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Universal Variables
string name;
int playerCharacter [4];
string statNames [4] = {" Current HP", " Total HP", " Attack Bonus", " Inventory Space"};
int dead = 0;
string endGame;
string contin;

//character creation
// A class for building one of the starting characters
void characterCreator ()
{
    //variables needed
    string classChoice;


    //choosing class
    cout << "What class do you choose? Knight/Apprentice/Thief " << endl;
    cin >> classChoice;

    //creating initial stats
    for (int i = 0; i < 1; ){
    if ((classChoice == "Thief") || (classChoice == "thief") || (classChoice == "THIEF")){
    playerCharacter[0]= 15;
    playerCharacter[1]= 15;
    playerCharacter[2]= 3;
    playerCharacter[3]= 6;
    i = i + 1;
    }
    else if ((classChoice == "Apprentice") || (classChoice == "apprentice") || (classChoice == "APPRENTICE")){
    playerCharacter[0]= 10;
    playerCharacter[1]= 10;
    playerCharacter[2]= 6;
    playerCharacter[3]= 4;
    i = i + 1;
    }
    else if ((classChoice == "Knight") || (classChoice == "knight") || (classChoice == "KNIGHT")){
    playerCharacter[0]= 20;
    playerCharacter[1]= 20;
    playerCharacter[2]= 2;
    playerCharacter[3]= 4;
    i = i + 1;
    }
    // Invalid choice catch
    else {
        cout << "That was not a valid choice please try again: " << endl;
        cin >> classChoice;
    }
    //Showing player the stats
    cout << name << endl;
    for (int i= 0; i < 4; i= i+1)
    {
        cout << "Here are your stats: " << endl;
        cout << playerCharacter[i];
        cout << statNames[i] << endl;
        cout << " " << endl;
    }
    }

}
//Tell the player what their character currently looks like
void characterStatus (){
    cout << " " << endl;
    cout << "Here are your stats: " << endl;
    cout <<"_______________________________" << endl;
    for (int i= 0; i < 4; i= i+1)
    {

        cout << playerCharacter[i];
        cout << statNames[i] << endl;
    }
    cout << " " << endl;
}

//character changes
//inventory checker
//called whenever inventory is adjusted in order to change stats
//combat
//Using random integers to simulate combat
void combat (int enemyHealth, int enemyAttack, string enemyName)
{

    int playerHit;
    int enemyHit;
    //fight indicator
    cout << "**************************************************************" << endl;
    cout << "A " ;
    cout << enemyName ;
    cout << " has appeared, you must fight to escape!" << endl;
    cout << " " << endl;
    cout << "Enter any key to continue: "<< endl;
    cin >> contin;

    cout <<"_______________________________" << endl;
    cout << "Begin Combat" << endl;
    cout <<"_______________________________" << endl;


    //creating attacks
    for (;enemyHealth >= 0;){

        playerHit = (rand() % 4) + playerCharacter[2];
        cout << "You hit for ";
        cout<< playerHit ;
        cout<< " damage" <<endl;
        cout<< " " << endl;

        enemyHit = rand() % enemyAttack;
        cout << "The ";
        cout << enemyName;
        cout << " hit for ";
        cout<< enemyHit ;
        cout<< " damage" <<endl;
        cout<< " " << endl;
        cout<< " " << endl;

        playerCharacter[0]= playerCharacter[0] - enemyHit;
        enemyHealth = enemyHealth - playerHit;

            if (playerCharacter[0] <= 0)
        {
            dead = 1;
            cout << "You have been defeated!" << endl;
            break;
        }
    }
    if (dead == 0){
    cout << "You have defeated ";
    cout << enemyName << endl;
    }

    cout << "**************************************************************" << endl;
    cout << "Enter any key to continue: "<< endl;
    cin >> contin;

    characterStatus();
}


//exploration
//map reference
//character status

int main()
{
    //important variables
    string x;
    string y;
    string currentHP;
    string totalHP;
    string attackBonus;
    string character [4];
    string choice;

    //Title screen
    cout << "CURSE OF KAVORN" << endl;
    cout << "______________________" << endl;
    cout << "Welcome to the Curse of Kavorn a simple text based RPG made for Enthuastic Education with Ethan." << endl;
    cout << "All inpute should be lowercase for simplicity. Good luck and have fun." << endl;
    cout << " " << endl;
    cout << "Enter any key to continue: "<< endl;
    cin >> contin;

    //clearing space
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;

    //inputting name
    cout << "What is your name: " << endl;
    cin >> name;

    cout << " " << endl;
    cout << " " << endl;

    //story
    cout << "Your footsteps patter against the slick cobbled stone streets of Havor.  In your hands you clench the crown jewels of the king." <<endl;
    cout << "A lucky find some might say, but you know better this was a planned event, you knew what you needed to do in order to gather these and escape." << endl;
    cout << "The papers will surely talk in the morning, speculate on who could have lifted the jewels with such skill." << endl;
    cout << "Perhaps you are a KNIGHT who was spurred by the kingdom and rejected for your radical ideals." << endl;
    cout << "Maybe just an APPRENTENCE who attempted to climb out of the shadow of their skilled master." << endl;
    cout << "Or maybe, just maybe, the visiting emissary just happened to be a daring THEIF in disguise..." <<endl;

    //Creating your character class
    characterCreator();

    //checking if choice is okay after seeing stats
    cout << "Is this okay?" << endl;
    cin >> choice;
    //fixing class choice if not okay
    while ((choice == "No") || (choice == "no") || (choice == "n"))
    {
        characterCreator();

        //checking if choice is ojay again
        cout << "Is this okay?" << endl;
        cin >> choice;
    }
    //setting up inventory
    string characterInv [playerCharacter[3]];
    //story cont.
    cout << " " << endl;
    cout << " " << endl;
    cout << "You continue to run from the castle, unless someone tipped off the guard you should be scott-free the king is gone hunting afterall." << endl;
    cout << "Hastily, you turn down the narrow alley you have explored many a time. This will lead you directly to the town square." << endl;
    cout << "From there it is only a short jog to the front gates, a easy escape." << endl;
    cout << "Unfortunately for you, a figure stands at the end of the alleyway" << endl;

    //first fight
    combat(15, 5, "Guard");

    //exposition
    cout << "An ill omen him being here, but with a weapon drawn means something more sinister..." << endl;
    cout << "Someone must have tipped off the guard, there is no other way they would have been armed and looking for you at this hour" << endl;\
    cout << "But the deed is already done, the only choice is to move forward." << endl;
    cout << "You press on to the town square wary of what might be waiting for you." << endl;
    cout << "As you expected a large group of town guard stand in front of you, what do you do?" << endl;
    //first choice
    cin >> choice;

    for (int i = 0 ; i < 1 ; ){
    if ((choice == "flee") || (choice == "run"))
    {
        cout << "Glancing around at the 5 guards in front of you, you realized you cannot hold them all back." << endl;
        cout << "You make all haste to try and get into a nearby alleyway, but they were ready for you to try to run..." << endl;

        combat(50, 10, "Group of Guards");

        i = i +1;
    }
    else if (choice == "surrender")
    {
        cout << "Your hands reach for the clouded night sky as you surrender yourself over to the guard." << endl;

        i = i +1;
    }
    else if (choice == "fight")
    {
        combat (50, 10, "Group of Guards");
        i = i +1;
    }
    else
    {
    cout << "That is not a recognized command, I probably forgot to include it, please try something else:" << endl;
    cin >> choice;
    }
    }
    cout << "They clasp you in irons and bring you off to jail to await your fate" << endl;
    cout << "Thanks for playing! Enter any key to exit" << endl;
    cin >> endGame;


return 0;
}
