#include <cstdio>

#include <algorithm>

using namespace std;

int chain_length(long n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return chain_length(n / 2) + 1;
    else return chain_length(3 * n + 1) + 1;
}

int main()
{
    int i, j;
    while (scanf("%d %d", &i, &j) == 2) {
        int max_len = 0;
        for (int k = i; k <= j; ++k)
            max_len = max(max_len, chain_length(k));
        printf("%d %d %d\n", i, j, max_len);
    }

    return 0;
}
