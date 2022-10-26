#include <iostream>
#include <string>

using namespace std;

struct gameInfo {
    string gameName;
    int replayScore;
    int graphicScore;
    int combinedScore;
};

bool firstTimeMenu = true;
const int gameCount = 3;

void enterGameNames();
void enterReplayScores();
void enterGraphicScores();
void getHighestGraphic();
void getHighestCombined();
void getHighestReplay();
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


    cout << "================================"
            "\nYour game list contains: "<<endl;
    for (int i = 0; i < gameCount; i++) {
        cout << games[i].gameName << "--> Graphic Score: "<< games[i].graphicScore << "  Replay Score: " << games[i].replayScore << endl;
    }
    menu();
}

////////////////////////////////////////////////
//function enterGameNames
void enterGameNames(){
    for (int i = 0; i < gameCount; i++) {
        cout << "enter a game name" << endl;
        getline(cin,(games[i].gameName));
    }


    cout << "================================"
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
    for (int i = 0; i < gameCount; ++i) {
        cout << "enter the graphic score for " << games[i].gameName << ":" <<endl;
        cin >> games[i].graphicScore;
    }

    menu();
}


////////////////////////////////////////////////
//function getHighestGraphic
void getHighestGraphic(){
    int highestGraphic {games[0].graphicScore};
    string highestGraphicName {games[0].gameName};

    cout << highestGraphic <<endl;

    for (int i = 0; i < gameCount; ++i) {
        if(highestGraphic < games[i].graphicScore){
            highestGraphic = games[i].graphicScore;
            highestGraphicName = games[i].gameName;
        }else if (highestGraphic == games[i].graphicScore){
            highestGraphicName = games[i].gameName;
        }
    }

    cout << highestGraphicName << " - " << highestGraphic <<endl;
    menu();
}

////////////////////////////////////////////////
//function getHighestReplay
void getHighestReplay(){

    string highestReplayName {games[0].gameName};
    int highestReplayScore {games[0].graphicScore};

    for (int i = 0; i < gameCount; ++i) {
        if(highestReplayScore < games[i].replayScore){
            highestReplayScore = games[i].replayScore;
            highestReplayName = games[i].gameName;
        }else if (highestReplayScore == games[i].replayScore){
            highestReplayName = games[i].gameName;
        }
    }
    cout << highestReplayName << " - " << highestReplayScore <<endl;

    menu();
}


////////////////////////////////////////////////
//function getHighestCombined
void getHighestCombined(){

    int highestCombinedScore = 0;
    string highestCombinedName;

    for (int i = 0; i < gameCount; ++i) {
        games[i].combinedScore = games[i].graphicScore + games[i].replayScore;
    }

    for (int i = 0; i < gameCount; ++i) {
        if (games[i].combinedScore > highestCombinedScore){
            highestCombinedScore = games[i].combinedScore;
            highestCombinedName = games[i].gameName;
        }else if (games[i].combinedScore == highestCombinedScore){
            highestCombinedName = games[i].gameName;
        }
    }

    cout << highestCombinedName << " - " << highestCombinedScore <<endl;

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
                "7. Enter All Game Info at once\n"
                "8. Exit" << endl;
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
                "7. Enter All Game Info at once\n"
                "8. Exit" << endl;
    }

    cin>>userInput;
    cin.ignore();

    if (userInput == 1){
        enterGameNames();
    }else if (userInput == 2){
        enterGraphicScores();
    }else if (userInput == 3){
        enterReplayScores();
    }else if (userInput == 4){
        getHighestGraphic();
    }else if (userInput == 5){
        getHighestReplay();
    }else if (userInput == 6){
        getHighestCombined();
    }else if (userInput == 7){
        getAllGameInfo();
    }else if (userInput == 8){
        cout << "Terminating the program!" << endl;
        EXIT_SUCCESS;
    }else{
        cout << "Invalid choice! Try Again."<<endl;
        menu();
    }
}

int main(){
    menu();
}
