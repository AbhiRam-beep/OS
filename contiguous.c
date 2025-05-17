
#include <stdio.h>

void firstfit(int b[], int p[], int n, int m) {
    int alloc[n];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                alloc[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }

    printf("First Fit:\n");
    for (int i = 0; i < n; i++) {
        if (alloc[i] != -1)
            printf("P%d -> B%d\n", i + 1, alloc[i] + 1);
        else
            printf("P%d -> Not Allocated\n", i + 1);
    }
    printf("\n");
}

void bestfit(int b[], int p[], int n, int m) {
    int alloc[n];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for (int i = 0; i < n; i++) {
    int best=-1;
        for (int j = 0; j < m; j++) {
                         
            if(b[j]>=p[i] && (best==-1 || b[j]<b[best])){
               best=j; 
            }}
            if (best!=-1) {
                alloc[i] = best;
                b[best] -= p[i];
                
            } 
    }
    printf("Best Fit:\n");
    for (int i = 0; i < n; i++) {
        if (alloc[i] != -1)
            printf("P%d -> B%d\n", i + 1, alloc[i] + 1);
        else
            printf("P%d -> Not Allocated\n", i + 1);
    }
    printf("\n");
}

void worstfit(int b[], int p[], int n, int m) {
    int alloc[n];
    for (int i = 0; i < n; i++)
        alloc[i] = -1;
    for (int i = 0; i < n; i++) {
    int worst=-1;
        for (int j = 0; j < m; j++) {            
            if(b[j]>=p[i] && (worst==-1 || b[j]>b[worst])){
               worst=j; 
            }}
            if (worst!=-1) {
                alloc[i] = worst;
                b[worst] -= p[i];
                
            } 
    }
    printf("Worst Fit:\n");
    for (int i = 0; i < n; i++) {
        if (alloc[i] != -1)
            printf("P%d -> B%d\n", i + 1, alloc[i] + 1);
        else
            printf("P%d -> Not Allocated\n", i + 1);
    }
    printf("\n");
}



int main() {
    int blocks1[] = {100, 500, 200, 300, 600};
    int blocks2[] = {100, 500, 200, 300, 600};
    int blocks3[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};

    int m = sizeof(blocks1) / sizeof(blocks1[0]);
    int n = sizeof(processes) / sizeof(processes[0]);

    firstfit(blocks1, processes, n, m);
    bestfit(blocks2, processes, n, m);
    worstfit(blocks3, processes, n, m);

    return 0;
}
