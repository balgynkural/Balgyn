#include <iostream>
#include <string>
using namespace std;

string encryptVigenere(string plaintext, string key) {
    string ciphertext;
    int keyLength = key.length();

    for (int i = 0; i < plaintext.length(); ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];
        char encryptedChar = 'A' + (plainChar + keyChar) % 26;
        ciphertext += encryptedChar;
    }

    return ciphertext;
}

string decryptVigenere(string ciphertext, string key) {
    string plaintext;
    int keyLength = key.length();

    for (int i = 0; i < ciphertext.length(); ++i) {
        char encryptedChar = ciphertext[i];
        char keyChar = key[i % keyLength];
        char decryptedChar = 'A' + (encryptedChar - keyChar + 26) % 26;
        plaintext += decryptedChar;
    }

    return plaintext;
}

int main() {
    string plaintext = "HELLO";
    string key = "KEY";

    string encryptedText = encryptVigenere(plaintext, key);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = decryptVigenere(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
