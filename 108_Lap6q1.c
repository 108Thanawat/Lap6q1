#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;

void *calculate(void *d);

int main(int argc, char *argv[])
{
	int num = 0;
	printf("Input Number:");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		sum += i;
	}
	printf("%d\n", sum);
	sum = 0;
	pthread_t t1;
	pthread_create(&t1, NULL, &calculate, (void *)&num);
	pthread_join(t1, NULL);
	printf("%d\n", sum);

	return 0;
}

void *calculate(void *d)
{
	int *maxNum = (int *)(d);
	*maxNum *= 2;
	for (int i = 1; i <= (*maxNum); i++)
	{
		sum += i;
	}
}
