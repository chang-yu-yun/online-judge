#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> table = {
    {2, 3},
    {0, 3},
    {1, 4},
    {2, 4},
    {0, 1}
};

int main()
{
    int n, na, nb;
    int sa = 0, sb = 0;
    scanf("%d%d%d", &n, &na, &nb);
    vector<int> pa(na, 0);
    vector<int> pb(nb, 0);
    for (int i = 0; i < na; i++) {
        scanf("%d", &(pa[i]));
    }
    for (int i = 0; i < nb; i++) {
        scanf("%d", &(pb[i]));
    }
    for (int i = 0; i < n; i++) {
        int a = pa[i % na];
        int b = pb[i % nb];
        if (table[a][0] == b || table[a][1] == b) sa++;
        if (table[b][0] == a || table[b][1] == a) sb++;
    }
    printf("%d %d\n", sa, sb);
}
