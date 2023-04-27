#include <stdio.h>

void copy_arr(double [], double [], int);
void copy_ptr(double*, double*, int);
void copy_ptrs(double*, double*, double*);

int max(int*, int);

int max_index(double*, int);

double compare(double*, int);

void oppo(double*, int);

int main(void) {
	//double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	//double target1[5];
	//double target2[5];
	//double target3[5];
	//
	//copy_arr(target1, source, 5);
	//copy_ptr(target2, source, 5);
	//copy_ptrs(target3, source, source + 5);

	//int arr[5] = { 1, 2, 3, 4, 3 };
	//printf("max = %d", max(arr, 5));

	double arr[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 3.3 };
	printf("最大值的下标：%d\n", max_index(arr, 6));
	printf("最大值和最小值的差值：%g\n", compare(arr, 6));
	oppo(arr, 6);

	double arr_two[2][3];
	double arr_2[2][3] = { 1.1, 2.2, 3.3, 4.4, 5.5, 3.3 };
	for (int i = 0; i < 2; i++)
		copy_arr(arr_two[i], arr_2[i], 3);
	printf("%g\n", arr_two[0][1]);

	double arr8[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 3.3, 2.2 };
	double arr8_3[3] = { 0 };
	copy_arr(arr8_3, arr8 + 2, 3);
	printf("%g %g %g\n", arr8_3[0], arr8_3[1], arr8_3[2]);

	return 0;
}

//2.
void copy_arr(double target[], double source[], int num) {
	int i;

	for (i = 0; i < num; i++)
		target[i] = source[i];
}

void copy_ptr(double* target, double* source, int num) {
	int i;

	for (i = 0; i < num; i++)
		*(target + i) = *(source + i);
}

void copy_ptrs(double* target, double* source, double* end) {
	int i;

	for (i = 0; i < end - source; i++)
		*(target + i) = *(source + i);
}

//3.
int max(int* arr, int num) {
	int max = 0;

	for (int i = 0; i < num; i++) {
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

//4.
int max_index(double* arr, int num) {
	int i, index = 0;

	for (i = 0; i < num - 1; i++) {
		index = arr[i] > arr[i + 1] ? i : i + 1;
	}

	return index;
}

//5.
double compare(double* arr, int num) {
	double max, min, answer;
	max = 0, min = 100;

	for (int i = 0; i < num; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	
	return max - min;
}

//6.
void oppo(double* arr, int num) {
	int i, j;
	double oppo_arr[6];

	for (i = 0, j = num - 1; i < num; i++, j--) {
		oppo_arr[i] = arr[j];
		printf("%5g", oppo_arr[i]);
	}
	printf("\n");
}