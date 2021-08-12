// sjf without arrival time algorithm implementation 

#include<stdio.h>

// function declarations
void bubbleSort(int* burstTime, int* processNo, int n);
void swap(int* num1, int* num2);
void computeWaitingTime(int* BurstTime, int* WaitTime, int processCount);
void computeTurnAroundTime(int* BurstTime, int* turnAroundTime, int processCount);
float AverageTime(int Time[], int n);


int main(){
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  int burst_time[n], wait_time[n], turn_around_time[n], process_no[n], i;
  float avgWaitTime = 0, avgTurnArndTime = 0;
  
  // to read process burst time and arrival time
  for(i = 0; i < n; i++){
  	printf("Enter burst time of process %d: ", i+1);
  	scanf("%d", &burst_time[i]);
  	process_no[i] = i+1;
  }
  
  // sorting the jobs, burst time depending on the process which has shortest burst time
  bubbleSort(burst_time, process_no, n);
  
  // computations
  computeWaitingTime(burst_time, wait_time, n);
  computeTurnAroundTime(burst_time, turn_around_time, n);
  avgWaitTime = AverageTime(wait_time, n);
  avgTurnArndTime = AverageTime(turn_around_time, n);
  
  // Display the output
  	printf("\nProcess no.\t burst time \t waiting time \t turnaround time\n");
	for(i = 0; i < n; i++){
		printf("      P[%d]%14d%18d%20d\n", process_no[i], burst_time[i], wait_time[i], turn_around_time[i]);
	}
	printf("Average Waiting time = %.2f\n", avgWaitTime);
	printf("Average Turn around time = %.2f\n", avgTurnArndTime);	
  
  return 0;
	}
	

void swap(int* num1, int* num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
	
	
void bubbleSort(int* burstTime, int* processNo, int n){
	int i, j, temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n-i-1; j++){
			if(burstTime[j] > burstTime[j+1]){
				swap(&burstTime[j], &burstTime[j+1]);
				swap(&processNo[j], &processNo[j+1]);
			}
		}
	}
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
	turnAroundTime[0] = BurstTime[0];
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

