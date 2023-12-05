#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int countWords(const std::string& fileName) {
    ifstream file(fileName);
    
    if (!file.is_open()) {
        cout << "Error: Unable to open file '" << fileName << "'\n";
        return -1;
    }

    string line;
    int wordCount = 0;

    while (std::getline(file, line)) {
        stringstream stream(line);
        string word;
        
        while (stream >> word) {
            wordCount++;
        }
    }

    file.close();
    return wordCount;
}

int main() {
    string fileName;
    cout << "Enter the name of the text file: ";
    cin >> fileName;

    int totalWords = countWords(fileName);

    if (totalWords >= 0) {
        cout << "\nTotal number of words in '" << fileName << "': " << totalWords << std::endl;
    }

    return 0;
}
