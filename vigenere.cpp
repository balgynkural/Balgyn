#include <iostream>
#include <string>

using namespace std;

string encryptVigenere(string plaintext, string key) {
    string ciphertext = "";
    int keyLen = key.length();

    for (int i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLen];

        if (isalpha(plainChar)) {
            int plainIndex = tolower(plainChar) - 'a';
            int keyIndex = tolower(keyChar) - 'a';

            char encryptedChar = 'a' + (plainIndex + keyIndex) % 26;

            if (isupper(plainChar))
                encryptedChar = toupper(encryptedChar);

            ciphertext += encryptedChar;
        } else {
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

string decryptVigenere(string ciphertext, string key) {
    string plaintext = "";
    int keyLen = key.length();

    for (int i = 0; i < ciphertext.length(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % keyLen];

        if (isalpha(cipherChar)) {
            int cipherIndex = tolower(cipherChar) - 'a';
            int keyIndex = tolower(keyChar) - 'a';

            char decryptedChar = 'a' + (cipherIndex - keyIndex + 26) % 26;

            if (isupper(cipherChar))
                decryptedChar = toupper(decryptedChar);

            plaintext += decryptedChar;
        } else {
            plaintext += cipherChar;
        }
    }

    return plaintext;
}

int main() {
    string plaintext, key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    getline(cin, key);

    string ciphertext = encryptVigenere(plaintext, key);
    cout << "Encrypted ciphertext: " << ciphertext << endl;

    string decryptedText = decryptVigenere(ciphertext, key);
    cout << "Decrypted plaintext: " << decryptedText << endl;

    return 0;
}
