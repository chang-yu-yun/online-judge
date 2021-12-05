#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    string input;
    while (getline(cin, input)) {
        list<char> line;
        auto iter = line.begin();
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '[') {
                iter = line.begin();
            } else if (input[i] == ']') {
                iter = line.end();
            } else {
                iter = line.insert(iter, input[i]);
                iter++;
            }
        }
        for (char c : line) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}
