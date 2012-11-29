#include <cstdio>

#include <algorithm>

using namespace std;

#define MAXN 1000000

int memo[MAXN];

int chain_length(long long n)
{
    if (n == 1)
        return 1;
    if (n < MAXN && memo[n])
        return memo[n];
    if (n % 2 == 0) {
        if (n < MAXN) {
            memo[n] = chain_length(n / 2) + 1;
            return memo[n];
        } else {
            return chain_length(n / 2) + 1;
        }
    } else {
        if (n < MAXN) {
            memo[n] = chain_length(3 * n + 1) + 1;
            return memo[n];
        } else {
            return chain_length(3 * n + 1) + 1;
        }
    }
}

int main()
{
    int i, j;
    while(scanf("%d %d", &i, &j) == 2) {
        int max_len = 0;
        int i1 = i, j1 = j;
        if (i > j) i1 = j, j1 = i;
        for (int k = i1; k <= j1; ++k)
            max_len = max(max_len, chain_length(k));
        printf("%d %d %d\n", i, j, max_len);
    }

    return 0;
}

