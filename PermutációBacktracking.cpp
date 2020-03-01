#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>

using namespace std;


void backtracking(int, int*, int);
void forward_checking(int, int*, int);
void printArray(int*, int);
int contains(int*, int);
int main()
{
	int length;
	printf("Adja meg a szamsorozat hosszat: ");
	scanf_s("%d", &length);
	int* permutations = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i) {
		permutations[i] = i+1;
	}

	printf("Backtracking:\n");
	clock_t t1;
	t1 = clock();
	backtracking(0, permutations, length);

	t1 = clock() - t1;
	double time_taken1 = ((double)t1) / CLOCKS_PER_SEC; 
	
	printf("Forward checking:\n");
	clock_t t2;
	t2 = clock();
	forward_checking(0,permutations,length);
	t2 = clock() - t2;
	double time_taken2 = ((double)t2) / CLOCKS_PER_SEC;

	printf("bactraking() %f masodpercig futott \n", time_taken1);
	printf("forward_checking() %f masodpercig futott \n", time_taken2);
	
	free(permutations);
	return 0;
}

void backtracking(int init, int* permutations, int length) {
	int i;
	if (init == length) { printArray(permutations, length); }
	else {
		for (i = init; i < length; ++i) {
			swap(permutations[init], permutations[i]);
			backtracking(init + 1, permutations, length);
			swap(permutations[init], permutations[i]);
		}
	}
}

void forward_checking(int init, int* permutations, int length)
{
	int i;
	if (init == length) { printArray(permutations, length); }
	else
	{
		for (i = 1; i <= length; ++i)
		{
			permutations[init] = i;
			if (contains(permutations, init)) { forward_checking(init + 1, permutations, length); }
		}
	}
}

void printArray(int* permutations, int length)
{
	int i;
	for (i = 0; i < length; ++i)
	{
		printf("%d", permutations[i]);
	}
	printf("\n");
}

int contains(int* permutations, int init)
{
	int i;
	for (i = init - 1; i >= 0; --i)
	{
		if (permutations[i] == permutations[init]) { return 0; }
	}
	return 1;
}
