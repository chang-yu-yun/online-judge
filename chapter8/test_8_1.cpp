#include <cstdio>
#include <vector>
using namespace std;

const int size = 6;
const int mod = 100005;
const char *result[] = {"No two snowflakes are alike.", "Twin snowflakes found."};

bool check(const int [][size], int, int);

int main()
{
    int n;
    int nums[100005][size];
    vector<int> table[mod];
    
    scanf("%d", &n);
    for (int idx = 0; idx < n; idx++) {
        for (int i = 0; i < size; i++) {
            scanf("%d", &(nums[idx][i]));
        }
    }
    int flag = 0;
    for (int idx = 0; idx < n && !flag; idx++) {
        int sum = nums[idx][0] + nums[idx][1] + nums[idx][2] + 
                  nums[idx][3] + nums[idx][4] + nums[idx][5];
        int hash_code = sum % mod;
        for (int j = 0; j < table[hash_code].size(); j++) {
            if (check(nums, idx, table[hash_code][j])) {
                flag = 1;
                break;
            }
        }
        table[hash_code].push_back(idx);
    }

    printf("%s\n", result[flag]);
    return 0;
}

bool check(const int nums[][size], int i, int j)
{
    for (int start = 0; start < size; start++) {
        bool flag = true;           
        // clockwise
        for (int k = 0; k < size && flag; k++) {
            if (nums[i][k] != nums[j][(start+k) % size]) {
                flag = false;
            }
        }
        if (flag) {
            return true;
        }

        flag = true;
        // counterclockwise
        for (int k = 0; k < size && flag; k++) {
            if (nums[i][k] != nums[j][(start-k+size) % size]) {
                flag = false;
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}
