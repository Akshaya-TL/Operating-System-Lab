#include<stdio.h>

int main(){
	int n, processes;
	printf("Enter number of resources: ");
	scanf("%d", &n);

	int Total[n], i, j, Available[n];
	printf("Enter total number of allocated resources: ");
	for(i = 0; i < n; i++){
		Available[i] = 0;
		scanf("%d", Total + i);
	}
	
	printf("Enter number of processes: ");
	scanf("%d", &processes);

	int allocated[processes][n], MaxAllocation[processes][n], need[processes][n];
	printf("Enter initial allocation matrix: ");
	for(i = 0; i < processes; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &allocated[i][j]);
			Available[j] += allocated[i][j];
		}
	}
	
	for(i = 0; i < n; i++){
		Available[i] = Total[i] - Available[i];	
	}
	
	printf("Enter max need of each process:");
	for(i = 0; i < processes; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &MaxAllocation[i][j]);
			need[i][j] = MaxAllocation[i][j] - allocated[i][j];
		}
	}
	
	printf("Need matrix is\n");
	for(i = 0; i < processes; i++){
		for(j = 0; j < n; j++){
			printf("%d ", need[i][j]);
		}
		printf("\n");
	}
	printf("Available Resources are: ");
	for(i = 0; i < n; i++){
		printf("%d ", Available[i]);
	}
	
	// computing the process execution order
	int completed[processes], k, count;
	for(i = 0; i < processes; i++){
		completed[i] = 0;
	}
	printf("\n\nProcess execution order: \n");
	for(i = 0; i < processes; i++){
		for(j = 0; j < processes; j++){
			count = 0;
			for(k = 0; k < n; k++){
				if(completed[j] != 1 && Available[k] >= need[j][k]){
					count += 1;
				}
				else{
					break;
				}
			}
			if(count == n){
				completed[j] = 1;
				printf("Process %d under progress....\n", j+1);
				printf("\nAvailable resources: ");
				for(k = 0; k < n; k++){
					Available[k] += allocated[j][k];
					printf("%d ", Available[k]);
				}
				printf("\n\n");
				break;
			}
			else if(j == processes){
				printf("\nSafe sequence not possible\n");
				count = -1;
				break;
			}
		}
			if(count == -1){
				break;
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	

