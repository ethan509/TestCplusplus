#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

enum _error_code {
	ERROR_NONE = 0, 
	ERROR_NOT_DIGIT,
	ERROR_OVER_MIN,
	ERROR_OVER_MAX,
};

enum _max {
	MAX_CHANCE = 10,
	MIN_RAND_NUMBER = 1,
	MAX_RAND_NUMBER = 100,
};

void errorPrint(const _error_code err) {
	switch (err) {
	case ERROR_NOT_DIGIT :
		cout << "[USAGE] input value has to only digit" << endl;
		break;
	case ERROR_OVER_MIN :
	case ERROR_OVER_MAX :
		cout << "[USAGE] The random number range is 1~100" << endl;
		break;
	}
}

_error_code isDigit(int& digit, string str) {
	const char& ch = str[0];

	int startIndex = 0;

	// check the negative
	if (ch == '-')
		startIndex = 1;

	for (int i = startIndex; i < str.size(); i++) {
		const char& ch = str[i];
		if (!isdigit(ch))
			return ERROR_NOT_DIGIT;
	}

	digit = atoi(str.c_str());

	if (digit < MIN_RAND_NUMBER) {
		return ERROR_OVER_MIN;
	}

	if (digit > MAX_RAND_NUMBER) {
		return ERROR_OVER_MAX;
	}

	return ERROR_NONE;
}

int main() {
	string inputStr = "";
	int digit = 0;

	random_device rd;
	int rand = rd() % MAX_RAND_NUMBER + 1;

	int chance = 0;
	while (chance < MAX_CHANCE) {
		cout << "Enter the guess Num: ";
		cin >> inputStr;

		_error_code err = ERROR_NONE;
		if ( (err = isDigit(digit, inputStr)) != ERROR_NONE) {
			errorPrint(err);
			continue;
		}

		if (digit > rand) {
			cout << "[" << chance + 1 << "] digit: " << digit << "\t Down" << endl;
		}
		else if (digit < rand) {
			cout << "[" << chance + 1 << "] digit: " << digit << "\t Up" << endl;
		}
		else {
			cout << "[" << chance + 1 << "] Corect !!!rand number is " << rand << endl;
			break;
		}

		chance++;
	}

	return 0;
}
