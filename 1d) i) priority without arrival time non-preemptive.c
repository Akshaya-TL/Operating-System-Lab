// priority algorithm - non-preemptive without arrival time
#include<stdio.h>
#include<stdlib.h>

int n, *waitingTime, *tat, totaltat = 0, totalwt = 0;
void sort(int burstTime[][n], int* priority, int s);
void swap(int* a, int* b);

int main(){
	int i;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	waitingTime = (int*)malloc(sizeof(int)*n);
	tat = (int*)malloc(sizeof(int)*n);
	int PnoBT[2][n], priority[n];
	for(i = 0; i < n; i++){
		printf("Enter process %d burst time: ", i+1);
		scanf("%d", &PnoBT[1][i]);
		printf("Enter process %d priority: ", i+1);
		scanf("%d", &priority[i]);
		PnoBT[0][i] = i+1;
	}
	
	sort(PnoBT, priority, n);
	
	printf("Process\t Priority\t Burst Time\t Waiting Time\t Turn Around Time\n");
	for(i = 0; i < n; i++){
		printf("  P[%d]\t %8d\t %10d\t %12d\t %16d\n", PnoBT[0][i], priority[i], PnoBT[1][i], waitingTime[i], tat[i]);
	}
	
	printf("\nAverage waiting time = %.2f", totalwt*1.0/n);
	printf("\nAverage turn around time = %.2f", totaltat*1.0/n);	
	
	return 0;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int burstTime[][n], int* priority, int s){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n-i-1; j++){
			if(priority[j] > priority[j+1]){
				swap(&priority[j], &priority[j+1]);
				swap(&burstTime[0][j], &burstTime[0][j+1]);				
				swap(&burstTime[1][j], &burstTime[1][j+1]);				
			}
		}
	}
	waitingTime[0] = 0;
	tat[0] = burstTime[1][0];
	totaltat += tat[0];
	for(i = 1; i < n; i++){
		waitingTime[i] = waitingTime[i-1] + burstTime[1][i-1];
		tat[i] =  waitingTime[i] + burstTime[1][i];
		totalwt += waitingTime[i];
		totaltat += tat[i];
	}
}
