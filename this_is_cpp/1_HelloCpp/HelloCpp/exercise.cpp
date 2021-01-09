#include "stdafx.h"
#include <iostream>


int sortascend(void)
{
	int aList[5] = { 20, 10, 50, 30, 40 };
	int i, j, min_index, temp;

	for (i = 0; i < 4; i++){
		min_index = i;
		for (j = i + 1; j < 5; j++){
			if (aList[min_index] > aList[j]){
				min_index = j;
			}
		}
		if (min_index != i) {
			temp = aList[min_index];
			aList[min_index] = aList[i];
			aList[i] = temp;
		}
	}

	for (auto n : aList){
		std::cout << n << " ";
	}

	std::cout << std::endl;
		

	return 0;
}