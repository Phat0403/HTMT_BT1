#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string intToBinary(int x, int n) {
	if (0 > x || x > (1 << n) - 1) {
		return "overflow";
	}
	else {
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
}

string sign_Magnitude(int x) {
	if (-(1 << 7) + 1 > x || x > (1 << 7) - 1) {
		return "overflow";
	}
	else {
		string ans = "";
		if (x == 0) {
			ans = "00000000 hoac 10000000";
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
	if (-(1 << 7) + 1 > x || x > (1 << 7) - 1) {
		return "overflow";
	}
	else {
		string ans = "";
		if (x == 0) {
			ans = "00000000 hoac 11111111";
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
	if (-(1 << 7) > x || x > (1 << 7) - 1) {
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
	string text = "0123456789ABCDE";
	string ans = "";
	for (int i = s.length()  - 1; i >= 0; i -= 4) {
		int temp = 0;
		for (int j = 0; j < 4; j++) {
			temp += ((s[i-j] - '0') << j);
		}
		ans = string(1,text[temp]) + ans;
	}
	return ans;
}

int main() {
	cout <<"Output a: "<< sign_Magnitude(-128) << endl;
	cout << "Output b: " << one_Complement(-128) << endl;
	cout << "Output c: " << two_Complement(-128) << endl;
	string s = two_Complement(-128);
	cout << "Hexadecimal: " << two_ComplementToHexa(s);
}