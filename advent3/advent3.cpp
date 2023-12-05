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

int findDigitR(vector<string> mat, int line_idx, int char_idx){
    string digit = "";

    for (int i = char_idx + 1; i < mat[line_idx].size() && isdigit(mat[line_idx][i]); i++){
        digit += mat[line_idx][i];
    }

    if(digit != "")
        return stoi(digit);
    else
        return 0;
}

int findDigitL(vector<string> mat, int line_idx, int char_idx){
    string digit = "";

    for (int i = char_idx - 1; i >= 0 && isdigit(mat[line_idx][i]); i--){
        digit = mat[line_idx][i] + digit;
    }

    if(digit != "")
        return stoi(digit);
    else
        return 0;
}

int findDigitUD(vector<string> mat, int line_idx, int char_idx){
    string digitstr = "";
    int digit = 0;

    if (line_idx < 0 || line_idx > mat.size())// Check for out-of-bound.
        return 0;


    // Find if there is a number directly above/below
    if (isdigit(mat[line_idx][char_idx])) {
        for (int i = char_idx; i < mat[line_idx].size() && isdigit(mat[line_idx][i]); i++) {
            digitstr += mat[line_idx][i];
        }
        for (int i = char_idx - 1; i > 0 && isdigit(mat[line_idx][i]); i--) {
            digitstr = mat[line_idx][i] + digitstr;
        }
    }

    if (digitstr != ""){ // If we found a number above/below, then there cannot be a number diagonally (since the digit would be part of the number directly above/below)
        return stoi(digitstr);
    }

    // Check if there is number diagonally
    else{
        for (int i = char_idx + 1; i < mat[line_idx].size() && isdigit(mat[line_idx][i]); i++) {
            digitstr += mat[line_idx][i];
        }
        if (digitstr != ""){
            digit += stoi(digitstr);
            digitstr = "";
        }
        for (int i = char_idx - 1; i > 0 && isdigit(mat[line_idx][i]); i--) {
            digitstr = mat[line_idx][i] + digitstr;
        }
        if (digitstr != ""){
            digit += stoi(digitstr);
        }

        return digit;
    }

}

int findNeighbouringNumbers(vector<string> mat, int line_idx, int char_idx){
    int sum = 0;

    // Find if there is a number to the EAST of the symbol
    sum += findDigitR(mat, line_idx, char_idx);
    sum += findDigitL(mat, line_idx, char_idx);
    sum += findDigitUD(mat, line_idx + 1, char_idx);
    sum += findDigitUD(mat, line_idx - 1, char_idx);
    
    return sum;
}



int main(){

    vector<string> matrixText;
    vector<vector<bool>> boolMatrix;
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

    vector<bool> boolLine(matrixText[0].size(), false);
    for (string line : matrixText){
        boolMatrix.push_back(boolLine);
    }

    for (int line_idx = 0; line_idx < matrixText.size(); line_idx++){
        for (int char_idx = 0; char_idx < matrixText[line_idx].size(); char_idx++){
            if(symbols.find(matrixText[line_idx][char_idx]) != symbols.end()){
                sum += findNeighbouringNumbers(matrixText, line_idx, char_idx);
            }
        }
    }

    cout << sum;
}