#include<stdio.h>

int main(){

	int ArrivalTime[10],BurstTime[10],RemainingTime[10],endTime,i,smallest,processGantt[100];
	
	int completed=0,n,time,sum_wait=0,sum_turnaround=0;
	
	printf("Enter no of Processes : ");
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){

		printf("Enter arrival time for Process P%d : ",i+1);
		
		scanf("%d",&ArrivalTime[i]);
		
		printf("Enter burst time for Process P%d : ",i+1);
		
		scanf("%d",&BurstTime[i]);
		
		RemainingTime[i]=BurstTime[i];
	}

	printf("\n\nProcess\t Arrival Time\t Burst Time\t Turnaround Time\t  Waiting Time\n");
	RemainingTime[9]=9999;

	for(time=0;completed!=n;time++){
		smallest=9;
		for(i=0;i<n;i++){
			if(ArrivalTime[i]<=time && RemainingTime[i]<RemainingTime[smallest] && RemainingTime[i]>0){
				processGantt[time]=i;
				smallest=i;
			}
		}
		RemainingTime[smallest]--;
		if(RemainingTime[smallest]==0){
			completed++;
			endTime=time+1;
			printf("\n P[%d]\t %12d\t %11d\t %15d\t %12d",smallest+1,ArrivalTime[smallest], BurstTime[smallest], endTime-ArrivalTime[smallest],endTime-BurstTime[smallest]-ArrivalTime[smallest]);
			sum_wait+=endTime-BurstTime[smallest]-ArrivalTime[smallest];
			sum_turnaround+=endTime-ArrivalTime[smallest];
		}
	}	
	printf("\n\nAverage waiting time = %.2f\n",sum_wait*1.0/n);
	printf("Average Turnaround time = %.2f\n\n",sum_turnaround*1.0/n);
	
	for(i=0;i<time;i++){
		printf("%d->P%d ",i,processGantt[i]+1);
	}

}
