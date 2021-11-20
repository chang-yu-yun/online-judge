#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

constexpr size_t BUFSIZE = 25;
char buffer[BUFSIZE];

string get_str(const char *begin, const char *end)
{
    string str;
    for (const char *iter = begin; iter != end; iter++) {
        str.push_back(*iter);
    }
    return str;
}

int main()
{
    unordered_map<string, string> dict;
    size_t length;
    while (fgets(buffer, BUFSIZE, stdin)) {
        char *last = strchr(buffer, '\n');
        const char *target = strchr(buffer, ' ');
        *last = '\0';
        length = strlen(buffer);
        if (target) {
            string d = get_str(buffer, target);
            string s = get_str(target+1, buffer+length);
            dict[s] = d;
        } else if (length > 0) {
            auto target = dict.find(buffer);
            printf("%s\n", target != dict.cend() ? (target->second).c_str() : "eh");
        }
    }
    return 0;
}
