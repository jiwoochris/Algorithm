#include <stdio.h>

struct elephant {
	int iq;
	int weight;
	int index;
};

struct large_subset {
	int iq;
	int weight;
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int n;

	struct elephant e[100];

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &e[i].weight, &e[i].iq);
		e[i].index = i+1;
	}

	struct elephant temp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (e[i].weight > e[i + 1].weight) {
				temp.weight = e[i].weight;
				temp.iq = e[i].iq;
				temp.index = e[i].index;

				e[i].weight = e[i + 1].weight;
				e[i].iq = e[i + 1].iq;
				e[i].index = e[i + 1].index;

				e[i + 1].weight = temp.weight;
				e[i + 1].iq = temp.iq;
				e[i + 1].index = temp.index;
			}
		}
	}

	int large_subset[100][100];
	int key_weight;
	int key_iq;

	for (int i = 0; i <= n; i++) {	
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				large_subset[i][j] = 0;
			}
			else if (e[i].weight < e[j].weight && e[i].iq > e[j].iq) {
				large_subset[i][j] = large_subset[i][j - 1] + 1;
			}
			else {
				large_subset[i][j] = max(large_subset[i][j - 1], large_subset[i - 1][j]);
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", large_subset[i][j]);
		}
		printf("\n");
	}



	printf("\n\nOutput:\n");
	printf("%d\n", large_subset[n][n]);

	/*for (int i = 0; i < large_subset[n][n]; i++) {
		printf("%d\n", )
	}*/
	

	return 0;
}