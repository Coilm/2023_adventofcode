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

bool checkSymbol(vector<string> mat, int line_idx, int char_idx, set<char> symbols){
    
        for(int line_shift : set<int> {0,1,-1}){
            for(int char_shift: set<int> {0,1,-1}){

                // Check for out of bound condition
                bool c1 = ((line_idx + line_shift) >= mat.size());
                bool c2 = ((line_idx + line_shift) < 0);
                bool c3 = ((char_idx + char_shift) >= mat[line_idx].size());
                bool c4 = ((char_idx + char_shift) < 0);
                bool c = (c1 || c2 || c3 || c4);

                if(c)
                    continue;
                else{
                    for (char symbol : symbols){
                        if(mat[line_idx + line_shift][char_idx + char_shift] == symbol)
                            return true;
                    }
                }
            }
        }

    return false;

}

int findValidNumber(vector<string> mat, set<char> symbols){
    bool nextToSymbol = false;
    char c;
    string digits = "";
    int sum = 0;
    for (int line_idx=0; line_idx < mat.size(); line_idx++){
        for(int char_idx=0; char_idx < mat[line_idx].size(); char_idx ++){
            c = mat[line_idx][char_idx];
            if(isdigit(c)){
                digits += c;
                if(!nextToSymbol){
                    nextToSymbol = checkSymbol(mat, line_idx, char_idx, symbols);
                }
            }
            else{
                if(nextToSymbol && digits != ""){
                    sum += stoi(digits);
                }
                digits = "";
                nextToSymbol = false;
            }
        }
            if(nextToSymbol && digits != ""){
                sum += stoi(digits);
            }
            digits = "";
            nextToSymbol = false;
    }

    return sum;
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

    sum = findValidNumber(matrixText, symbols);

    cout << sum;
}