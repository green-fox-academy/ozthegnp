#include <stdio.h>

void print_array(int *array, int size);

int main()
{
	int a[] = {6, 8, 48, 1, -9, 89};
	int size = sizeof(a)/sizeof(int);

    print_array(a, size);

	//TODO: write a function, which prints out the passed array's elements.

	return 0;
}

void print_array(int *array, int size)

{
    for(int i = 0; i < size; i++){
        printf("a[%d] = %d\n",i ,array[i]);
    }
}
