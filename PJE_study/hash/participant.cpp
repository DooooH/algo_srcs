#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

static bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    vector<pair<string, int>> temp;
    for (auto part : participant)
    {
        if (m.find(part) == m.end())
            m.insert(make_pair(part, 1));
        else
            m[part] += 1;
    }
    for (auto comp : completion)
    {
        m[comp] -= 1;
    }
    for (auto element : m)
    {
        temp.push_back(element);
    }
    sort(temp.begin(), temp.end(), cmp);
    answer = temp[0].first;
    return answer;
}

    // for (auto t : temp)
    // {
    //     cout << t.first << " " << t.second << "\n";
    // }
int main()
{
    vector<string> participant = {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion = {"stanko", "ana", "mislav"};
    cout << solution(participant, completion) << "\n";
    return 0;
}