#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll count_inv_pairs(vector<int>&);
void merge_sort(ll&, vector<int>&, int, int);

int main()
{
    int size;
    while (scanf("%d", &size) != EOF && size > 0) {
        vector<int> nums(size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &(nums[i]));
        }
        printf("%lld\n", count_inv_pairs(nums));
    }
    return 0;
}

ll count_inv_pairs(vector<int>& nums)
{
    ll result = 0;
    merge_sort(result, nums, 0, nums.size());
    return result;
}

void merge_sort(ll& count, vector<int>& nums, int left, int right)
{
    // at most one element
    if (right-left <= 1) {
        return;
    }

    int mid = left + (right-left)/2;
    int idx1 = left, idx2 = mid;
    int write_idx = 0;
    vector<int> temp(right-left);

    merge_sort(count, nums, left, mid);
    merge_sort(count, nums, mid, right);
    
    while (idx1 < mid && idx2 < right) {
        if (nums[idx1] <= nums[idx2]) {
            temp[write_idx] = nums[idx1];
            idx1++;
        } else {
            temp[write_idx] = nums[idx2];
            idx2++;
            count += mid - idx1;
        }
        write_idx++;
    }
    while (idx1 < mid) {
        temp[write_idx] = nums[idx1];
        idx1++, write_idx++;
    }
    while (idx2 < right) {
        temp[write_idx] = nums[idx2];
        idx2++, write_idx++;
    }
    copy(temp.cbegin(), temp.cend(), nums.begin()+left);
}
