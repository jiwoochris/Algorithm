#include <stdio.h>

int main() {
	int r, c;
	int matrix[10][100];
	int way[10][100];
	int up, down, go;
	int min;

	scanf_s("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}

	for (int j = 0; j < c; j++) {
		for (int i = 0; i < r; i++) {
			way[i][j] = 9999;

			up = i + 1;
			go = i;
			down = i - 1;

			if (i == 0)
				down = r - 1;
			else if (i == r - 1)
				up = 0;

			if (i == 0 && j == 0)
				way[i][j] = matrix[i][j];

			if (j > 0 && (way[up][j - 1] != 9999 || way[go][j - 1] != 9999 || way[down][j - 1] != 9999)) {
				min = way[up][j - 1];

				if (min > way[go][j - 1])
					min = way[go][j - 1];

				if (min > way[down][j - 1])
					min = way[down][j - 1];

				way[i][j] = matrix[i][j] + min;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", way[i][j]);
		}
		printf("\n");
	}

	//printf("%d", way[r - 1][c - 1]);

	return 0;
}