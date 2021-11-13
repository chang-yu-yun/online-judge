// HDU 4006
#include <iostream>
#include <string>
#include <queue>
#include <functional>
using namespace std;

int main() {
    int n, k, input;
    string buffer;
    size_t space;

    while (getline(cin, buffer)) {
        space = buffer.find(' ');
        n = stoi(buffer.substr(0, space));
        k = stoi(buffer.substr(space + 1));
        priority_queue<int, vector<int>, greater<int>> min_heap;
        while (n--) {
            getline(cin, buffer);
            space = buffer.find(' ');
            if (space != string::npos) {
                // insert
                input = stoi(buffer.substr(space + 1));
                if (min_heap.size() < k || input > min_heap.top()) {
                    min_heap.push(input);
                }
                if (min_heap.size() > k) {
                    min_heap.pop();
                }
            } else {
                // query
                cout << min_heap.top() << endl;
            }
        }
    }

    return 0;
}