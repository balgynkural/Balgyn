#include <iostream>
#include <string>
#include <openssl/sha.h>

using namespace std;

string sha256(const string& str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.length());
    SHA256_Final(hash, &sha256);

    string hashedString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        hashedString += hash[i];
    }

    return hashedString;
}


void signUp()
{
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    string hashedPassword = sha256(password);

    cout << "Sign-up successful!" << std::endl;
}


void signIn()
{
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    
    string hashedPassword = sha256(password);


    if (hashedPassword == storedHashedPassword)
    {
        cout << "Sign-in successful!" << endl;
    }
    else
    {
        cout << "Invalid username or password." << endl;
    }
}

int main()
{
    int choice;
    cout << "1. Sign up" << endl;
    cout << "2. Sign in" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        signUp();
    }
    else if (choice == 2)
    {
        signIn();
    }
    else
    {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}
