#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string input;
    stack<char> stk;
    bool res = true;
    getline(cin, input);
    for (int i = 0; i < input.size() && input[i] != '@'; i++) {
        if (input[i] == '(') {
            stk.push(input[i]);
        } else if (input[i] == ')') {
            if (stk.empty()) {
                res = false;
                break;
            }
            stk.pop();
        }
    }
    if (!stk.empty()) res = false;
    cout << (res ? "YES" : "NO") << endl;
    return 0;
}
