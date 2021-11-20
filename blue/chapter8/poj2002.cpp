// POJ 2002
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE (100007)

struct ListNode {
    int x;
    int y;
    ListNode *next;
    ListNode(int i, int j, ListNode *node = NULL) : x(i), y(j), next(node) {}
};

struct HashTable {
public:
    HashTable();
    void insert(int, int);
    bool find(int, int);
private:
    ListNode *table[SIZE];
};

HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }
}

void HashTable::insert(int x, int y)
{
    int hash_code = (x*x + y*y) % SIZE;
    table[hash_code] = new ListNode(x, y, table[hash_code]);
}

bool HashTable::find(int x, int y)
{
    int hash_code = (x*x + y*y) % SIZE;
    for (ListNode *iter = table[hash_code]; iter; iter = iter->next) {
        if (iter->x == x && iter->y == y) {
            return true;
        }
    }
    return false;
}

bool cmp(const ListNode& p1, const ListNode& p2)
{
    return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
}

int main()
{
    int n, x, y, x1, y1, x2, y2, x3, y3, x4, y4, diff_x, diff_y;
    while (scanf("%d", &n) != EOF && n > 0) {
        HashTable table;
        vector<ListNode> points;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            table.insert(x, y);
            points.push_back(ListNode(x, y));            
        }

        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                x1 = points[i].x, y1 = points[i].y;
                x2 = points[j].x, y2 = points[j].y;
                diff_x = x2 - x1;
                diff_y = y2 - y1;

                x3 = x1 - diff_y, y3 = y1 + diff_x;
                x4 = x2 - diff_y, y4 = y2 + diff_x;
                if (table.find(x3, y3) && table.find(x4, y4)) {
                    cnt++;
                }

                x3 = x1 + diff_y, y3 = y1 - diff_x;
                x4 = x2 + diff_y, y4 = y2 - diff_x;
                if (table.find(x3, y3) && table.find(x4, y4)) {
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt / 4);
    }
    return 0;
}
