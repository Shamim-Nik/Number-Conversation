#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
typedef vector<int> vct;
inline int HexadecimalToDecimal(vct Arr, int len) {
    ll d = 0;
    int p = 0;
    for (int i = len - 1; i >= 0; i--)
        d = d + Arr[i] * pow(2, p),
                p++;
    return d;
}
inline int octal(ll N) {
    if (N == 0)
        return N;
    return N % 8 + 10 * octal(N / 8);
}
void HexadecimalToOctal(vct Arr, int len) {
    ll d = 0;
    int p = 0;
    for (int i = len - 1; i >= 0; i--)
        d = d + Arr[i] * pow(2, p),
                p++;
    cout << "Octal Number = " << octal(d) << endl;
}
void hexadecimal(vct Arr,int len) {
    ll d = 0;
    int p = 0;
    for (int i = len - 1; i >= 0; i--)
        d = d + Arr[i] * pow(2, p),
                p++;
    p = 0;
    vector<char> ch;
    while (d != 0) {
        p = d % 16;
        switch (p) {
            case 0: ch.push_back('0'); break;
            case 1: ch.push_back('1'); break;
            case 2: ch.push_back('2'); break;
            case 3: ch.push_back('3'); break;
            case 4: ch.push_back('4'); break;
            case 5: ch.push_back('5'); break;
            case 6: ch.push_back('6'); break;
            case 7: ch.push_back('7'); break;
            case 8: ch.push_back('8'); break;
            case 9: ch.push_back('9'); break;
            case 10:ch.push_back('A'); break;
            case 11:ch.push_back('B'); break;
            case 12:ch.push_back('C'); break;
            case 13:ch.push_back('D'); break;
            case 14:ch.push_back('E'); break;
            case 15:ch.push_back('F'); break;
        }
        d /= 16;
    }
    sort(ch.begin(), ch.end());
    for (p = 0; p < ch.size(); p++)
        cout << ch[p];
}

int main()
{
    string hexa_dcm;
    cout << "Enter a Hexadecimal number : ";
    while(cin >> hexa_dcm) {
        int i = 0;
#if 1
        bool check_hexa_dcm = true;
        i = 0;
        if (hexa_dcm.at(0) == '-')
            i = 1;
        for (; i < hexa_dcm.size(); i++) {
            if ((hexa_dcm.at(i) >= '0' && hexa_dcm.at(i) <= '9') || (hexa_dcm.at(i) >= 'A' && hexa_dcm.at(i) <= 'F') ||
                (hexa_dcm.at(i) >= 'a' && hexa_dcm.at(i) <= 'f')) {
                if (hexa_dcm.at(i) >= 'a' && hexa_dcm.at(i) <= 'f')
                    hexa_dcm.at(i) = toupper(hexa_dcm.at(i));
                check_hexa_dcm = true;
            } else {
                check_hexa_dcm = false;
                break;
            }
        }
        if (!check_hexa_dcm) {
            cout << "This is not a Hexadecimal number.\nSo Enter a Hexadecimal number : ";
            continue;
        }
#endif
        vct Binary, binary;
        Binary.clear();
        if (hexa_dcm.at(0) == '-')
            i = 1;
        else
            i = 0;
        for (; hexa_dcm[i]; i++) {
            switch (hexa_dcm[i]) {
                case '0' : { Binary.push_back(0);  Binary.push_back(0);   Binary.push_back(0);  Binary.push_back(0);   break; }
                case '1' : { Binary.push_back(0);  Binary.push_back(0);   Binary.push_back(0);  Binary.push_back(1);   break; }
                case '2' : { Binary.push_back(0);  Binary.push_back(0);   Binary.push_back(1);  Binary.push_back(0);   break; }
                case '3' : { Binary.push_back(0);  Binary.push_back(0);   Binary.push_back(1);  Binary.push_back(1);   break; }
                case '4' : { Binary.push_back(0);  Binary.push_back(1);   Binary.push_back(0);  Binary.push_back(0);   break; }
                case '5' : { Binary.push_back(0);  Binary.push_back(1);   Binary.push_back(0);  Binary.push_back(1);   break; }
                case '6' : { Binary.push_back(0);  Binary.push_back(1);   Binary.push_back(1);  Binary.push_back(0);   break; }
                case '7' : { Binary.push_back(0);  Binary.push_back(1);   Binary.push_back(1);  Binary.push_back(1);   break; }
                case '8' : { Binary.push_back(1);  Binary.push_back(0);   Binary.push_back(0);  Binary.push_back(0);   break; }
                case '9' : { Binary.push_back(1);  Binary.push_back(0);   Binary.push_back(0);  Binary.push_back(1);   break; }
                case 'A' : { Binary.push_back(1);  Binary.push_back(0);   Binary.push_back(1);  Binary.push_back(0);   break; }
                case 'B' : { Binary.push_back(1);  Binary.push_back(0);   Binary.push_back(1);  Binary.push_back(1);   break; }
                case 'C' : { Binary.push_back(1);  Binary.push_back(1);   Binary.push_back(0);  Binary.push_back(0);   break; }
                case 'D' : { Binary.push_back(1);  Binary.push_back(1);   Binary.push_back(0);  Binary.push_back(1);   break; }
                case 'E' : { Binary.push_back(1);  Binary.push_back(1);   Binary.push_back(1);  Binary.push_back(0);   break; }
                case 'F' : { Binary.push_back(1);  Binary.push_back(1);   Binary.push_back(1);  Binary.push_back(1);   break; }
            }
        }
#if 1
        if (hexa_dcm.at(0) == '-') {
            i = 0;
            for (; i < Binary.size(); i++) {
                if (Binary[i] == 0)
                    binary.push_back(1);
                else if (Binary[i] == 1)
                    binary.push_back(0);
            }
            i = binary.size() - 1;
            if (binary[i] == 0)
                binary.at(i) = 1;
            else {
                for (; i >= 0; i--) {
                    if (binary[i] == 0) {
                        binary[i] = 1;
                        break;
                    } else
                        binary[i] = 0;
                }
            }
        }
        cout << endl;
#endif
        cout << "What number convertation do you want ?" << endl;
        cout << "______________________________________" << endl;
        cout << "1. Decimal To Binary ?" << endl;
        cout << "2. Decimal To Octal ?" << endl;
        cout << "3. Decimal To Decimal ?" << endl;
        cout << "4. Decimal To Hexadecimal ?" << endl;
        cout << "5. Exit ?" << endl;
        int change_form;
        while (cin >> change_form) {
            bool ans = false;
            switch (change_form) {
                case 1: {
                    cout << "Binary number = ";
                    if (hexa_dcm.at(0) == '-') {
                        for (i = 0; i < binary.size(); i++)
                            cout << binary[i];
                    } else {
                        for (i = 0; i < Binary.size(); i++)
                            cout << Binary[i];
                    }
                    cout << endl;
                    break;
                }
                case 2: {
                    if (hexa_dcm.at(0) == '-')
                        HexadecimalToOctal(binary, binary.size());
                    else
                        HexadecimalToOctal(Binary, Binary.size());
                    break;
                }
                case 3: {
                    cout << "Decimal number = ";
                    if (hexa_dcm.at(0) == '-')
                        cout << "-" << HexadecimalToDecimal(Binary, Binary.size()) << endl;
                    else
                        cout << HexadecimalToDecimal(Binary, Binary.size()) << endl;
                    break;
                }
                case 4: {
                    cout << "Hexadecimal number = ";
                    if (hexa_dcm.at(0) == '-') {
                        hexadecimal(binary, binary.size());
                    }
                    else {
                        i = 0;
                        for (; i < hexa_dcm.size(); i++)
                            cout << hexa_dcm[i];
                    }
                    cout << endl;
                    break;
                }
                case 5:
                    ans = true;
                    break;
            }
            if (ans)
                break;
            else {
                cout << endl;
                cout << "What number convertation do you want ?" << endl;
                cout << "______________________________________" << endl;
                cout << "1. Decimal To Binary ?" << endl;
                cout << "2. Decimal To Octal ?" << endl;
                cout << "3. Decimal To Decimal ?" << endl;
                cout << "4. Decimal To Hexadecimal ?" << endl;
                cout << "5. Exit ?" << endl;
            }
        }
        cout << endl;
        cout << "Enter a Hexadecimal number : ";
    }
    return 0;
}
