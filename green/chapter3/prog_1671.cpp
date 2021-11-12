// HDU: 1671
// POJ: 3630
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#define BUFSIZE (20)
#define NDIGITS (10)

char buffer[BUFSIZE];

struct TrieNode {
    int prefix_cnt;
    int str_cnt;
    TrieNode *next[NDIGITS];
    TrieNode() {
        prefix_cnt = 0, str_cnt = 0;
        memset(next, 0, sizeof(TrieNode*) * NDIGITS);
    }
};

struct Trie {
    Trie(): root(new TrieNode) {}
    ~Trie() { release(root); }
    bool insert(const string& str) {
        TrieNode *curr = root;
        for (int i = 0; i < str.size(); i++) {
            if ((curr->next)[str[i]-'0'] == 0) {
                (curr->next)[str[i]-'0'] = new TrieNode;
            }
            curr = (curr->next)[str[i]-'0'];
            if (curr->str_cnt > 0) {
                return false;
            }
            curr->prefix_cnt++;
        }
        if (curr->prefix_cnt > 1) {
            return false;
        }
        curr->str_cnt++;
        return true;
    }
    void release(TrieNode *target) {
        for (int i = 0; i < NDIGITS; i++) {
            if ((target->next)[i]) {
                release((target->next)[i]);
            }
        }
        delete target;
    }
    TrieNode *root;
};

int main() {
    int num_tests, n;
    scanf("%s", buffer);
    num_tests = atoi(buffer);
    while (num_tests--) {
        scanf("%s", buffer);
        n = atoi(buffer);
        vector<string> phone;
        Trie trie;
        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            phone.push_back(buffer);
        }
        bool flag = true;
        for (int i = 0; i < n && flag; i++) {
            flag = trie.insert(phone[i]);
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
