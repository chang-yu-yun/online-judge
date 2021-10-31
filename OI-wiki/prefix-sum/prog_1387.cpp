#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN (100)
#define MAXM (100)

int matrix[MAXN][MAXM];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &(matrix[i][j]));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int s1 = i > 0 && j > 0 ? matrix[i-1][j-1] : 0;
            int s2 = i > 0 ? matrix[i-1][j] : 0;
            int s3 = j > 0 ? matrix[i][j-1] : 0;
            int s4 = matrix[i][j] + s2 + s3 - s1;
            matrix[i][j] = s4;
        }
    }
    int size = min(n, m);
    bool found = false;
    while (size > 0 && !found) {
        int target = size * size;
        for (int i = size-1; i < n; i++) {
            for (int j = size-1; j < m; j++) {
                int ui = i - size;
                int uj = j - size;
                int s1 = ui >= 0 && uj >= 0 ? matrix[ui][uj] : 0;
                int s2 = ui >= 0 ? matrix[ui][j] : 0;
                int s3 = uj >= 0 ? matrix[i][uj] : 0;
                int s4 = matrix[i][j] - s2 - s3 + s1;
                if (s4 == target) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) size--;
    }
    printf("%d\n", size);
    return 0;
}