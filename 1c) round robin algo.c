// round robin


#include<stdio.h>
#include<stdbool.h>
int main() {
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n];
    int wt[n];
    int tt[n];
    int tq;
    float awt = 0, att = 0;
    printf("Enter the burst times: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    int copy_bt[n];
    for(i = 0; i < n; i++) {
        copy_bt[i] = bt[i];
    }
    int t = 0;
    while(1) {
        bool done = true;
        for(i = 0; i < n; i++) {
            if(copy_bt[i] > 0) {
                done = false;
                if(copy_bt[i] > tq) {
                    t += tq;
                    copy_bt[i] -= tq;
                } else {
                    t += copy_bt[i];
                    wt[i] = t - bt[i];
                    copy_bt[i] = 0;
                }
            }
        }
        if(done == true) {
            break;
        }
    }

    for(j = 0; j < n; j++) {
        tt[j] = wt[j] + bt[j];
    }
    for(i = 0; i < n; i++) {
        awt += wt[i];
    }
    for(i = 0; i < n; i++) {
        att += tt[i];
    }
    printf("process\t  waiting time\t   burst time\t  turnaround time\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t\t%dms\t\t%dms\t\t%dms\n", i + 1, wt[i], bt[i], tt[i]);
    }
    printf("Average waiting time: %0.2fms\n", awt*1.0/n);
    printf("Average turnaround time: %0.2fms\n", att*1.0/n);
}
