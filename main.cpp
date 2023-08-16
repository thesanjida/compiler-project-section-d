#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool checkError(const string &checkFile) {
    ofstream tempFile("temp.cpp");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        return false;
    }
    tempFile << "#include <iostream>\nint main() {\n" << checkFile << "\nreturn 0;\n}\n";
    tempFile.close();

    string compileCommand = "g++ temp.cpp -o temp.exe";
    int result = system(compileCommand.c_str());
    remove("temp.cpp");
    remove("temp.exe");
    return (result == 0);
}

int main() {
    ifstream localFile("C:\\Users\\sanj\\Documents\\GitHub\\compiler-project-section-d\\input.txt");
    if (!localFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    vector<string> inputLines;
    string line;
    while (getline(localFile, line)) {
        inputLines.push_back(line);
    }

    localFile.close();
    cout << "Checking..." << endl;
    for (const string &checkFile: inputLines) {
        if (checkError(checkFile)) {
            cout << "correct: " << checkFile << endl;
        } else {
            cout << "incorrect: " << checkFile << endl;
        }
    }
    return 0;
}
