#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string intToBinary(int x, int n)
{
	string ans = "";
	while (x > 0) {
		int bit = x & 1;
		ans = to_string(bit) + ans;
		n--;
		x = x >> 1;
	}
	while (n > 0) {
		ans = "0" + ans;
		n--;
	}
	return ans;
}

string sign_Magnitude(int x) {
	if (-127 > x || x > 127) {
		return "overflow";
	}
	else {
		string ans = "";
		if (x == 0) {
			ans = "00000000 or 10000000";
		}
		else if (x > 0) {
			ans = "0" + intToBinary(x, 7);
		}
		else {
			ans = "1" + intToBinary(-x, 7);
		}
		return ans;
	}
}

string one_Complement(int x) {
	if (-127 > x || x > 127) {
		return "overflow";
	}
	else {
		string ans = "";
		if (x == 0) {
			ans = "00000000 or 11111111";
		}
		else if (x > 0) {
			ans = "0" + intToBinary(x, 7);
		}
		else {
			int reverse = ((-x) ^ ((1 << 7) - 1));
			ans = "1" + intToBinary(reverse, 7);
		}
		return ans;
	}
}
string two_Complement(int x) {
	if (-128 > x || x > 127) {
		return "overflow";
	}
	else {
		string ans = "";
		if (x == 0) {
			ans = "00000000";
		}
		else if (x > 0) {
			ans = "0" + intToBinary(x, 7);
		}
		else {
			ans = "1" + intToBinary(x + (1 << 7), 7);
		}
		return ans;
	}
}
string two_ComplementToHexa(string s) {
	if (s == "overflow") {
		return "overflow";
	}
	string text = "0123456789ABCDE";
	string ans = "";
	for (int i = s.length() - 1; i >= 0; i -= 4) {
		int temp = 0;
		for (int j = 0; j < 4; j++) {
			temp += ((s[i - j] - '0') << j);
		}
		ans = string(1, text[temp]) + ans;
	}
	return ans;
}

int main() {
	int n;
	cout << "Input n: ";
	cin >> n;
	cout << "Output a: " << sign_Magnitude(n) << endl;
	cout << "Output b: " << one_Complement(n) << endl;
	cout << "Output c: " << two_Complement(n) << endl;
	string s = two_Complement(n);
	cout << "Hexadecimal: " << two_ComplementToHexa(s);
}