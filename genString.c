#include "basic.h"

void main() {
	int i, j, n;

	for (i = 0; i < N; i++) {
		for (j = 0; j < 100; j++) {
			n = (rand() % (58)) + 65;
			if((n >= 91) && (n <= 96)) {
				j --;
				continue;
			}
			printf("%c", n);
		}
		printf("\n");
	}
}