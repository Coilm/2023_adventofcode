#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

using namespace std;

int compute_digits(string line){
    int firstdigit = 0;
    int lastdigit = 0;
    for (int i = 0 ; i < line.size() ; i++){
        if (isdigit(line[i])){

            if (firstdigit == 0){
                firstdigit = int(line[i] - '0');
                lastdigit = int(line[i] - '0');
            }
            else{
                lastdigit = int(line[i] - '0');
            }
        }
    }
    cout << firstdigit << lastdigit << endl << endl;
    return firstdigit * 10 + lastdigit;
}

string translate_string_to_num(string line){

    vector<vector<string>> conversion = {{"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};
    string tmp;
    cout << line << endl;
    for (int c = 0 ; c < line.size() ; c++){
        for (int i = 0 ; i < conversion.size() ; i ++){
            if (c + conversion[i][0].size() > line.size()){
                break;
            }

            if (line.substr(c, conversion[i][0].size()) == conversion[i][0]){

                line = line.replace(c, conversion[i][0].size(), conversion[i][1]);
                
            }
        }
    }
    cout << line << endl ;
    return line;
}


int main()
{
    // translate_string_to_num("onehellonineheight");
    
    ifstream file ("advent1.txt");
    int sum = 0;
    string line;

    if (file.is_open()){
        while (getline(file, line)){
            line = translate_string_to_num(line);
            sum += compute_digits(line);
        }
    }
    file.close();

    cout << sum << std::endl;

}