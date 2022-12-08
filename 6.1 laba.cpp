#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::string;

string check(string str) {
	std::stack <char> symb;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '{' or str[i] == '(' or str[i] == '[') {
			symb.push(str[i]);
		}
		if (str[i] == '}') {
			if (symb.empty() == 1) return 0;
			if ('{' == symb.top()) symb.pop();
			else return 0;
		}
		if (str[i] == ')') {
			if ('(' == symb.top()) symb.pop();
			else return 0;
		}
		if (str[i] == ']') {
			if ('[' == symb.top()) symb.pop();
			else return 0;
		}
	}
	if (symb.empty() == 1) return "yes";
	else return "no";
}

int main()
{
	string a;
	cin >> a;
	cout << check(a);
}