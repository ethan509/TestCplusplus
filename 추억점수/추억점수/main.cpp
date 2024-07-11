#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> scoreMap;

    for (int i = 0; i < name.size(); i++) {
        scoreMap.insert(pair<string, int>(name[i], yearning[i]));
    }

    //for (auto it = scoreMap.begin(); it != scoreMap.end(); ++it) {
    //    cout << "<" << it->first << ", " << it->second << ">" << endl;
    //}

    for (vector<string> list : photo) {
        int sum = 0;
        for (string name : list) {
            auto it = scoreMap.find(name);
            if (it != scoreMap.end()) {
                sum += it->second;
            }
        }
        answer.push_back(sum);
    }

    //for (int point : answer) {
    //    cout << "point=" << point << endl;
    //}

    return answer;
}

int main() {
    /*
    name	yearning	photo	result
    ["may", "kein", "kain", "radi"]	[5, 10, 1, 3]
        [["may", "kein", "kain", "radi"],["may", "kein", "brin", "deny"], ["kon", "kain", "may", "coni"]]	[19, 15, 6]
    ["kali", "mari", "don"]	[11, 1, 55]	
        [["kali", "mari", "don"], ["pony", "tom", "teddy"], ["con", "mona", "don"]]	[67, 0, 55]
    ["may", "kein", "kain", "radi"]	[5, 10, 1, 3]
        [["may"],["kein", "deny", "may"], ["kon", "coni"]]	[5, 15, 0]
    */
    vector<string> name = { "may", "kein", "kain", "radi" };
    vector<int> yearning = { 5, 10, 1, 3 };
    vector<vector<string>> photo = {
        {"may", "kein", "kain", "radi"},
        {"may", "kein", "brin", "deny"},
        {"kon", "kain", "may", "coni"}
    };

    vector<int> answer = solution(name, yearning, photo);

    return 0;
}