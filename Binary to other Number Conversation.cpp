#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector <int> vct;
typedef vector <string> strvct;
#define FOR(i, len) for (int i = 0; i < len; i++)
#define FoR(i, start, stop) for (int i = stop - start; i < stop; i++)
#define br() cout << endl

inline int octal(ll N) {
	if (N == 0)
		return N;
	return N % 8 + 10 * octal(N / 8);
}
void BinaryToOctal(int Arr[], int len) {
	ll decimal = 0;
	int p = 0;
	for (int i = 0; i < len; i++)
		decimal = decimal + Arr[i] * pow(2, p),
		p++;
	cout << "Octal Number = " << octal(decimal) << endl;
	br();
}
inline ll BinaryToDecimal(int Arr[], int len) {
	ll decimal = 0;
	int p = 0;
	for (int i = 0; i < len; i++)
		decimal = decimal + Arr[i] * pow(2, p),
		p++;
	return decimal;
}
inline int reverce(ll d) {

	ll sum = 0;
	while (d != 0) {
		int rev = d % 10;
		sum *= 10;
		sum = sum + rev;
		d /= 10;
	}
	return sum;
}
void BinaryToHexadecimal(int Arr[], int len) {
	ll decimal = 0;
	int p = 0;
	for (int i = 0; i < len; i++)
		decimal = decimal + Arr[i] * pow(2, p),
		p++;
	p = 0;
	strvct hexadcm;
	while (decimal != 0) {
		int rem = decimal % 16;
		switch (rem)
		{
			case 0:		hexadcm.push_back("0");		break;
			case 1:		hexadcm.push_back("1");		break;
			case 2:		hexadcm.push_back("2");		break;
			case 3:		hexadcm.push_back("3");		break;
			case 4:		hexadcm.push_back("4");		break;
			case 5:		hexadcm.push_back("5");		break;
			case 6:		hexadcm.push_back("6");		break;
			case 7:		hexadcm.push_back("7");		break;
			case 8:		hexadcm.push_back("8");		break;
			case 9:		hexadcm.push_back("9");		break;
			case 10:	hexadcm.push_back("A");		break;
			case 11:	hexadcm.push_back("B");		break;
			case 12:	hexadcm.push_back("C");		break;
			case 13:	hexadcm.push_back("D");		break;
			case 14:	hexadcm.push_back("E");		break;
			case 15:	hexadcm.push_back("F");		break;
		}
		decimal /= 16;
	}
	reverse(hexadcm.begin(), hexadcm.end());
	cout << "Hexadecimal Number = ";
	for (int i = 0; i < hexadcm.size(); i++)
		cout << hexadcm[i];
	br();
}

int main() {
	ll num;
	cout << "Enter a binary number : ";
	while (cin >> num) {
		vct Arr;
		int Ar[20], len = 0;
		bool bit8 = false;
		bool bit16 = false;
		ll b = num;
		#if 1
			ll m = abs(num);
			bool binary_number_check = false;
			while (m != 0) {
				int r = m % 10;
				if (r > 1) {
					binary_number_check = true;
					break;
				}
				m /= 10;
			}
			if (binary_number_check) {
				cout << "This number is not a binary number.\nSo please again ";
				cout << "enter a binary number : ";
				continue;
			}
		#endif
		if (b >= 0) {
			while (b != 0) {
				int rem = b % 10;
				if (rem == 0)
					Arr.push_back(0);
				else
					Arr.push_back(1);
				b /= 10;
			}
			cout << "How many byte do you want to represent ?" << endl;
			cout << "________________________________________" << endl;
			cout << "1. 8 bit Binary value ?"; br();
			cout << "2. 16 bit Binary value ?"; br();
			int bit_value;
			cin >> bit_value;
			switch (bit_value) {
				case 1: {
					bit8 = true;
					len = 8;
					for (int i = Arr.size(); i < 8; i++)
						Arr.push_back(0);
					for (int i = Arr.size() - 1; i >= 0; i--) {
						Ar[i] = Arr[i];
					}
					br();
					break;
				}
				case 2: {
					bit16 = true;
					len = 16;
					for (int i = Arr.size() - 1; i < 16; i++)
						Arr.push_back(0);
					for (int i = Arr.size() - 1; i >= 0; i--) {
						Ar[i] = Arr[i];
					}
					br();
					break;
				}
			}
		}
		else if (b < 0) {
			b = abs(b);
			while (b != 0) {
				int rem = b % 10;
				if (rem == 0)
					Arr.push_back(1);
				else
					Arr.push_back(0);
				b /= 10;
			}
			if (Arr[0] == 0)
				Arr[0] = 1;
			else {
				for (int i = 0; i < Arr.size(); i++) {
					if (Arr[i] == 1)
						Arr[i] = 0;
					else {
						Arr[i] = 1;
						break;
					}
				}
			}
			cout << "How many byte do you want to represent ?" << endl;
			cout << "________________________________________" << endl;;
			cout << "1. 8 bit Binary value ?"; br();
			cout << "2. 16 bit Binary value ?"; br();
			int bit_value;
			cin >> bit_value;
			switch (bit_value) {
				case 1: {
					bit8 = true;
					len = 8;
					for (int i = Arr.size(); i < 8; i++)
						Arr.push_back(1);
					for (int i = Arr.size() - 1; i >= 0; i--) {
						Ar[i] = Arr[i];
					}
					br();
					break;
				}
				case 2: {
					bit16 = true;
					len = 16;
					for (int i = Arr.size(); i < 16; i++)
						Arr.push_back(1);
					for (int i = Arr.size() - 1; i >= 0; i--) {
						Ar[i] = Arr[i];
					}
					br();
					break;
				}
			}
		}
		cout << "What number convertation do you want ?" << endl;
		cout << "______________________________________" << endl;
		cout << "1. Binary To Binary ?" << endl;
		cout << "2. Binary To Octal ?" << endl;
		cout << "3. Binary To Decimal ?" << endl;
		cout << "4. Binary To Hexadecimal ?" << endl;
		cout << "5. Exit ?" << endl;
		int change_form;
		while (cin >> change_form) {
			bool ans = false;
			switch (change_form) {
				case 1: {
					cout << "Binary Number = ";
					for (int i = len - 1; i >= 0; i--)
						cout << Ar[i];
					br();
					br();
					break;
				}
				case 2: {
					BinaryToOctal(Ar, len);
					break;
				}
				case 3: {
					vct bn;
					int BN[25], l = 0;
					memset(BN, 0, sizeof(BN));
					#if 1
						ll binary = abs(num);
						while (binary != 0) {
							int rem = binary % 10;
							if (rem == 0)
								bn.push_back(0);
							else
								bn.push_back(1);
							binary /= 10;
						}
						if (bit8) {
							l = 8;
							for (int i = bn.size(); i < 8; i++)
								bn.push_back(0);
							for (int i = bn.size() - 1; i >= 0; i--) {
								BN[i] = bn[i];
							}
						}
						if (bit16) {
							l = 16;
							for (int i = bn.size(); i < 16; i++)
								bn.push_back(0);
							for (int i = bn.size() - 1; i >= 0; i--) {
								BN[i] = bn[i];
							}
						}
					#endif
					if (num >= 0)
						cout << "Decimal Number = " << BinaryToDecimal(BN, l) << endl;
					else
						cout << "Decimal Number = -" << BinaryToDecimal(BN, l) << endl;
					br();
					break;
				}
				case 4: {
					BinaryToHexadecimal(Ar, len);
					br();
					break;
				}
				case 5:
					ans = true;
					break;
			}
			if (ans)
				break;
			cout << "What number convertation do you want ?" << endl;
			cout << "______________________________________" << endl;
			cout << "1. Binary To Binary ?" << endl;
			cout << "2. Binary To Octal ?" << endl;
			cout << "3. Binary To Decimal ?" << endl;
			cout << "4. Binary To Hexadecimal ?" << endl;
			cout << "5. Exit ?" << endl;
		}
		cout << endl << "Enter a binary number : ";
	}
	return 0;
}
