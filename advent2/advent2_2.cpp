#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <limits>

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

vector<int> findLowestAmountCube(string line){

    string c;
    vector<string> tmp;
    vector<int> count = {0,0,0};

    tmp = splitString(line, ':');
    int gameId = stoi(splitString(tmp[0], ' ')[1]);
    vector<string> results = splitString(tmp[1], ';');

    for (string result: results){
        vector<string> colors = splitString(result, ',');

        for(string color: colors){
            vector<string> split = splitString(color, ' ');

            int val = stoi(split[1]);
            c = split[2];

            if(c.find("red") != string::npos){
                if (val > count[0]){
                    count[0] = val;
                }
            }
            if(c.find("green") != string::npos){
                if (val > count[1]){
                    count[1] = val;
                }
            }
            if (c.find("blue") != string::npos){
                if (val > count[2]){
                    count[2] = val;
                }
            }
        }
    }
    return count;//count[0]*count[1]*count[2];
}

int main(){

    string line;
    vector<int> vals;
    int mul;
    int sum = 0;
    ifstream file ("advent2.txt");

    if (file.is_open()){
        while (getline(file, line)){
            vals = findLowestAmountCube(line);
            mul = vals[0]*vals[1]*vals[2];
            sum += mul;
        }
    }

    file.close();

    cout << sum;
}