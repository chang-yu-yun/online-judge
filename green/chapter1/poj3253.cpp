// POJ 3253
#include <cstdio>
#include <queue>
using namespace std;

typedef long long int ll;

struct Rule {
    bool operator()(int i, int j) const {
        return i > j;   
    }
};

int main() {
    int num_planks;
    int length;
    long long int total = 0;
    int t1, t2;
    priority_queue<int, vector<int>, Rule> min_heap;
    
    scanf("%d", &num_planks);
    while (num_planks--) {
        scanf("%d", &length);
        min_heap.push(length);
    }
    
    while (min_heap.size() > 1) {
        t1 = min_heap.top(), min_heap.pop();
        t2 = min_heap.top(), min_heap.pop();
        total += t1 + t2;
        min_heap.push(t1 + t2);
    }
    printf("%lld\n", total);
    
    return 0;
}
