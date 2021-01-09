// Cpp_practice.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;


int main(void)
{
	// printing out A+B
	/*
	int N, a, b;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}
	*/

	// if N not given,
	int a, b;
	while (cin >> a >> b)
	{
		cout << a + b << '\n';
	}

	return 0;
}

