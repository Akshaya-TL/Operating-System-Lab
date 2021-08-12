//First Come First Serve Scheduling Algorithm implementation

#include<stdio.h>
#include<stdlib.h>

void computeWaitingTime(int* BurstTime, int* WaitTime, int processCount);
void computeTurnAroundTime(int* BurstTime, int* turnAroundTime, int processCount);
float AverageTime(int Time[], int n);

int main(){
	int n, i;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	int processArray[n], BurstTime[n], WaitingTime[n], TurnAroundTime[n];
	
	printf("\nEnter the order of processes in terms of 1, 2, 3, 4,...n: ");
	for(i = 0; i < n; i++){
		scanf("%d", processArray + i);
	}
	
	for(i = 0; i < n; i++){
		printf("Enter the burst time of the process %d: ", processArray[i]);
		scanf("%d", BurstTime + i);
	}
	
	computeWaitingTime(BurstTime, WaitingTime, n);
	computeTurnAroundTime(BurstTime, TurnAroundTime, n);
	
	printf("\nProcess no.\t burst time \t waiting time \t turnaround time\n");
	for(i = 0; i < n; i++){
		printf("%10d%14d%18d%20d\n", processArray[i], BurstTime[i], WaitingTime[i], TurnAroundTime[i]);
	}
	
	printf("Average Waiting time = %.2f\n", AverageTime(WaitingTime, n));
	printf("Average Turn around time = %.2f\n", AverageTime(TurnAroundTime, n));	
	
	return 0;
	
}

void computeWaitingTime(int* BurstTime, int* WaitTime, int processCount){
	int i;
	WaitTime[0] = 0;
	for(i = 1; i < processCount; i++){
		WaitTime[i] = WaitTime[i-1] + BurstTime[i-1];
	}
}

void computeTurnAroundTime(int* BurstTime, int* turnAroundTime, int processCount){
	int i;
	turnAroundTime[0] = BurstTime[0]; // waitingTime[i] + BurstTime[i];  IMPORTANTS
	for(i = 1; i < processCount; i++){
		turnAroundTime[i] = turnAroundTime[i-1] + BurstTime[i];
	}
}

float AverageTime(int Time[], int n){
	int i;
	float avg = 0;
	for(i = 0; i < n; i++){
		avg += Time[i];
	}
	return avg/n;
}

