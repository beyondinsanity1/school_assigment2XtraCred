#include <iostream>
#include <string>

using namespace std;

struct gameInfo {
    string gameName;
    int replayScore;
    int graphicScore;
};
        
gameInfo games [5] {};

//function getGameName
void getGameName(){
    for (int i = 0; i < 5; ++i) {
        cout << "enter a game name" << endl;
        getline(cin,(games[i].gameName));
    }
    for (int i = 0; i < 5; ++i) {
        cout << games[i].gameName << endl;
    }
}

//function getReplayScores


//function getGraphicScores


//function getHighestReplay


//function getHighestGraphic


//function menu


int main(){
    getGameName();
}