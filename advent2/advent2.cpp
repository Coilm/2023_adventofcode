#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

using namespace std;

vector<pair<string, int>> objectSeen = {{"blue", 0}, {"red", 0}, {"green", 0}};


void main(){

    string line;
    ifstream file ("advent2.txt");

    if (file.is_open()){
        while (getline(file, line)){
        
        }
    }
    
    file.close();
}