#include <cstdio>
#include <cstring>

#define NROW (5)
#define NCOL (6)
#define NSHF (4)

int matrix[NROW][NCOL];
int result[NROW][NCOL];
int shift[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void press(int x, int y)
{
    matrix[x][y] ^= 1;
    for (int i = 0; i < NSHF; i++) {
        int next_x = x + shift[i][0];
        int next_y = y + shift[i][1];
        if (next_x >= 0 && next_x < NROW &&
            next_y >= 0 && next_y < NCOL) {
            matrix[next_x][next_y] ^= 1;
        }
    }
}

void print(int matrix[][NCOL], const char *name)
{
    printf("[%s]\n", name);
    for (int i = 0; i < NROW; i++) {
        for (int j = 0; j < NCOL; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int input[NROW][NCOL];
    for (int i = 0; i < NROW; i++) {
        for (int j = 0; j < NCOL; j++) {
            scanf("%d", &(input[i][j]));
        }
    }
    for (int state = 0; state < (1<<NCOL); state++) {
        memcpy(matrix, input, sizeof(int)*NROW*NCOL);
        memset(result, 0, sizeof(int)*NROW*NCOL);
        for (int k = 0, mask = 1; k < NCOL; k++, mask <<= 1) {
            if (state & mask) {
                press(0, k);
                result[0][k] = 1;
            }
        }
        for (int i = 0; i < NROW-1; i++) {
            for (int j = 0; j < NCOL; j++) {
                if (matrix[i][j]) {
                    press(i+1, j);
                    result[i+1][j] = 1;
                }
            }
        }
        bool check = true;
        for (int i = 0; i < NCOL && check; i++) {
            if (matrix[NROW-1][i] == 1) {
                check = false;
            }
        }
        if (check) {
            for (int i = 0; i < NROW; i++) {
                for (int j = 0; j < NCOL; j++) {
                    if (j > 0) {
                        printf(" ");
                    }
                    printf("%d", result[i][j]);
                }
                printf("\n");
            }
            break;
        }
    }
    return 0;
}
