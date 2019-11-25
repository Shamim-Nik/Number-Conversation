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
typedef double db;
typedef vector <int> vct;
typedef vector <string> strvct;
#define FOR(i, len) for (int i = 0; i < len; i++)
#define FoR(i, start, stop) for (int i = stop - start; i < stop; i++)
#define br() cout << endl

inline int reverce(ll N) {
	ll sum = 0;
	while (N != 0) {
		sum *= 10;
		sum += N % 10;
		N /= 10;
	}
	return sum;
}

inline int octal(ll N) {
	if (N == 0)
		return N;
	return N % 8 + 10 * octal(N / 8);
}
void OctalToOctal(int Arr[], int len) {
	ll d = 0;
	int p = 0;
	for (int i = len - 1; i >= 0; i--)
		d = d + Arr[i] * pow(2, p),
		p++;
	cout << "Octal Number = " << octal(d) << endl;
	br();
}
inline int OctalToDecimal(int Arr[], int len) {
	ll d = 0;
	int p = 0;
	for (int i = len - 1; i >= 0; i--)
		d = d + Arr[i] * pow(2, p),
		p++;
	return d;
}
void OctalToHexadecimal(int Arr[], int len) {
	ll decimal = 0;
	int p = 0;
	for (int i = len - 1; i >= 0; i--)
		decimal = decimal + Arr[i] * pow(2, p),
		p++;
	p = 0;
	strvct hexadcm;
	while (decimal != 0) {
		int rem = decimal % 16;
		switch (rem)
		{
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
	cout << "Enter a octal number : ";
	while (cin >> num) {
		ll n = abs(num);
		vct Ar;
		int Arr[25], len = 0;
	#if 1
		ll m = abs(num);
		bool octal_number_check = false;
		while (m != 0) {
			int r = m % 10;
			if (r > 7) {
				octal_number_check = true;
				break;
			}
			m /= 10;
		}
		if (octal_number_check) {
			cout << "This number is not a Octal number.\nSo please again ";
			cout << "enter a octal number : ";
			continue;
		}
	#endif
		ll N = reverce(n);
		while (N != 0) {
			int rem = N % 10;
			switch (rem) {
				case 0: {
					Ar.push_back(0);
					Ar.push_back(0);
					Ar.push_back(0);
					break;
				}
				case 1: {
					Ar.push_back(0);
					Ar.push_back(0);
					Ar.push_back(1);
					break;
				}
				case 2: {
					Ar.push_back(0);
					Ar.push_back(1);
					Ar.push_back(0);
					break;
				}
				case 3: {
					Ar.push_back(0);
					Ar.push_back(1);
					Ar.push_back(1);
					break;
				}
				case 4: {
					Ar.push_back(1);
					Ar.push_back(0);
					Ar.push_back(0);
					break;
				}
				case 5: {
					Ar.push_back(1);
					Ar.push_back(0);
					Ar.push_back(1);
					break;
				}
				case 6: {
					Ar.push_back(1);
					Ar.push_back(1);
					Ar.push_back(0);
					break;
				}
				case 7: {
					Ar.push_back(1);
					Ar.push_back(1);
					Ar.push_back(1);
					break;
				}
			}
			N /= 10;
		}
		int dcm[25];
		memset(dcm, 0, sizeof(dcm));
		for (int i = 0; i < Ar.size(); i++)
			dcm[i] = Ar[i];
		int l = Ar.size();
		memset(Arr, 0, sizeof(Arr));
		bool bit8 = false;
		bool bit16 = false;		
		if (num >= 0) {
			cout << "How many bit do you want to represent ?" << endl;
			cout << "________________________________________" << endl;
			cout << "1. 8 bit Binary value ?"; br();
			cout << "2. 16 bit Binary value ?"; br();
			int bit_value;
			cin >> bit_value;
			switch (bit_value) {
				case 1: {
					bit8 = true;
					len = 8;
					FOR(i, 8) {
						Arr[i] = 0;
					}
					int j = 0;
					FoR(i, Ar.size(), 8) {
						Arr[i] = Ar[j];
						j++;
					}
					break;
				}
				case 2: {
					bit16 = true;
					len = 16;
					FOR(i, 16) {
						Arr[i] = 0;
					}
					int j = 0;
					FoR(i, Ar.size(), 16) {
						Arr[i] = Ar[j];
						j++;
					}
					break;
				}
			}
		}
		else if (num < 0) {
			cout << "How many bit do you want to represent ?" << endl;
			cout << "________________________________________" << endl;
			cout << "1. 8 bit Binary value ?"; br();
			cout << "2. 16 bit Binary value ?"; br();
			int bit_value;
			cin >> bit_value;
			switch (bit_value) {
				case 1: {
					bit8 = true;
					len = 8;
					FOR(i, 8) {
						Arr[i] = 0;
					}
					int j = 0;
					FoR(i, Ar.size(), 8) {
						Arr[i] = Ar[j];
						j++;
					}
					break;
				}
				case 2: {
					bit16 = true;
					len = 16;
					FOR(i, 16) {
						Arr[i] = 0;
					}
					int j = 0;
					FoR(i, Ar.size(), 16) {
						Arr[i] = Ar[j];
						j++;
					}
					break;
				}
			}
			Ar.clear();
			for (int i = 0; i < len; i++) {
				if (Arr[i] == 0)
					Ar.push_back(1);
				else
					Ar.push_back(0);
			}
			if (Ar[Ar.size() - 1] == 0)
				Ar[Ar.size() - 1] = 1;
			else {
				for (int i = Ar.size() - 1; i >= 0; i--) {
					if (Ar[i] == 1)
						Ar[i] = 0;
					else if (Ar[i] == 0) {
						Ar[i] = 1;
						break;
					}
				}
			}
			for (int i = 0; i < Ar.size(); i++)
				Arr[i] = Ar[i];
		}
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
					cout << "Binary Number = ";
					for (int i = 0; i < len; i++)
						cout << Arr[i];
					br();
					break;
				}
				case 2: {
					OctalToOctal(Arr, len);
					br();
					break;
				}
				case 3: {
					int bn[25];
					cout << "Decimal Number = ";
					#if 1						
						if(bit8) {
							int j = 0;
							memset(bn, 0, sizeof(bn));
							for (int i = 8 - l; i < 8; i++)
								bn[i] = dcm[j],
								j++;
						}
						if(bit16) {
							int j = 0;
							memset(bn, 0, sizeof(bn));
							for (int i = 16 - l; i < 16; i++)
								bn[i] = dcm[j],
								j++;
						}						
					#endif
					if(num >= 0)
						cout << OctalToDecimal(bn, len);
					else
						cout << "-" << OctalToDecimal(bn, len);
					br();
					break;
				}
				case 4: {
					OctalToHexadecimal(Arr, len);
					br();
					break;
				}
				case 5: {
					ans = true;
					break;
				}
			}
			if (ans)
				break;
			cout << "What number convertation do you want ?" << endl;
			cout << "______________________________________" << endl;
			cout << "1. Decimal To Binary ?" << endl;
			cout << "2. Decimal To Octal ?" << endl;
			cout << "3. Decimal To Decimal ?" << endl;
			cout << "4. Decimal To Hexadecimal ?" << endl;
			cout << "5. Exit ?" << endl;
		}

		cout << "Enter a octal number : ";
	}
	return 0;
}
