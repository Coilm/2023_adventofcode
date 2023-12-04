#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

using namespace std;

vector<pair<string, int>> objectSeen = {{"blue", 0}, {"red", 0}, {"green", 0}};

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


int findValidGameID(string line){
    const int RED = 12;
    const int GREEN = 13;
    const int BLUE = 14;

    string token;
    string c;
    vector<string> tmp;

    tmp = splitString(line, ':');
    int gameId = stoi(splitString(tmp[0], ' ')[1]);
    vector<string> results = splitString(tmp[1], ';');

    for (string result: results){
        vector<string> colors = splitString(result, ',');

        for(string color: colors){
            vector<string> split = splitString(color, ' ');

            int val = stoi(split[1]);
            c = split[2];

            if (c.find("blue") != string::npos){
                if (val > BLUE)
                    return -1;
            }
            if(c.find("red") != string::npos){
                if (val > RED)
                    return -1;
            }
            if(c.find("green") != string::npos){
                if (val > GREEN)
                    return -1;
            }
        }
    }
    return gameId;
}

int main(){
    cout << "Hello World!" << endl;
    string line;
    int id;
    int sum = 0;
    ifstream file ("advent2.txt");

    if (file.is_open()){
        while (getline(file, line)){
            id = findValidGameID(line);
            if (id != -1){
                sum += id;
            }
        }
    }

    file.close();

    cout << sum;
}