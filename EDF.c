
#include<stdio.h>

typedef struct{
  int id;
  int period;
  int deadline;
  int exectime;
  int executed;
}Task;

int gcd(int a,int b){
  while(b!=0){
    int t=b;
    b=a%b;
    a=t;
  }
  return a;
}

int lcm(int a, int b){
  return a*b/gcd(a,b);
}

int main(){
  printf("enter no of tasks: ");
  int n;
  scanf("%d",&n);
  Task tasks[n];
  printf("enter id,time period and exec time of each task:\n");
  for(int i=0;i<n;i++){
    scanf("%d %d %d",&tasks[i].id,&tasks[i].period,&tasks[i].exectime);
    tasks[i].executed=0;
    tasks[i].deadline=tasks[i].period;
  }
  int stime = tasks[0].period;
  for(int i=0;i<n;i++){
    stime=lcm(stime,tasks[i].period);
  }
  for(int t=0;t<stime;t++){
    for(int i=0;i<n;i++){
      if(t%tasks[i].period==0){
        tasks[i].executed=0;
        tasks[i].deadline=t+tasks[i].period;
      }
    }
    int current=-1;
    for(int i=0;i<n;i++){
    if(tasks[i].executed<tasks[i].exectime && t<tasks[i].deadline){
      if(current==-1 || tasks[i].deadline<tasks[current].deadline){
        current=i;
      }
    }
  }
    if(current!=-1){
      tasks[current].executed++;
      printf(" %3d | Task %d\n",t+1,tasks[current].id);

    } else {
      printf(" %3d | Idle\n",t+1);
    }
}
      return 0;


}


