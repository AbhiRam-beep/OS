#include <stdio.h>

#define N 5

int forks[N] = {1, 1, 1, 1, 1};
int finished[N] = {0, 0, 0, 0, 0};

void wait(int *sem) {
  while (*sem <= 0)
    ;
  (*sem)--;
}

void signal(int *sem) { (*sem)++; }

void think(int i) { printf("Philosopher %d is thinking\n", i + 1); }

void philosopher(int i) {
  wait(&forks[i]);
  wait(&forks[(i + 1) % N]);
  printf("Philosopher %d is eating\n", i + 1);
  signal(&forks[i]);
  signal(&forks[(i + 1) % N]);
  finished[i] = 1;
}

int overlap(int i, int j) {
  return i == j || i == (j + 1) % N || (i + 1) % N == j ||
         (i + 1) % N == (j + 1) % N;
}

void simulate_one_eating() {
  printf("\nSimulation: One philosopher eats at a time\n");
  int all_finished = 0;

  while (!all_finished) {
    all_finished = 1;

    for (int i = 0; i < N; i++) {
      if (!finished[i]) {
        think(i);
        philosopher(i);
        all_finished = 0;
        break;
      }
    }
  }
}

void simulate_two_eating(int d) {
  printf("\nSimulation: Two philosophers eat at a time\n");
  int count = 0;
  while (count < d) {
    for (int i = 0; i < N; i++) {
      if (!finished[i]) {
        int paired = 0;
        for (int j = i + 1; j < N; j++) {
          if (!finished[j] && forks[i] && forks[(i + 1) % N] && forks[j] &&
              forks[(j + 1) % N] && !overlap(i, j)) {
            philosopher(i);
            philosopher(j);
            printf("Philosophers %d and %d have finished eating\n", i + 1,
                   j + 1);
            count += 2;
            paired = 1;
            break;
          }
        }
        if (!paired && !finished[i]) {
          philosopher(i);
          printf("Philosopher %d has finished eating\n", i + 1);
          count++;
        }
      }
    }
  }
}

int main() {
  int hungry_count;
  printf("Enter number of hungry philosophers (0 to %d): ", N);
  scanf("%d", &hungry_count);

  if (hungry_count < 0 || hungry_count > N) {
    printf("Invalid number.\n");
    return 1;
  }

  int hungry[N] = {0};

  printf("Enter positions (1 to %d) of hungry philosophers:\n", N);
  for (int i = 0; i < hungry_count; i++) {
    int pos;
    scanf("%d", &pos);
    if (pos < 1 || pos > N) {
      printf("Invalid position.\n");
      return 1;
    }
    hungry[pos - 1] = 1;
  }

  for (int i = 0; i < N; i++) {
    if (!hungry[i]) {
      finished[i] = 1;
    }
  }

  simulate_one_eating();

  for (int i = 0; i < N; i++) {
    forks[i] = 1;
    finished[i] = hungry[i] ? 0 : 1;
  }

  simulate_two_eating(hungry_count);

  return 0;
}
