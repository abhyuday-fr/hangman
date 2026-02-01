#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;
string words();
void man(int num);
int main(){
    int live=6;
    string word,word1,opt;
    do{
        word=words();
        word1=words();
        for(int i=0;i<word.length();i++){
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                continue;
            }
            else{
                word[i]='_';
            }
        }
        cout << word << " " << '\n';
        cout << "Lives: " << live<< '\n';
    do{
    int flag=0;
    char player;
    cout << "Guess the letter: ";
    cin >> player;
    for(int i=0;i<word1.length();i++){
        if(player==word1[i]){
            word[i]=word1[i];
            flag=1;
            man(live);
        }
    }
    cout << word<< '\n';
    if (flag==0){
        live=live-1;
        man(live);
    }
    cout << "\nLives: " << live << '\n';

    if(word!=word1 && live<=0){
        cout << "You lost :(" << '\n';
        cout << "The word was: " << word1 << '\n';
        break;
    }
    else if(word==word1){
        cout << "You won!! :D" << '\n';
        break;
    }
    }while(live>0);
    cout << "Wanna play again?(y/n): ";
    cin >> opt;
    }while(opt[0]=='y' || opt[0]=='Y');
    
    system("Pause");
    return 0;
}
string words(){
    vector <string> words={"hitman","love","college","school","horse","collector","hate","christmas","holiday","memory"};
    string word;
    srand(time(0));
    word=words[rand()%(words.size())];
    return word;
}
void man(int num){
    vector<string> hang={"-------+","       O","      /"," \\","       |","      /"," \\"};
    for(int i=0;i<=6-num;i++){
        if(i==2 || i==5){
            cout << hang[i] << "";
        }
        else{
            cout << hang[i] << "\n";
        }
    }
    cout << '\n';
}