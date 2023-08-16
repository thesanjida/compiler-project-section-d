#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool checkSyntax(const string &input) {
    ofstream tempFile("temp.cpp");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        return false;
    }
    tempFile << "#include <iostream>\nint main() {\n" << input << "\nreturn 0;\n}\n";
    tempFile.close();

    string compileCommand = "g++ temp.cpp -o temp.exe";
    int result = system(compileCommand.c_str());
    remove("temp.cpp");
    remove("temp.exe");
    return (result == 0);
}

int main() {
    ifstream inputFile("/Users/alvi/Documents/complier_design_lab/compiler--lab-project/project/input.txt");
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    vector<string> inputLines;
    string line;
    while (getline(inputFile, line)) {
        inputLines.push_back(line);
    }

    inputFile.close();
    cout << "Checking syntax..." << endl;
    for (const string &input: inputLines) {
        if (checkSyntax(input)) {
            cout << "Syntax is correct: " << input << endl;
        } else {
            cout << "Syntax is incorrect: " << input << endl;
        }
    }
    return 0;
}
