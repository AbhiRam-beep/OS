#include <stdio.h>

int main() {
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  int wt[n], tat[n], bt[n], gant[n];
  printf("Enter burst times:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &bt[i]);
  }
  wt[0] = 0;
  tat[0] = bt[0];
  int wtavg = 0, tatavg = tat[0];
  for (int i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = tat[i - 1] + bt[i];
    wtavg += wt[i];
    tatavg += tat[i];
  }
  gant[0] = bt[0];
  for (int i = 1; i < n; i++) {
    gant[i] = gant[i - 1] + bt[i];
  }
  printf("\nProcess\tBT\tWT\tTAT\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }
  printf("\nAverage WT: %.2f", wtavg * 1.0 / n);
  printf("\nAverage TAT: %.2f\n", tatavg * 1.0 / n);
  printf("\nGantt Chart:\n|");
  for (int i = 0; i < n; i++) {
    printf("  P%d  |", i + 1);
  }
  printf("\n0");
  for (int i = 0; i < n; i++) {
    printf("\t%d", gant[i]);
  }
  printf("\n");

  return 0;
}
