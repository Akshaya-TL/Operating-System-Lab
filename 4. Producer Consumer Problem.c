// producer consumer problem
// requires 3 semaphore variables
//   1> S = mutex = mutual exclusion is maintained
//   2> E = empty locations = initial value is n
//   3> F = Filled locations = initial value is 0
// conditions met -
//   1> producer and consumer do not access the buffer at same time
//   2> consumer should not consume items from buffer when it is empty
//   3> producer should not produce/append items into buffer when it is full


#include <stdio.h>
#include <stdlib.h>


# define SIZE 5
int mutex = 1, empty = SIZE, full = 0, item = 0;

int wait(int w){	
	return (--w);
}

int signal(int s){
	return (++s);
}

void producer(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("\nProducer produces the item %d",++item);
	mutex=signal(mutex);
}

void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes item %d",item--);
	mutex=signal(mutex);
}

int main(){
	printf("Press 1 for Producer\nPress 2 for Consumer\nPress 3 for Exit\n");
	int n;
	while(1){
		printf("\nEnter your choice : ");
		scanf("%d",&n);
		switch(n){
			case 1: if((mutex==1)&&(empty!=0))
					producer();
					
					else
					printf("Buffer is full!!\n");
					break;
			case 2: if((mutex==1)&&(full!=0))
					consumer();
					else
					printf("Buffer is empty!!\n");
					break;
					
			case 3: exit(0);
					break;
		}
	}
	return 0;
}
