#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;
	p = (int *) malloc(sizeof(int));

	*p = 52;
	printf("*p = %d\n", *p);

	free(p);
	printf("\n\nFreeing p...\n");
	printf("*p = %d\n", *p);

	return (0);
}
