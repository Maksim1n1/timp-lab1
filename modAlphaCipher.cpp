#include "modAlphaCipher.h"

string modAlphaCipher::decoder(const std::string& cipher_st) // дешифратор
{
    string n_s = cipher_st;
    int razm, stroki, pos, a; 
    razm = cipher_st.size(); 
    stroki = (razm - 1) / newkey + 1;
    a = 0;
    for (int colum = newkey; colum > 0; colum--) {
        for (int line = 0; line < stroki; line++) { 
            pos = newkey*line+colum;
            if (pos-1 < razm) {
                n_s[pos-1] = cipher_st[a];
                a++;
            }
        }
    }
    return n_s;
}
string modAlphaCipher::coder(const string& open_st) // шифратор
{
    string n_s = open_st;
    int razm, stroki, pos, a;
    razm = open_st.size();
    stroki = (razm - 1) / newkey + 1;
    a = 0;
    for (int colum = newkey; colum > 0; colum--) { 
        for (int line = 0; line < stroki; line++) { 
            pos = colum+newkey*line;
            if (pos-1 < razm) {
                n_s[a] = open_st[pos-1];
                a++;
            }
        }
    }
    return n_s;
}
