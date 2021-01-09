#include <iostream>
#include <string>
#include <stack>
using namespace std;
void print(stack<char> &s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}
int main()
{
	//use stack for each word, for end of every word use pop to reverse
	//for tag with <> do not reverse
	string str;
	getline(cin, str);
	// if tag is true do not reverse
	bool tag = false;
	stack<char> s;
	for (char ch : str) {
		if (ch == '<') {
			print(s);
			tag = true;
			cout << ch;
		}
		else if (ch == '>') {
			tag = false;
			cout << ch;
		}
		else if (tag == true) {
			cout << ch;
		}
		else {
			if (ch == ' ') {
				print(s);
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
	}
	print(s);
	cout << '\n';

	return 0;
}