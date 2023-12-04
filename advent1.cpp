#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

using namespace std;

int getDigit(string line, int idx){
    
    vector<pair<string, int>> conversions = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    if (isdigit(line[idx])){
        return line[idx] - '0';
    }

    for (const auto& conversion : conversions){
        if (line.substr(idx, conversion.first.size()) == conversion.first){
            return conversion.second;
        }
    }

    return -1;

}

int computeDigit(string line){
    int digit = -1;
    int firstdigit = -1;
    int lastdigit = -1;

    for (int idx ; idx < line.size() ; idx++){
        digit = getDigit(line, idx);
        if (digit != -1){
            if (firstdigit == -1){
                firstdigit = digit;
            }
            lastdigit = digit;
        }
    }
    cout << firstdigit << " " << lastdigit << endl << endl;
    return firstdigit * 10 + lastdigit;
}


int main()
{
    // translate_string_to_num("onehellonineheight");
    
    ifstream file ("advent1.txt");
    int sum = 0;
    string line;

    if (file.is_open()){
        while (getline(file, line)){
            cout << line << endl;
            sum += computeDigit(line);
        }
    }
    file.close();

    cout << sum << std::endl;

}