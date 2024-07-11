#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 최대대칭수 -> 오류 해결 및 로직업그레이드.
int solution(string str) {
	int ret = 0;
	map<char, int> map_;	// <int, int> 대신 <char, int>로 저장. more simple
	set<char, greater<int>> set_;

	for (const char ch : str) {
		char n = ch;
		auto it = map_.find(n);
		if (it == map_.end()) {
			map_.insert(make_pair(n, 1));
			set_.insert(n);
		}
		else {
			it->second++;
		}
	}

	char max = '0'-1; // 숫자 0보다 작은 ascii 값을 default value 로 설정
	string answerStr = "";
	answerStr.resize(str.size(), ' ');
	int answerStrIdx = 0;

	int idx = 0;
	for (char ch : set_) {
		auto it = map_.find(ch);

		int loopCnt = 0;
		if (it->second > 1) {
			if (it->second % 2 == 0) {
				loopCnt = it->second / 2;
			}
			else {
				loopCnt = it->second / 2 - 1;
				if (max < it->first)
					max = it->first;
			}

			for (int i = 0; i < loopCnt; i++) {
				answerStr[i+idx] = it->first;
				answerStr[answerStr.size() - 1 -i - idx] = it->first;
				idx++;
			}
		}
		else {
			if (max < it->first)
				max = it->first;
		}
	}

	// 한번도 max 값이 설정되지 않았을 때 추가되는 것을 방지하기 위해 if문 필요
	if (max != '0' - 1) {
		answerStr[idx] = max;
	}

	//cout << "answerStr: '" << answerStr << "'";
	
	int blankCnt = 0;
	for (char ch : answerStr) {
		if (ch == ' ')
			blankCnt++;
	}
	remove(answerStr.begin(), answerStr.end(), ' ');
	answerStr.resize(answerStr.size() - blankCnt);
	
	ret = atoi(answerStr.c_str());



	return ret;
}

int main() {
	//string str = "4294";
	string str = "4994";
	//string str = "462664";
	//string str = "46265477";
	cout << "answer= " << solution(str) << endl;

	return 0;
}
