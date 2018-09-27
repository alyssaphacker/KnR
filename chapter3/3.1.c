#include<stdio.h>
#include<stdlib.h>
//value x in ordered array of length
int binsearch(int x, int v[], int n){ 
	int low, high, mid; // these are used as indices

	high = mid = n-1;
	low = 0; 
	while(low + 1 < high){
		mid = (low+high)/2;
		printf("low: %d, mid: %d, high: %d\n", low, mid, high);
		(x < v[mid]) ? (high = mid-1) : (low = mid);		
	}
	if(x == v[mid]) return mid;

	//i used two conditionals but removed one from the loop. should be a lot better!
	if(x == v[low]) return low;
	if(x == v[high]) return high;
	else return -1;
}

int main(int argc, char *argv[]){
	int search_me[] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};

	


	//printf("%lu", sizeof(search_me)/sizeof(int));
	printf("value %d is index: %d", atoi(argv[1]), 
		binsearch(atoi(argv[1]), search_me, 10));
}
