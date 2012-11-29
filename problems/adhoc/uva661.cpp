#include <cstdio>
#include <cstring>

#include <algorithm>

#define MAXN 25 

using namespace std;

int consumption[MAXN];
bool onoff[MAXN];

int main()
{
    int n, m, c, t = 0;
    while (scanf("%d %d %d", &n, &m, &c)) {
        if (t != 0)
            printf("\n");
        if (n == 0 && m == 0 && c == 0)
            break;

        for (int i = 0; i < n; ++i)
            scanf("%d", &consumption[i]);
        memset(onoff, 0, sizeof(onoff));

        int max_cons = 0;
        int cons = 0;
        bool bad = false;
        for (int i = 0; i < m; ++i) {
            int id;
            scanf("%d", &id);
            id -= 1;
            onoff[id] = !onoff[id];
            if (onoff[id])
                cons += consumption[id];
            else cons -= consumption[id];
            max_cons = max(cons, max_cons);

            if (max_cons > c) 
                bad = true;
        }

        printf("Sequence %d\n", ++t);
        if (bad) {
            printf("Fuse was blown.\n");
        } else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", max_cons);
        }
    }

    return 0;
}
