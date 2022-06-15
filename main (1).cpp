#include<iostream>
using namespace std;
 
string generateKey(string pt, string key)
{
    int k = pt.size();
 
    for (int i = 0; ; i++)
    {
        if (k == i)
            i = 0;
        if (key.size() == pt.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string encryption(string pt, string key)
{
    string cipher_text;
 
    for (int i = 0; i < pt.size(); i++)
    {
        char k = (pt[i] + key[i]) %26;
 
        k += 'A';
 
        cipher_text.push_back(k);
    }
    return cipher_text;
}

string decryption(string cipher_text, string key)
{
    string orig_text;
 
    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        char k = (cipher_text[i] - key[i] + 26) %26;
 
        k += 'A';
        orig_text.push_back(k);
    }
    return orig_text;
}
 
void input(string &str,string &keyword)
{
    cout<<"Enter text-";
    cin>>str;
    cout<<"Enter keyword-";
    cin>>keyword;
    cout << "\nPlaintext : " << str;
    cout << "\nKeyword: " << keyword<<"\n";
}

int main()
{
    string str;
    string keyword;
    char a;
    cout<<"ENTER [E] FOR ENCRYPTION OR [D] FOR DECRYPTION:";
    cin>>a;
    input(str,keyword);
    string key = generateKey(str, keyword);
    if(a=='E'){
    	string cipher_text = encryption(str, key);
    	cout << "Ciphertext : "<< cipher_text<< "\n"; 
  }
    else if(a=='D')
    cout << "Decrypted Text : "<< decryption(str, key);
    return 0;
}