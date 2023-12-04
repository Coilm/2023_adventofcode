#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <set>

using namespace std;

set<char> findSymbols(vector<string> mat){
    set<char> symbols;

    for(string line: mat){
        for(char c: line){
            if(!isdigit(c)){
                if (c != '.'){
                    symbols.insert(c);
                }
            }
        }
    }
    return symbols;

}

int main(){

    vector<string> matrixText;
    set<char> symbols;
    string line;
    int sum = 0;
    ifstream file ("advent3.txt");

    if (file.is_open()){
        while (getline(file, line)){
            matrixText.push_back(line);
        }
    }
    file.close();

    symbols = findSymbols(matrixText);

    for (int line_idx; matrixText.size(); line_idx++){
        for (char char_idx; matrixText[line_idx].size(); char_idx++){
            if(symbols.find(matrixText[line_idx][char_idx]) != symbols.end()){
                //TODO: find the numbers next to the symbol
            }
        }
    }

    // cout << sum;
}