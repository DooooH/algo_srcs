#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

static bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}

static bool compare_int(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // map<pair<string, int>, vector<pair<int, int>>> m; // <genre, <idx, play>>
    map<pair<string, int>, vector<int>> m; // <genre, <idx, play>>
    map<string, int> genre_count;
    vector<pair<string, int>> temp;
    vector<pair<int, int>> songs;

    // count genre
    for (int i = 0; i < genres.size(); i++)
    {
        if (genre_count.find(genres[i]) == genre_count.end())
            genre_count.insert(make_pair(genres[i], plays[i]));
        else
            genre_count[genres[i]] += plays[i];
    }

    for (int i = 0; i < genres.size(); i++)
    {
        if (m.find(make_pair(genres[i], genre_count[genres[i]])) == m.end())
        {
            // vector<pair<int, int>> val;
            vector<int> val;
            // val.push_back(make_pair(i, plays[i]));
            val.push_back(i);
            m.insert(make_pair(make_pair(genres[i], genre_count[genres[i]]) , val));
        }
        else
        {
            // m[make_pair(genres[i], genre_count[genres[i]])].push_back(make_pair(i, plays[i]));
            m[make_pair(genres[i], genre_count[genres[i]])].push_back(i);
        }
    }
    sort(m.begin(), m.end(), cmp);
    for (auto t : m)
        sort(t.second.begin(), t.second.end(), compare_int);
    for (auto e : m)
    {
        int i = 0;
        while (i < 2 || i != m.size())
        {
            // answer.push_back(e.second[i].first);
            answer.push_back(e.second[i]);
            i++;
        }
    }
    return answer;
}

int main()
{
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    vector<int> answer = solution(genres, plays);
    for (auto t : answer)
    {
        cout << t << " ";
    }
    return 0;
}