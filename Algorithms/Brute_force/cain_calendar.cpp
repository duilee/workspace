// https://www.acmicpc.net/problem/6064
/*
It was recently revealed by the ICPC excavation team that the Inca Empire was established just after 
the Cain Empire which was a splendid civilization that flourished in South America. It is believed that 
the people in the Cain Empire used an interesting odd calendar. 
In their calendar, a year was represented by <x:y>, where x and y are natural numbers which are less than 
or equal to M and N, respectively. The first year, that is, the beginning of the world is represented by <1:1>. 
The second year is represented by <2:2>. Let <x':y'>be the following year of <x:y>. 
If x < M, x' = x + 1, otherwise x' = 1. Similarly, if y < N, y' = y + 1, otherwise y' = 1. 
The last year of their calendar is <M:N>. 
It is said that there was a prophecy which states the world ends in the year <M:N>. 

For example, assume that M = 10 and N = 12. The first year is represented by <1:1>. 
The year <1:11> represents the 11th year, <3:1> represents the 13th year, and 
<10:12> represents the 60th year which is the last year. 

Given four integers M, N, x, and y, write a program that computes the number k such that <x:y> 
represents the kth year, where <x:y> is the last year of the world in the Cain Calendar.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t, m, n, x, y;
	cin >> t;

	for (int i = 0; i < t; i++){
		
		int ans = 0;
		cin >> m >> n >> x >> y;
		int max_nm = max(n, m);
		x -= 1;
		y -= 1;

		for (int j = 0; j <= max_nm; j++) {
			ans = j * m + x;
			if (ans % n == y) {
				cout << ans + 1 << '\n';
				break;
			}
			if (j == max_nm){
				ans = -1;
				cout << ans << '\n';
			}
		}

	}

	
	return 0;
}