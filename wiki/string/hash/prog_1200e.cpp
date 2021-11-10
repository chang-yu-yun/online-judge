#include <cstdio>
#include <string>
#include <vector>
using namespace std;
using ll = long long int;

constexpr ll MAXS  = 1000002LL;
constexpr ll BASE  = 131LL;
constexpr ll PRIME = 20211031LL;

char buf[MAXS];
ll power[MAXS], table[MAXS];

void build_hash_power_values(vector<ll>& table, int size);

int main()
{
    int n, total = 0;
    vector<string> words;
    string res;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        words.emplace_back(buf);
        total += words[i].size();
    }
    // build hash table
    build_hash_power_values(total);
    for (int i = 0; i < n; i++) {
        ll val = 0, target;
        for (int idx = 0; idx < words[i].size(); idx++) {
            val = (val * BASE + words[i][idx]) % PRIME;
            target = get_suffix_hash(res.size()-idx, res.size());
        }
    }
    return 0;
}

void build_hash_power_values(int size)
{
    power[0] = 1LL;
    for (int i = 1; i <= size; i++) {
        power[i] = (power[i-1] * BASE) % PRIME; 
    }
}

ll get_suffix_hash(int start, int size)
{
    return ((table[size-1] - table[start]*power[size-start]) % PRIME + PRIME) % PRIME;
}