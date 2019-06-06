/*
Team Name: Derpsters 
Team Members: Musamim Mubtakir & David Real
Case 3: Vigenere Cipher Decryption
*/

#include<iostream>
#include<string.h>
 
using namespace std;

//This function Encrypts the Message
string Encryption(string msg, string key) 
{ 
  string tmp_encrypt;
  for (int i = 0; i < msg.length(); i++)
  {
    int tmp = (msg[i] + key[i]) % 95;

  tmp += ' ';
  
  tmp_encrypt.push_back(tmp);
  } 

  return tmp_encrypt;
} 

//This function Decrypts the Message
string Decryption(string msg, string key) 
{ 
  string tmp_decrypt;
  for (int i = 0; i < msg.length(); i++)
  {
    int tmp = (msg[i] - key[i] + 126) % 95;

  tmp += ' ';
  
  tmp_decrypt.push_back(tmp);
  
  } 
  return tmp_decrypt;
}

//This function generates the key for the Encryption/Decryption
string generateKey(string str, string key) 
{ 
    int x = str.size();
  
    for (int i = 0; ; i++) 
    { 
        if (x == i) 
            i = 0; 
        if (key.size() == str.size()) 
            break; 
        key.push_back(key[i]); 
    } 
    return key; 
} 

//Main Function
int main()
{
    string msg = " ";
    string key = " ";
    string newKey;
    string newEncrypt, newDecrypt;
    string decryptMsg, decryptKey;
    int choice;

    cout << "Welcome, please choose an option from the menu below:" << endl << endl;

    do
    {
      cout << "Press 1: Encrypt a message" << endl;
      cout << "Press 2: Decrypt a message" << endl;
      cout << "Press 3: Exit the program" << endl;

      cout << "Enter choice here: ";
      cin >> choice;
      cin.ignore();

      while (choice < 1 || choice > 3)
      {
        cout << "\nInvalid choice, please choose an option from the menu above!" << endl;
        cout << "Enter your choice again: ";
        cin >> choice;
        cin.ignore();
      }

      if (choice == 1)  //Enryption
      {
        cout << "\nEnter your message here: ";
        getline(cin, msg);
        cout << "Enter the encryption key: ";
        getline(cin, key);
        
        newKey = generateKey(msg, key);
        newEncrypt = Encryption(msg, newKey);

        cout << "\nOriginal Message: " << msg;
        cout << "\nKey: " << key;
        cout << "\nNew Generated Key: " << newKey;
        cout << "\nEncrypted Message: " << newEncrypt << endl << endl;

        cout << "-----------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------" << endl << endl;
      }
      else if (choice == 2)  //Decryption
      {
        cout << "\nEnter your message here: ";
        getline(cin, msg);
        cout << "Enter the encryption key: ";
        getline(cin, key);
        
        newKey = generateKey(msg, key);
        newDecrypt = Decryption(msg, newKey);

        cout << "\nOriginal Message: " << msg;
        cout << "\nKey: " << key;
        cout << "\nNew Generated Key: " << newKey;
        cout << "\nDecrypted Message: " << newDecrypt << endl << endl;

        cout << "-----------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------" << endl << endl;
      }
      else  //Exits the program
      cout << "\nThank you for using the program!\n";
      
    }
    while (choice != 3);

	return 0;
}
