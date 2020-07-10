#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    map<string, int> m;
    for (auto part : clothes)
    {
        if (m.find(part[1]) == m.end())
            m.insert(make_pair(part[1], 1));
        else
            m[part[1]] += 1;
    }
    answer = 1;
    for (auto num : m)
    {
        answer *= num.second + 1;
    }
    answer -= 1;
    return answer;
}