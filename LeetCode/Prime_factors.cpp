#include<iostream>
#include<math.h>

using namespace std;

void prime_factors(int n) {
	int i;
	while (n % 2 == 0) {
		n = n / 2;
		printf("%d ", 2);
	}

	for (i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			n = n / i;
			printf("%d ", i);
		}
	}

	if (n > 2) {
		printf("%d", n);
	}
	printf("\n");
}

void Prime_Factor(int n){
	while (n % 2 == 0){
		n = n / 2;
		cout << 2 << " ";
	}
	int i = 3;
	for (i = 3; i <= sqrt(n); i += 2){
		while (n%i == 0){
			n = n / i;
			cout << i << " ";
		}
	}
	if (i>2)
		cout << i << endl;
		
}

void main() {
	int n = 315;
	prime_factors(1001);
	Prime_Factor(1001);
}