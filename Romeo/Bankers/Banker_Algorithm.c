#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Allocation Matrix
    int alloc[n][m];
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // MAX Matrix
    int max[n][m];
    printf("Enter the MAX matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Available Resources
    int avail[m];
    printf("Enter the available resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Banker's Algorithm
    int f[n], ans[n], ind = 0;
    for(int i=0;i<n;i++){
        f[i]=0;
    }
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    int y = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The system is not safe\n");
            break;
        }
    }

    if (flag == 1) {
        printf("SAFE Sequence:\n");
        for (int i = 0; i < n - 1; i++)
            printf("P%d -> ", ans[i]);
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}


// allocation matrix : 
// 2 1 0
// 1 2 2 
// 0 2 0
// 3 0 1

// MAX MAtrix:
// 8 6 3
// 9 4 3
// 5 3 3
// 4 2 3

// Available
// 4 3 2
