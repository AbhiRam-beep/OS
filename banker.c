#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("Enter no. of processes: ");
  int n;
  scanf("%d",&n);
  printf("Enter no. of resources: ");
  int m;
  scanf("%d",&m);
  int alloc[n][m],max[n][m],avail[m],need[n][m];
  for(int i=0;i<n;i++){
    printf("enter allocation for p%d:",i+1);
    for(int k=0;k<m;k++) scanf("%d",&alloc[i][k]);
    printf("enter max for p%d:",i+1);
    for(int k=0;k<m;k++) scanf("%d",&max[i][k]);
  }
  printf("enter initial available resources:");
  for(int i=0;i<m;i++){
    scanf("%d",&avail[i]);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }
  int p,req[m];
  printf("enter pid with new request: ");
  scanf("%d",&p);
  printf("Enter new request resources: ");
  for(int i=0;i<m;i++){
    scanf("%d",&req[i]);
  }
  int valid=1;
  for(int i=0;i<m;i++){
    if(req[i]>need[p][i] || req[i]>avail[i]){
      valid=0;
      break;
    }
  }
  if(valid){
    for(int i=0;i<m;i++){
      avail[i]-=req[i];
      alloc[p][i]+=req[i];
      need[p][i]-=req[i];
    }
  } else {
    printf("request cant be granted\n");
    return 0;
  }
  int finish[n];
  for(int i=0;i<n;i++){
    finish[i]=0;
  }
  int work[m],safeseq[n];
  for(int i=0;i<m;i++){
    work[i]=avail[i];
  }
  int count=0;
  while(count<n){
    int found=0;
    for(int i=0;i<n;i++){
      if(!finish[i]){
        int j;
        for(j=0;j<m;j++){
          if(need[i][j]>work[j]) break;
        }
        if(j==m){
            printf("P%d is finished (",i+1);
            for(int k=0;k<m;k++){
              work[k]+=alloc[i][k];
              printf("%d ",work[k]);
            }
            printf(")\n");
            safeseq[count++]=i+1;
            finish[i]=1;
            found=1;
          }
        }
      }
      if(!found) break;
    }
    if(count==n){
      printf("The system is in safe state.\nSafe Sequence:  ");
      for(int i=0;i<n;i++){
        printf("P%d ",safeseq[i]);
      }
      printf("\n");
    } else {
      printf("System not in safe state\n");
    }
  
  return 0;
}
