
/*
Made by
█▄─█▀▀▀█─▄█─█─█▄─▄█─▄─▄─█▄─▄▄─█░█░██─▄▄▄▄█▄─▄███▄─▄▄─█
██─█─█─█─██─▄─██─████─████─▄█▀█▄▄░██─██▄─██─██▀██─▄█▀█
▀▀▄▄▄▀▄▄▄▀▀▄▀▄▀▄▄▄▀▀▄▄▄▀▀▄▄▄▄▄▀▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀
*/
#include <bits/stdc++.h>
#include <ctime>
#include <Windows.h>

using namespace std;

class guessio{
public:
char select, difficulty;
string player_name;
int player_score = 0;

guessio(){
    cout<<"\t\t|Guessio|\t\t\n";
    cout<<"\t****Enter player name****\n";
    get_playerinfo();
    cout<<"\t\t**"<<player_name<<"**\n\t   Welcome to Guessio!\t\n";
    how_to_play();
    prompt();
}

void prompt(){//PROMPT MENU TO START
    string choice;
    cout<<"\tType 'start' to begin!:\n";
    cin>>choice;
    chce:
    cin>>choice;
    if(choice == "start"){
        start();
    }
    else{
        cout<<"type again: \n";
        goto chce;
    }
}

void start(){//THE TABLE OF SCRIBBLED WORDS WITH INPUT FUNCTIONS
    int seconds = 0;
    string ans[20];
    string words[20]={"STAR","SAIL","SIREN","RAIN",
    "ROPE","TOIL","TAIL","TOAST",
    "SIT","TON","SEA","LOSE",
    "TIRE","SNAIL","VAIN","REAL",
    "RISE","NOTE","LANE","DINE"};
    char alph[5][5]={
    {'S','R','P','O','T'},
    {'A','N','E','A','O'},
    {'I','T','E','V','R'},
    {'L','L','S','T','N'},
    {'G','D','I','A','E'}
    };
    for(int i = 0; i < 5; i++){//VIEWING THE TABLE
        for(int j = 0; j < 5; j++){
            cout<<" "<<alph[i][j];
        }
            cout<<"\n";
    }
    cout<<"And the time starts now!! Enter the words: \n";
    time_t startTime, endTime;
    for(int i = 0; seconds <= 20; seconds+=endTime-startTime, i++){
        if(seconds > 20){
            break;
        }
        else{
            time(&startTime);//TAKING INPUT WITHIN TIME FRAME
            cin>>ans[i];
            transform(ans[i].begin(),ans[i].end(),ans[i].begin(), ::toupper);
            time(&endTime);
            seconds += endTime-startTime;
        }
        cout<<"Time: "<<seconds<<"secs\n";
    }
    for(int i = 0; i < 20; i++){//CALCULATING TOTAL SCORE
        for(int j = 0; j < 20; j++){
            if(ans[i] == words[j]){
                player_score++;
            }
        }
    }
    cout<<"\t\tTIME IS UP!\n";
    cout<<"\t\tLet's have a look at your score!\n";
    cout<<"\t\tPlayer - "<<player_name<<"\n";
    cout<<"\t\tScore - "<<player_score<<"\n";

}

void how_to_play(){
    cout<<"\tThis is a word guessing game\n";
    cout<<"A table of scribbled alphabets will be given to you\n";
    cout<<"You will have to type out all possible words you can make\n";
    cout<<"\tout of those scribbled alphabets\n\n";
    cout<<"You have 20 SECS to write down all the words you can think of!\n";
    cout<<"\tYou'll be given extra time to write your last word\n";
    cout<<"\t*GOOD LUCK HAVE FUN!*\n";
}

void get_playerinfo(){
    cin>>player_name;
}

};


int main(){

guessio one;


    return 0;
}