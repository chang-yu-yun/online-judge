#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, vector<string>> seen;
    vector<string> result;
    string line;

    while (getline(cin, line) && line.find('#') == string::npos) {
        stringstream ss{line};
        while (getline(ss, line, ' ')) {
            string str;
            for (int i = 0; i < line.size(); i++) {
                str.push_back(tolower(line[i]));
            }
            sort(str.begin(), str.end());
            seen[str].emplace_back(line);
        }
    }

    for (auto iter = seen.cbegin(); iter != seen.cend(); iter++) {
        if ((iter->second).size() == 1) {
            result.emplace_back((iter->second).front());
        }
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        printf("%s\n", result[i].c_str());
    }

    return 0;
}
