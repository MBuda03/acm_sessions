#include <stdio.h>

int binary_search(int *array, int n, int x)
{
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (array[mid] < x)
            lo = mid + 1;
        else hi = mid;
    }

    if (lo == hi && array[lo] == x)
        return lo;
    return -1;
}

int main()
{
    int a[] = {1, 2, 10, 24, 56, 78};
    int n = 6;
    printf("%d\n", binary_search(a, n, 10));
    printf("%d\n", binary_search(a, n, 1));
    printf("%d\n", binary_search(a, n, 78));
    printf("%d\n", binary_search(a, n, -19));

    return 0;
}
