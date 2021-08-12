// sjf with arrival time - non preemptive

#include<stdio.h>

// function declarations
void bubbleSort(int* burstTime, int* ArrivalTime, int* processNo, int n);
void sjfsort(int* burstTime, int* ArrivalTime, int* processNo, int n);
void swap(int* num1, int* num2);
void computeStartTime(int* startTime, int* burstTime, int processCount);
void computeWaitingTime(int* WaitTime, int* ArrivalTime, int* startTime, int processCount);
void computeTurnAroundTime(int* BurstTime, int* turnAroundTime, int* WaitTime, int processCount);
float AverageTime(int Time[], int n);


int main(){
  int n;
  printf("Enter number of processes: ");
  scanf("%d", &n);
  int burst_time[n], startTime[n], arrival_time[n], wait_time[n], turn_around_time[n], process_no[n], i;
  float avgWaitTime = 0, avgTurnArndTime = 0;
  
  // to read process burst time and arrival time
  for(i = 0; i < n; i++){
  	printf("Enter arrival time and burst time of process %d: ", i+1);
  	scanf("%d %d", &arrival_time[i], &burst_time[i]);
  	process_no[i] = i+1;
  }
  
  // sorting the jobs, burst time and arrival time depending on the process which has shortest burst time
  bubbleSort(burst_time, arrival_time, process_no, n);
  sjfsort(burst_time, arrival_time, process_no, n);
  
  // computations
  computeStartTime(startTime, burst_time, n);
  computeWaitingTime(wait_time, arrival_time, startTime, n);
  computeTurnAroundTime(burst_time, turn_around_time, wait_time, n);
  avgWaitTime = AverageTime(wait_time, n);
  avgTurnArndTime = AverageTime(turn_around_time, n);
  
  // Display the output
  	printf("\nProcess no.\t burst time \t waiting time \t turnaround time \t arrival time\n");
	for(i = 0; i < n; i++){
		printf("      P[%d]%14d%18d%20d%18d\n", process_no[i], burst_time[i], wait_time[i], turn_around_time[i], arrival_time[i]);
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
	
	
// sort acc to arrival time
void bubbleSort(int* burstTime, int* ArrivalTime, int* processNo, int n){
	int i, j, temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n-i-1; j++){
			if(ArrivalTime[j] > ArrivalTime[j+1]){
				swap(&burstTime[j], &burstTime[j+1]);
				swap(&processNo[j], &processNo[j+1]);
				swap(&ArrivalTime[j], &ArrivalTime[j+1]);
			}
		}
	}
 }
 
 // sort acc to burst time and availability of processes at a particalar arrival time
 void sjfsort(int* burstTime, int* ArrivalTime, int* processNo, int n){
 	int timecompleted = 0;
 	int i, j;
 	for(i = 0; i < n; i++){
 		int swapwithindex = i;
 		for(j = i+1; j < n; j++){
 			if(ArrivalTime[j] <= timecompleted){
 				if(burstTime[j] < burstTime[i]){
	 				swapwithindex = j;	
				}
			 }
		 }
		swap(&burstTime[i], &burstTime[swapwithindex]);
		swap(&processNo[i], &processNo[swapwithindex]);
		swap(&ArrivalTime[i], &ArrivalTime[swapwithindex]);
		timecompleted += burstTime[i];
	 }
 }

void computeStartTime(int* startTime, int* burstTime, int processCount){
	int i;
	startTime[0] = 0;
	for(i = 1; i < processCount; i++){
		startTime[i] = startTime[i-1] + burstTime[i-1];
	}
}

void computeWaitingTime(int* WaitTime, int* ArrivalTime, int* start_time, int processCount){
	int i;
	WaitTime[0] = 0;
	for(i = 1; i < processCount; i++){
		WaitTime[i] = start_time[i] - ArrivalTime[i];
	}
}

void computeTurnAroundTime(int* BurstTime, int* turnAroundTime, int* WaitTime, int processCount){
	int i;
	turnAroundTime[0] = BurstTime[0];
	for(i = 1; i < processCount; i++){
		turnAroundTime[i] = WaitTime[i] + BurstTime[i];
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

