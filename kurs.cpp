#include <iostream>
#include <string>
#include "windows.h"
using namespace std;
string removeSpaces(string tx)
{
    int length = tx.length();
    for (int i = 0; i < length; i++) 
    {
        if (tx[i] == ' ')
        {
            tx.erase(i, 1);
            
        }
    }
    return tx;
}
string extkey(string tx, string key) 
{
    for (int i = 0; i < tx.length(); i++)
    {
        if (tx[i] == ' ')
        {

        }
    }
    if (key.length() >= tx.length())
        return key;
    else 
    {
        int txleng = tx.length() - key.length();
        int keyleng = key.length();
        while (txleng >= keyleng) 
        {
            key += key;
            txleng -= keyleng;
        }
        key += key.substr(0, txleng);
        return key;
    }
}
string encrypt(string key, string tx)
{
    string res = "";
    for (int i = 0; i < tx.length(); i++)
    {
        res += (char)(((int)tx[i] - 'а' + (int)key[i] - 'а') % 32) + 'а';
    }
    return res;
}
string decrypt(string key, string res)
{
    
    string tx = "";
    for (int i = 0; i < res.length(); i++)
       tx += (char)((((int)tx[i] - 'а' - (key[i] - 'а')) + 32) % 32) + 'а';
    return tx;
}
int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string tx;
    cout << "Введіть текст для шифрування:" << endl;
    getline(cin, tx);
    tx = removeSpaces(tx);
    string key;
    cout << "Введіть ключ:" << endl;
    cin >> key;
    key = extkey(tx, key);
    encrypt(tx, key);
    string res = encrypt(key, tx);
    cout << res << endl;
    decrypt(res, key);
    cout << tx << endl;
}