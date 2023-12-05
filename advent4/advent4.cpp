#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> splitString(string line, char token){
    string word = "";
    vector<string> result;
    for(auto &c : line){
        if (c == token){
            result.push_back(word);
            word = "";
        }
        else{
            word += c;
        }
    }
    result.push_back(word);

    return result;
} 

int computeScore(vector<string> game){
    vector<int> winning_values; 
    vector<int> game_values; 
    int winning_count = 0;

    for (string val: splitString(game[0], ' ')){
        if (val != "")
            winning_values.push_back(stoi(val));
    }
    for (string val: splitString(game[1], ' ')){
        if (val != "")
            game_values.push_back(stoi(val)); 
    }

    for(int val : game_values){
        if (find(winning_values.begin(), winning_values.end(), val) != winning_values.end())
            winning_count++;
    }

    if (winning_count == 0)
        return 0;
    return pow(2,winning_count - 1);
}

int main(){

    string line;
    int sum = 0;
    ifstream file ("advent4.txt");
    vector<string> game;

    if (file.is_open()){
        while (getline(file, line)){
            game = splitString(splitString(line, ':')[1], '|');
            sum += computeScore(game);
        }
    }

    file.close();

    cout << sum;
}