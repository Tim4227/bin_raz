﻿#include <iostream>
#include <string>
using namespace std;

string pluss(string a, string b) {
	string apb = "";
	int s;
	if (a.size() < b.size()) {
		string swap = a;
		a = b;
		b = swap;
	}
	s = a.size();
	int o = 0;
	for (int i = b.size(); i < s; i++)
		b = '0' + b;
	for (int i = s - 1; i >= 0; i--) {
		if ((int(a[i]) - 48 + int(b[i]) - 48 + o) == 0) {
			apb = '0' + apb;
			o = 0;
		}
		else if ((int(a[i]) - 48 + int(b[i]) - 48 + o) == 1) {
			apb = '1' + apb;
			o = 0;
		}
		else if ((int(a[i]) - 48 + int(b[i]) - 48 + o) == 2) {
			apb = '0' + apb;
			o = 1;
		}
		else {
			apb = '1' + apb;
			o = 1;
		}
	}
	if (o > 0)
		apb = '1' + apb;
	return apb;
}

string neg(string a) {
	string s1 = a;
	int s = a.size();
	int o = 0;
	for (int i = 0; i < s; i++) {
		a[i] = a[i] == '0' ? '1' : '0';
		s1[i] = '0';
	}
	s1[s - 1] = '1';
	return pluss(a, s1);
}

string min(string a, string b) {
	string m, min;
	int s;
	b = neg(b);
	m = pluss(a, b);
	s = m.size();
	min = "";
	for (int i = 1; i < s; i++)
		min += m[i];
	bool big = 0;
	s--;
	m = "";
	for (int i = 0; i < s; i++) {
		if (min[i] == '1')
			big = 1;
		if (big)
			m += min[i];
	}
	if (m == "")
		m = "0";
	return m;
}

int main()
{
	string a, b;
	cin >> a >> b;
	cout << pluss(a, b) << endl << min(a, b);
}