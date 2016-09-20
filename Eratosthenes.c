//Sieve of Eratosthenes Algorithm : Sam Fellers
//input: An integer J > 1
//output: An array listing primes <= J
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primes[1000000];

main( int argc, char *argv[]){

		if( argc != 2){ 
			printf("usage: %s <number you want to count the primes to (up to 1 mil)>", argv[0]); 
			exit(0);
		}
		int k,l;
		int j = atoi(argv[1]);
		calcPrimes(j);
		l = 0;
		printf("First 5 primes: ");
		for(k = 0;k<100;k++){
			if(primes[k] == 1 && l < 5){
				printf("%d ", k);
				l = l + 1;
			}
		}
		l = 0;
		printf("\nLast 5 primes: ");
		for(k = j;k>0;k--){
			if(primes[k] == 1 && l < 5){
				printf("%d ", k);
				l = l + 1;
			}
		}	
		printf("\n");
		printf("Number of primes = %d\n", calcNumberOfPrimes(j));
		for(k=2;k<8;k++){
			j = (int)pow(7,k);
			printf("pi(7^%d) = %d", k, (int)(j/log(j)));
			calcPrimes(j);
			//printf("\nj = %d\n", j);
			printf("	real number = %d\n",calcNumberOfPrimes(j));
		}

}

calcPrimes(int j){
	primes[1]=0;
	int i,k;
	int l = 0;

	for(i=2;i<j+1;i++){ primes[i]=1; }

	int p = 2;
	while(p <= (int)sqrt(j)){
		i = p+p;
		while(i <= j){ primes[i]=0; i = i + p; }
		i = p+1;
		while(i <= (int)sqrt(j) && primes[i] == 0){ i = i + 1; }
		p = i;
	}

}

int calcNumberOfPrimes(int j){
		int l = 0;
		int k;
		for(k=0;k<j+1;k++){
			if(primes[k]==1){
				l = l + 1;
			}
		}
		return l;
}
