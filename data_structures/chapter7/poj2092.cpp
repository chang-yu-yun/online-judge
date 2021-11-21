#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define CSIZE (10001)
int cnt[CSIZE];

struct CMP {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return (p1.first > p2.first) ||
               (p1.first == p2.first && p1.second < p2.second);
    }
};

int main()
{
    int n, m, rank;
    CMP cmp;
    while (scanf("%d%d", &n, &m) != EOF && n > 0 && m > 0) {
        vector<pair<int, int> > players;
        int target;
        memset(cnt, 0, sizeof(int)*CSIZE);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &rank);
                cnt[rank]++;
            }
        }
        for (int i = 0; i < CSIZE; i++) {
            if (cnt[i] > 0) {
                players.push_back(make_pair(cnt[i], i));
            }
        }
        sort(players.begin(), players.end(), cmp);
        target = players[1].first;
        for (int i = 1; i < players.size(); i++) {
            if (i > 1) printf(" ");
            if (players[i].first < target) break;
            printf("%d", players[i].second);
        }
        printf("\n");
    }
    return 0;
}
