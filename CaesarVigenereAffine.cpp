#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Caesar
string caesarEncrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char(int(text[i] + shift - 65) % 26 + 65);
        else
            result += char(int(text[i] + shift - 97) % 26 + 97);
    }

    return result;
}

string caesarDecrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char(int(text[i] - shift - 65 + 26) % 26 + 65);
        else
            result += char(int(text[i] - shift - 97 + 26) % 26 + 97);
    }

    return result;
}

// Vigenere
string generateKey(string str, string key) {
    int x = str.size();

    for (int i = 0; ; i++) {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string cipherText(string str, string key) {
    string cipher_text;

    for (int i = 0; i < str.size(); i++) {
        char x = (str[i] + key[i]) %26;

        x += 'A';

        cipher_text.push_back(x);
    }
    return cipher_text;
}

string originalText(string cipher_text, string key) {
    string orig_text;

    for (int i = 0 ; i < cipher_text.size(); i++) {
        char x = (cipher_text[i] - key[i] + 26) %26;

        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

// Affine
const int m = 26;

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

string encryptMessage(string msg, int a, int b) {
    string cipher = "";
    for (int i = 0; i < msg.length(); i++) {
        if(msg[i]!=' ') 
            cipher = cipher + (char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
        else
            cipher += msg[i];    
    }
    return cipher;
}

string decryptCipher(string cipher, int a, int b) {
    string msg = "";
    int a_inv = modInverse(a, m);
    for (int i = 0; i < cipher.length(); i++) {
        if(cipher[i]!=' ')
            msg = msg + (char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
        else
            msg += cipher[i]; 
    }
    return msg;
}

int main() {
	string text = "HELLO";
    int shift = 4; // Caesar
    string keyword = "KEY"; // Vigenere
	int a = 5; // Affine
	int b = 8;
	
    cout << "Text : " << text;
    
    // Caesar
    string encrypt = caesarEncrypt(text, shift);
    cout << "\n----------- CAESAR ----------" << endl;
    cout << "\nShift: " << shift;
    cout << "\nCipher: " << encrypt;
    cout << "\nDecipher: " << caesarDecrypt(encrypt, shift) << endl;
    
    // Vigenere
    string key = generateKey(text, keyword);
    string cipher_text = cipherText(text, key);
    cout << "\n----------- VIGENERE --------" << endl;
    cout << "\nKey : " << keyword;
    cout << "\nCipher Text : " << cipher_text;
    cout << "\nDecrypted Text : " << originalText(cipher_text, key) << endl;

    // Affine
    string cipherText = encryptMessage(text, a, b);
    cout << "\n----------- AFFINE ----------" << endl;
    cout << "\nEncrypted Message: " << cipherText;
    cout << "\nDecrypted Message: " << decryptCipher(cipherText, a, b) << endl;
    return 0;
}

