/*
For each list of words, print a line with each word reversed 
without changing the order of the words. 
Each word consists of English letters only.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{

    //use stack for each word, for end of every word use pop to reverse
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	// to ignore the first \n after t
	cin.ignore();
	while (t--) {
		string str;
		getline(cin, str);
		str += '\n';
		stack<char> s;
		for (char ch : str) {
			if (ch == ' ' || ch == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}

				cout << ch;
			}
			else {
				s.push(ch);
			}
		}

	}
	
	return 0;
}