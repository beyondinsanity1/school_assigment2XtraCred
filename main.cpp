#include <iostream>
#include <string>

using namespace std;

struct gameInfo {
    string gameName;
    int replayScore;
    int graphicScore;
};

bool firstTimeMenu = true;
const int gameCount = 3;

void getGameName();
void enterReplayScores();
void enterGraphicScores();
void getHighestReplay();
void getHighestGraphic();
void menu();


gameInfo games [gameCount] {};

////////////////////////////////////////////////
//function getAllGameInfo
void getAllGameInfo(){
    for (int i = 0; i < gameCount; i++) {

        cout << "enter a game name" << endl;
        getline(cin,(games[i].gameName));

        cout << "enter the replay score for "<< games[i].gameName << ":" <<endl;
        cin >> games[i].replayScore;

        cout << "enter the graphic score for "<< games[i].gameName << ":" <<endl;
        cin >> games[i].graphicScore;

        cin.ignore();

    }


    for (int i = 0; i < gameCount; i++) {
        cout << games[i].gameName << endl;
    }

    menu();
}

////////////////////////////////////////////////
//function getGameName
void getGameName(){
    for (int i = 0; i < gameCount; i++) {
        cout << "enter a game name" << endl;
        getline(cin,(games[i].gameName));
    }


    cout << "======================================="
            "\nYour game list contains: "<<endl;
    for (int i = 0; i < gameCount; i++) {
        cout << games[i].gameName << endl;
    }
    menu();
}

////////////////////////////////////////////////
//function enterReplayScores
void enterReplayScores(){
    for (int i = 0; i < gameCount; ++i) {
        cout << "enter the replay score for "<< games[i].gameName << ":" <<endl;
        cin >> games[i].replayScore;
    }

    menu();
}

////////////////////////////////////////////////
//function enterGraphicScores
void enterGraphicScores(){

    int highestGraphics = games[0].graphicScore;
    string highestGraphicsName;
    for (int i = 0; i < gameCount; ++i) {
        if (highestGraphics < games[i].graphicScore){
            highestGraphics = games[i].graphicScore;
            highestGraphicsName = games[i].gameName;
        }

    }

    cout << highestGraphicsName << " - " << highestGraphics << endl;

    menu();
}

////////////////////////////////////////////////
//function getHighestReplay
 void getHighestReplay(){
    for (int i = 0; i < gameCount; ++i) {
        int highestReplay = games[0].graphicScore;
        if (highestReplay < games[i].graphicScore){
            highestReplay = games[i].graphicScore;
        }

    }

    menu();
}

////////////////////////////////////////////////
//function getHighestGraphic
void getHighestGraphic(){
    for (int i = 0; i < gameCount; ++i) {
        cout << "enter the graphic score for "<< games[i].gameName << ":" <<endl;
        cin >> games[i].graphicScore;
    }

    menu();
}

////////////////////////////////////////////////
//function menu
void menu(){
    int userInput;
    if (firstTimeMenu == true) {
        cout
                << "Welcome! Select the action you want from the menu! \n Make sure to select '1' as your first action for an accurate calculation!"
                << endl;
        cout << "1. Enter Game Titles\n"
                "2. Enter Graphic Scores\n"
                "3. Enter Replay Scores\n"
                "4. Find the highest graphic score\n"
                "5. Find the highest replay value score\n"
                "6. Find the highest combined score\n"
                "7. Exit" << endl;
        firstTimeMenu = false;


    }else if (firstTimeMenu == false){
        cout<< "================================\n"
               "Please select the next action you want to execute!" << endl;

        cout << "1. Enter Game Titles\n"
                "2. Enter Graphic Scores\n"
                "3. Enter Replay Scores\n"
                "4. Find the highest graphic score\n"
                "5. Find the highest replay value score\n"
                "6. Find the highest combined score\n"
                "7. Exit" << endl;
    }

    cin>>userInput;
    cin.ignore();

    if (userInput == 1){
        getGameName();
    }else if (userInput == 2){
        enterGraphicScores();
    }else if (userInput == 3){
        enterReplayScores();
    }else if (userInput == 4){
        getHighestGraphic();
    }else if (userInput == 5){
        getHighestReplay();
    }else if (userInput == 6){

    }else{
        cout << "Invalid choice! Try Again."<<endl;
    }
    menu();
}

int main(){
    menu();
}