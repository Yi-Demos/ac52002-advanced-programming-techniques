#include "readarray.h"

// function read_int_as_array
//
// parameter input: array to hold the digits of the integer
// parameter size: the size of the array
// parameter success: indicates that integer was read successfully,
// or otherwise.
//
// This function reads an integer of up to "size" digits
// and stores the digits in the array "input".
//

void read_int_as_array(int input[], int size, bool& success) {
	string temp;
	int i;
	success = true;
	if (size < 1) return;

	// input number
	cin >> temp;

	// loop through input characters
	for (int i = temp.length() - 1, j = 0; i >= 0; i--) {
		// if we have not reached end of line or got too many digits
		// place digit into array, converted to int
		if (isdigit(temp[i])) {
			input[j++] = int(temp[i]) - int('0');
		}
		// if the input was not a digit, make success false
		else {
			success = false;
		}
	}

	// if there were too many digits, set success to false
	if (temp.length() > size) {
		success = false;
	}

	if (!success) {
		cout << "Invalid input" << endl;
	}

	return;
}
