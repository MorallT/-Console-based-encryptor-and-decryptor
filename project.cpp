#include <Windows.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

string crypto(string input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] += 15;
    }
    return input;
}

string decrypto(string input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] -= 15;
    }
    return input;
}

void encodeToFile(const string &input, const string &filename) {
    string fullFilename = filename + ".txt";
    ofstream outFile(fullFilename.c_str(), ios::binary);
    if (!outFile) {
        cout << "Error 001" << endl;
        return;
    }
    string encoded = crypto(input);
    outFile << encoded;
    outFile.close();
    cout << "Coding file: " << fullFilename << endl;
    
}

void changePassword(const string &filename) {
    string fullFilename = filename + ".txt";
    ifstream inFile(fullFilename.c_str(), ios::binary);
    if (!inFile) {
        cout << "Error 002: File not found." << endl;
        return;
    }
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();
    
    string currentPassword = decrypto(content);
    cout << "Enter current password: ";
    string inputPassword;
    getline(cin, inputPassword);
    
    if (inputPassword != currentPassword) {
        cout << "Error: Incorrect password." << endl;
        return;
    }
    
    cout << "Enter new password: ";
    string newPassword;
    getline(cin, newPassword);
    
    encodeToFile(newPassword, filename);
    cout << "Password successfully changed." << endl;
}




void decodeFromFile(const string &filename) {
    string fullFilename = filename + ".tx";
    ifstream inFile(fullFilename.c_str(), ios::binary);
    if (!inFile) {
        cout << "Error 002" << endl;
        return;
    }
    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();
    string decoded = decrypto(content);
    cout << "Decoding password: " << decoded << endl;
}

int main() {
    string v;
    cout << "Choose  (1 - encrypt, 2 - decrypt, 3-change ): ";
    getline(cin, v);
    
    string filename;
    cout << "File name: ";
    getline(cin, filename);

    if (v == "1") {
        string a;
        cout << "Password: ";
        getline(cin, a);
        encodeToFile(a, filename);
    }
    else if (v == "2") {
        decodeFromFile(filename);
    }
    else if (v == "3") {
        changePassword(filename);
    }
    else {
        cout << "Error choose corect" << endl;
    } while (true);
    cout << "Exiting program..." << endl;
    system("pause");
    return 0;
}
