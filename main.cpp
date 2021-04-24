#include "modAlphaCipher.h"
bool isValid(const string& s)
{
    for(const auto &c:s)
        if (!isalpha(c) )
            return false;
    return true;
}
int main(int argc, char **argv)
{
    int key;
    string st;
    unsigned operation;
    cout<<"Введите ключ: ";
    cin>>key;
    if (!cin.good()) {
        clog<<"Ключ не корректен\n";
        return 1;
    }
    cout<<"Ключ введен\n";
    modAlphaCipher cipher(key);
    do {
        cout<<"Выбор операции (0-выход, 1-шифрование, 2-дешифрование): ";
        cin>>operation;
        if (operation > 2) {
            cout<<"Некорректная операция\n";
        } else if (operation >0) {
            cout<<"Ввод текста: ";
            cin>>st;
            if (isValid(st)) {
                if (operation==1) {
                    cout<<"Зашифрованная строка: "<<cipher.coder(st)<<endl;
                } else {
                    cout<<"Дешифрованная строка "<<cipher.decoder(st)<<endl;
                }
            } else {
                cout<<"Некорректная строка\n";
            }
        }
    } while (operation!=0);

    return 0;
}