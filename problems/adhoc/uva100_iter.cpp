#include <cstdio>

#include <algorithm>

using namespace std;

int chain_length(long n)
{
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else n = 3 * n + 1;
        ++length;
    }

    return length;
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
