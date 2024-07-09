#include <iostream>
#include <algorithm>

using namespace std;

enum max {
	MAX_CHANCE = 1,
};

bool isDigit(int& digit, string str) {
	const char& ch = str[0];

	int startIndex = 0;

	// check the negative
	if (ch == '-')
		startIndex = 1;

	for (int i = startIndex; i < str.size(); i++) {
		const char& ch = str[i];
		if (!isdigit(ch))
			return false;
	}

	digit = atoi(str.c_str());

	return true;
}

int main() {
	string inputStr = "";
	int digit = 0;

	int chance = 0;
	while (chance < MAX_CHANCE) {
		cout << "Enter the guess Num: ";
		cin >> inputStr;

		if (isDigit(digit, inputStr) == false) {
			cout << "[USAGE] input value has to only digit" << endl;
			continue;
		}

		cout << "[" << chance + 1 << "] digit: " << digit << endl;

		chance++;
	}

	return 0;
}
