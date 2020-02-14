// A small main program to demonstrate the way the read_int_as_array
// function works. The program reads a long integer from the keyboard,
// and then displays the contents of the array.

#include <iostream>
#include <cstring>
#include "readarray.h"
using namespace std;

#define MAXSIZE 50

void subtract(int*, int*, int*);
void printArray(bool, int*);

bool secondArrIsSmaller(int*, int*);

int main() {
	// init array entries to 0
	int arr1[MAXSIZE] = {0}, arr2[MAXSIZE] = {0}, result[MAXSIZE] = {0};
	bool negative = false, success;

	cout << "Enter first integer:" << endl;
	read_int_as_array(arr1, MAXSIZE, success);
	cout << "Enter second integer:" << endl;
	read_int_as_array(arr2, MAXSIZE, success);

	// before proceeding further, make sure arr1 is larger han arr2
	if (!secondArrIsSmaller(arr1, arr2)) {
		negative = true;
		swap(arr1, arr2);
	}

	subtract(arr1, arr2, result);

	printArray(negative, result);

	char junk; cin.get(junk);

	return 0;
}

// returns true if str1 is smaller than str2.
bool secondArrIsSmaller(int* arr1, int* arr2) {
	// start with high digit value and compare the corresponding values
	for (int i = MAXSIZE - 1; i >= 0; i--) {
	 	// when two number value is different return comparison
	    if (arr1[i] != arr2[i] && arr1[i] > arr2[i]) {
			return true;
		}
	}

	return false; // exactly equal
}

void subtract(int* arr1, int* arr2, int* result) {
	int bit = 0; // whether borrow from next index

	for(int i = 0; i < MAXSIZE; i++) {
		arr1[i] -= bit;

		if(arr1[i] < arr2[i]) {
			arr1[i] += 10;
			bit = 1;
		}
		else {
			bit = 0;
		}

		result[i] = arr1[i] - arr2[i];
	}
}

void printArray(bool negative, int* arr) {
    int i = MAXSIZE - 1;

	std::cout << "\n\n\n";
	if (negative) {
		cout << "-";
	}

    while (arr[i] == 0) i--; // remove trailing zeros
    while (i >= 0) cout << arr[i--];

	std::cout << "\n\n";
}
