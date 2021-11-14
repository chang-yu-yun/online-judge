// Codeforce 1550C
// https://codeforces.com/contest/1550/problem/C
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int count(const vector<int>&);

int main() {
    int ntest, n;
    scanf("%d", &ntest);
    while (ntest--) {
        scanf("%d", &n);
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &(nums[i]));
        }
        printf("%d\n", count(nums));
    }
    return 0;
}

int count(const vector<int>& nums) {
    auto check = [&](int a, int b, int c) {
        int diff1 = abs(nums[a]-nums[b]) + b-a;
        int diff2 = abs(nums[b]-nums[c]) + c-b;
        int diff3 = abs(nums[a]-nums[c]) + c-a;
        return diff1 + diff2 == diff3;
    };
    int cnt = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool flag = true;
            for (int p = i; p < j && flag; p++) {
                for (int q = p+1; q < j && flag; q++) {
                    if (check(p, q, j)) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                ++cnt;
            } else {
                break;
            }
        }
    }
    return cnt;
}
