#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pancakes[30];
int stack[30];
int i = 0;

void flip(int f) {
	for (int n = 0; n < i; n++)
		stack[n] = pancakes[i - n - f];
}


int main() {
	char input[100];
	char* str = NULL;

	gets_s(input, sizeof(input));

	char* ptr = strtok_s(input, " ", &str);
	pancakes[i] = atoi(ptr);

	while (1) {
		i++;
		printf("%s\n", ptr);
		ptr = strtok_s(NULL, " ", &str);
		if (ptr == NULL)
			break;
		pancakes[i] = atoi(ptr);
	}

	int max = 0;
	int max_num;

	for (int j = 0; j < i; j++) {
		printf("%d ", pancakes[j]);

		if (pancakes[j] > max) {
			max = pancakes[j];
			max_num = j;
		}
	}

	fix = 1;

	if (max_num == i - 1) {
		fix++;
		i = i - fix;
	}
	else if (max_num == 0) {
		flip(fix);
		fix++;
		i = i - fix;
	}
	else {
		flip(i - max_num);
		flip(fix);
		fix++;
		i = i - fix;
	}





	return 0;
}