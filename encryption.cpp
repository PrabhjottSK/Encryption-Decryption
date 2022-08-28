/*
Author: Prabhjott Singh Kusrath
Project: Encryption using Caesar and Vigenere ciphers.
*/

#include <iostream>
using namespace std;

char shiftChar(char c, int rshift)
{  
    if (!isalpha(c))
    {
        return c;
    }
    if(c >= 'A' && c <= 'Z')
    { 
        c = 'A' + ((c - 'A') + (rshift + 26)) % 26;
    }
    if(c >= 'a' && c <= 'z')
    {  
        c = 'a' + ((c - 'a') + (rshift + 26)) % 26;
    }
    return c;
}

char dcrypt_shiftChar(char c, int rshift)
{   
    if(c >= 'A' && c <= 'Z')
    {
        c = 'A' + (c - 'A' - rshift + 26) % 26;
    }
    if(c >= 'a' && c <= 'z')
    {
        c = 'a' + (c - 'a' - rshift + 26) % 26;
    }
    return c;
}

string encryptCaesar(string plaintext, int rshift)
{
    string result;
    for (int i = 0; i < plaintext.size(); i++)
    {
        result = result + shiftChar(plaintext[i], rshift); 
    }
    return result;
}

string decryptCaesar(string ciphertext, int rshift)
{
    string result = encryptCaesar(ciphertext, -1*rshift); 
    return result;
}

string encryptVigenere(string plaintext, string keyword)
{
    int ct = 0;
    for(int i = 0; i < plaintext.length(); i++)
    {
        if(isalpha(plaintext[i]))
        {
            if(ct == (keyword.length())) // If the counter is equal to the length of the keyword then, it's gonna reset the counter to 0. Allows to text wrap.
            {    
                ct = 0;
            }
            plaintext[i] = shiftChar(plaintext[i], keyword[ct] - 97);
            ct += 1;
        }
        else
        {
            plaintext[i] = plaintext[i];
        }
    }
    return plaintext;
}

string decryptVigenere(string ciphertext, string keyword)
{
    int ct = 0;

    for(int i = 0; i < ciphertext.length(); i++)
    {
        if(isalpha(ciphertext[i]))
        {  
            if(ct == (keyword.length()))
            { 
                ct = 0;
            }
            ciphertext[i] = dcrypt_shiftChar(ciphertext[i], keyword[ct] - 97);
            ct += 1;
        }
        else
        {
            ciphertext[i] = ciphertext[i];
        }
    }
    return ciphertext;   
}
 
int main()
{
    string input; string kw; int shift;

    cout << "Enter plaintext: ";
    getline(cin, input);

    // Output block for Caesar.
    cout << "= Caesar =" << endl;
    cout << "Enter shift: ";
    cin >> shift;
    string c_msg = encryptCaesar(input, shift);
    cout << "Ciphertext: " << c_msg << endl; 
    cout << "Decrypted: " << decryptCaesar(c_msg, shift) << endl;


    // Output block for Vigenere.
    cout << "= Vigenere =" << endl;
    cout << "Enter Keyword: ";
    cin >> kw;
    string v_msg = encryptVigenere(input, kw);
    cout << "Ciphertext: " << v_msg << endl;
    cout << "Decrypted: " << decryptVigenere(v_msg, kw) << endl;  // Since the decrypt function needs to take in cypertext, I stored in value of v_msg, and put that in function call.
}