#include <cstdio>
#include <map>
using namespace std;

int cube(int x)
{
    return x * x * x;
}

int main()
{
    int a1, a2, a3, a4, a5;
    long long int cnt = 0;
    map<int, int> seen;

    scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
    for (int i = -50; i <= 50; i++) {
        for (int j = -50; j <= 50; j++) {
            if (i != 0 && j != 0) {
                seen[-(a4 * cube(i) + a5 * cube(j))]++;
            }
        }
    }

    for (int i = -50; i <= 50; i++) {
        for (int j = -50; j <= 50; j++) {
            for (int k = -50; k <= 50; k++) {
                if (i != 0 && j != 0 && k != 0) {
                    int curr = a1 * cube(i) + a2 * cube(j) + a3 * cube(k);
                    map<int, int>::iterator iter = seen.find(curr);
                    if (iter != seen.end()) {
                        cnt += iter->second;
                    }
                }
            }
        }
    }

    printf("%lld\n", cnt);
    return 0;
}