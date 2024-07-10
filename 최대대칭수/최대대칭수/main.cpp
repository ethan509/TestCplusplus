#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

// 주어진 문자열의 숫자를 조합해 최대크기의 대칭수를 만드는 프로그램.
// solution
// 1. map 으로 숫자별 빈도수를 저장하고,
// 2. multiset<greater> 로 정렬해서
// 3. setting
int solution(string str) {
	map<int, int> digitMap;
	multiset<int, greater<int>> digitSet;

	string answer = "";
	answer.resize(str.size(), ' ');	// 초기 설정으로 parameter string 길이만큼 사이즈 설정.
	//cout << "answer size = " << answer.size() << endl;

	// set map<숫자, 빈도수>
	int digit = 0;
	for (const char ch : str) {
		digit = atoi(&ch);

		auto it = digitMap.find(digit);
		if (it == digitMap.end()) {
			digitMap.insert(make_pair(digit, 1));
			digitSet.insert(digit);
		}
		else {
			it->second++;
		}
	}

	//for (auto it = digitMap.begin(); it != digitMap.end(); ++it) {
	//	cout << "[" << it->first << ", " << it->second << "]" << endl;
	//}

	int max = 0;
	int idx = 0;
	for (auto it = digitSet.begin(); it != digitSet.end(); ++it) {

		auto itm = digitMap.find(*it);
		cout << "[" << *it << "]" << endl;;
		if (itm->second > 1) {
			int loopCnt = itm->second;

			if (loopCnt % 2 == 0) {
				loopCnt = loopCnt / 2;
			}
			else {
				loopCnt = (loopCnt - 1) / 2;
				if (max < itm->first) {
					max = itm->first;
					cout << "(max:" << max << ")" << endl;
				}
			}
			cout << "\tloonCnt:" << loopCnt << endl;

			// 여기서부터 세팅
			for (int i = 0; i < loopCnt; i++) {
				const char& ch = itm->first + 48;
				answer[i+idx] = ch;
				answer[answer.size() - 1 - i-idx] = ch;
				cout << "\tanswer= '" << answer << "'" << endl;
				idx++;
			}
		}
		else {
			if (max < itm->first) {
				max = itm->first;
				cout << "\t(max:" << max << ")" << endl;
			}
		}
	}

	//cout << "[before]answer= '" << answer << "'" << endl;
	answer[idx] = max + 48;
	//cout << " [after]answer= '" << answer << "'" << endl;

	// 공백 제거
	int blankCount = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == ' ')
			blankCount++;
	}
	remove(answer.begin(), answer.end(), ' ');
	answer.resize(answer.size() - blankCount);

	//cout << " [after]answer= '" << answer << "'" << endl;
	int ret = atoi(answer.c_str());

	return ret;
}

int main() {
	// condition : 숫자만 입력 가능
	//string str = "4294";
	//string str = "462664";
	string str = "46264";
	cout << "answer= " << solution(str) << endl;

	return 0;
}
