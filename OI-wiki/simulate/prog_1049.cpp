#include <cstdio>

int main()
{
    int n, u, d;
    while (scanf("%d%d%d", &n, &u, &d) != EOF && n > 0) {
        int height = 0, minute = 0;
        while (height < n) {
            if (minute > 0) {
                height -= d, minute++;
            }
            height += u, minute++;
        }
        printf("%d\n", minute);
    }
    return 0;
}
