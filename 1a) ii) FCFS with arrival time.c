// FCFS with arrival time
/* REQUIREMENTS
	- Inputs
		- no. of processes n
		- arrival time[n]
		- burst time[n] 
	- computation
		- sort burst time based on arrival time
		- turn around time[n] (entry time, exit time)   ----- waiting time + burst time
		- waiting time[n] (entry time, exec start time)
		- avgWaitTime
		- avgTAT
	- Output
		- process execution order
		- avg Wait time
		- avg turn around time
*/

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int* arrivalT, int* burstT, int* processOrder, int n);
void computeWaitingTime(int* BurstTime, int* WaitTime, int* arrivalTime, int processCount);
void computeTurnAroundTime(int* BurstTime, int* turnAroundTime,  int processCount);
float AverageTime(int Time[], int n);
void swap(int* a, int* b);

int*  WaitingTime;
int main(){
	int n, i;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	int processArray[n], BurstTime[n], TurnAroundTime[n], ArrivalTime[n];
	 WaitingTime = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++){
		printf("\nEnter the process number, arrival time and burst time: ");
		scanf("%d %d %d", &processArray[i], &ArrivalTime[i], &BurstTime[i]);
	}
	
	bubbleSort(ArrivalTime, BurstTime, processArray, n);
	computeWaitingTime(BurstTime, WaitingTime, ArrivalTime, n);
	computeTurnAroundTime(BurstTime, TurnAroundTime, n);
	
	printf("\nProcess no.\t arrival time \t burst time \t waiting time \t turnaround time\n");
	for(i = 0; i < n; i++){
		printf("%10d%18d%14d%18d%20d\n", processArray[i], ArrivalTime[i], BurstTime[i], WaitingTime[i], TurnAroundTime[i]);
	}
	
	printf("Average Waiting time = %.2f\n", AverageTime(WaitingTime, n));
	printf("Average Turn around time = %.2f\n", AverageTime(TurnAroundTime, n));	
	
	return 0;
	
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int* arrivalT, int* burstT, int* processOrder, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n-i-1; j++){
			if(arrivalT[i] > arrivalT[i+1]){
				swap(&arrivalT[i], &arrivalT[i+1]);
				swap(&burstT[i], &burstT[i+1]);
				swap(&processOrder[i], &processOrder[i+1]);
			}	
		}
	}
}

void computeWaitingTime(int* BurstTime, int* WaitTime, int* arrivalTime, int processCount){
	int i;
	WaitTime[0] = 0;
	for(i = 1; i < processCount; i++){
		WaitTime[i] = WaitTime[i-1] + BurstTime[i-1]-arrivalTime[i];
	}
}

void computeTurnAroundTime(int* BurstTime, int* turnAroundTime, int processCount){
	int i;
	turnAroundTime[0] = BurstTime[0];
	for(i = 1; i < processCount; i++){
		//turnAroundTime[i] = turnAroundTime[i-1] + BurstTime[i] - arrivalTime[i]; // ignore this
		turnAroundTime[i] =   WaitingTime[i] + BurstTime[i];
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



