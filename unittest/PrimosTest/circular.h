#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isPrime(int n) {
	if (n < 2)
		return 0;
	
    int i;
	for (i = 2; i*i <= n; ++i)
		if (n % i == 0)
			return 0;

	return 1;
}

int isCircularPrime(char const* num) {
	int n = atoi(num);
	int max = strlen(num) - 1;
	
	int i;
	for (i = 0; i <= max; ++i) {
		if (!isPrime(n))
			return 0;
		n = (n % 10) * (int)pow(10, max) + n / 10;
	}
	return 1;
}
