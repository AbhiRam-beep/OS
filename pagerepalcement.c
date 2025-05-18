#include <stdio.h>

int findind(int frames[], int framecount, int page) {
  for (int i = 0; i < framecount; i++) {
    if (frames[i] == page) {
      return i;
    }
  }
  return -1;
}

void printframe(int frames[], int framecount) {
  for (int i = 0; i < framecount; i++) {
    if (frames[i] == -1) {
      printf("- ");
    } else {
      printf("%d ", frames[i]);
    }
  }
  printf("\n ");
}

void fifo(int ref[], int framecount, int n) {
  int frames[framecount];
  for (int i = 0; i < framecount; i++) {
    frames[i] = -1;
  }
  int ind = 0;
  int pagefaults = 0;
  printf("fifo:\n");
  for (int i = 0; i < n; i++) {
    if (findind(frames, framecount, ref[i]) == -1) {
      frames[ind] = ref[i];
      ind = (ind + 1) % framecount;
      pagefaults++;
    }
    printframe(frames, framecount);
  }
  printf("Total page faults: %d\n", pagefaults);
}

void optimal(int ref[], int framecount, int n) {
  int frames[framecount];
  for (int i = 0; i < framecount; i++) {
    frames[i] = -1;
  }
  int ind = 0;
  int pagefaults = 0;
  printf("optimal:\n");
  for (int i = 0; i < n; i++) {
    if (findind(frames, framecount, ref[i]) == -1) {
      int replace = -1, farthest = i + 1;
      for (int j = 0; j < framecount; j++) {
        int k;
        for (k = i + 1; k < n; k++) {
          if (frames[j] == ref[k]) {
            break;
          }
        }
        if (k > farthest) {
          farthest = k;
          replace = j;
        }
        if (k == n) {
          replace = j;
          break;
        }
      }
      if (replace == -1)
        replace = 0;
      frames[replace] = ref[i];
      pagefaults++;
    }
    printframe(frames, framecount);
  }
  printf("Total page faults: %d\n", pagefaults);
}

void lru(int ref[], int framecount, int n) {
  int frames[framecount], recent[framecount];
  for (int i = 0; i < framecount; i++) {
    frames[i] = -1;
    recent[i] = -1;
  }
  int t = 0, pagefaults = 0;
  printf("LRU:\n");
  for (int i = 0; i < n; i++) {
    int ind = findind(frames, framecount, ref[i]);
    if (ind != -1) {
      recent[ind] = t;
    } else {
      int lind = 0;
      for (int j = 0; j < framecount; j++) {
        if (recent[lind] > recent[j]) {
          lind = j;
        }
      }
      frames[lind] = ref[i];
      recent[lind] = t;
      pagefaults++;
    }
    t++;
    printframe(frames, framecount);
  }
  printf("Total page faults: %d\n", pagefaults);
}

int main() {
  int pages[] = {1, 4, 2, 3, 2, 1};
  int n = sizeof(pages) / sizeof(pages[0]);
  int frameCount = 3;

  fifo(pages, frameCount, n);
  optimal(pages, frameCount, n);
  lru(pages, frameCount, n);

  return 0;
}
