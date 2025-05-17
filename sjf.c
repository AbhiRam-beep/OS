#include <stdio.h>

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int wt[n], tat[n], bt[n], gant[n],proc[n];
    for(int i=0;i<n;i++){
    proc[i]=i+1;
    }
    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(bt[j]<bt[i]){
        swap(&bt[j],&bt[i]);
        swap(&proc[i],&proc[j]);
      }
    }
  }
    wt[0] = 0;
    tat[0] = bt[0];
    int wtavg = 0, tatavg = tat[0];
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    gant[0] = bt[0];
    for (int i = 1; i < n; i++) {
        gant[i] = gant[i - 1] + bt[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", proc[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage WT: %.2f", wtavg * 1.0 / n);
    printf("\nAverage TAT: %.2f\n", tatavg * 1.0 / n);
    
printf("\nGantt Chart:\n|");
for (int i = 0; i < n; i++) {
    printf("  P%d  |", proc[i]);
}
printf("\n0");
for (int i = 0; i < n; i++) {
    printf("\t%d", gant[i]);
}


    return 0;
}printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf("  P%d  |", i + 1);
    }
    printf("\n0");
    for (int i = 0; i < n; i++) {
        printf("\t%d", gant[i]);
    }
    printf("\n");
