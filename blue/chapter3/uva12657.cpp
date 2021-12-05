#include <list>
#include <iterator>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cstdio>
using namespace std;

class Line {
public:
    Line(int n) {
        reversed = false;
        nums.assign(n, 0);
        auto iter = nums.begin();
        for (int i = 1; i <= n; i++) {
            *iter = i;
            table[i] = iter++;
        }
    }

    void move_left(int op1, int op2) {
        nums.erase(table[op1]);
        table[op1] = nums.insert(table[op2], op1);
    }

    void move_right(int op1, int op2) {
        nums.erase(table[op1]);
        auto target = next(table[op2]);
        table[op1] = nums.insert(target, op1);
    }

    void swap_boxes(int op1, int op2) {
        *(table[op1]) = op2;
        *(table[op2]) = op1;
        swap(table[op1], table[op2]);
    }

    void reverse() {
        reversed = !reversed;
    }

    void perform_op(int type, int op1, int op2) {
        if (reversed && type >= 1 && type <= 2) {
            type = 3 - type;
        }
        switch (type) {
            case 1:
                move_left(op1, op2);
                break;
            case 2:
                move_right(op1, op2);
                break;
            case 3:
                swap_boxes(op1, op2);
                break;
            case 4:
                reverse();
                break;
        }
    }

    int get_sum() const {
        return accumulate(nums.begin(), nums.end(), 0);
    }

    int get_odd_sum() const {
        int sum = 0;
        auto iter = nums.begin();
        for (int i = 1; i <= nums.size(); i++, iter++) {
            if (i % 2) {
                sum += *iter;
            }
        }
        return sum;
    }

    bool is_reversed() const {
        return reversed;
    }
private:
    list<int> nums;
    bool reversed;
    unordered_map<int, list<int>::iterator> table;
};

int main()
{
    int n, num_cmds;
    int case_idx = 1;
    while (scanf("%d%d", &n, &num_cmds) != EOF) {
        Line line(n);
        int type, op1, op2;
        while (num_cmds--) {
            scanf("%d", &type);
            if (type == 1 || type == 2 || type == 3) {
                scanf("%d%d", &op1, &op2);
            }
            line.perform_op(type, op1, op2);
        }
        bool rev = line.is_reversed();
        int sum;
        if (n % 2 || !rev) {
            sum = line.get_odd_sum();
        } else {
            sum = line.get_sum() - line.get_odd_sum();
        }
        printf("Case %d: %d\n", case_idx++, sum);
    }
    return 0;
}
