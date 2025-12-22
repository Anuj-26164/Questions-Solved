#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> cleanCode(const vector<string>& code) {
    vector<string> result;
    bool inBlockComment = false;
    
    for (string line : code) {
        string cleanLine;
        bool inLineComment = false;
        
        for (size_t i = 0; i < line.size(); ++i) {
            if (!inBlockComment && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {
                inBlockComment = true;
                ++i;
            } else if (inBlockComment && i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {
                inBlockComment = false;
                ++i;
            } else if (!inBlockComment && !inLineComment && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') {
                inLineComment = true;
            } else if (!inBlockComment && !inLineComment) {
                cleanLine += line[i];
            }
        }
        
        if (!cleanLine.empty()) {
            result.push_back(cleanLine);
        }
    }
    
    return result;
}

int main() {
    vector<string> code;
    string line;
    while (getline(cin, line)) {
        code.push_back(line);
    }
    
    vector<string> cleanedCode = cleanCode(code);
    
    for (const string& line : cleanedCode) {
        cout << line << "\n";
    }
    
    return 0;
}