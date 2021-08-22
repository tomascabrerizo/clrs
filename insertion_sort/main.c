#include <stdlib.h>
#include <stdio.h>

#define count(array) (sizeof(array)/sizeof(array[0]))

void insertion_sort(int *array, int array_size)
{
    for(int j = 1; j < array_size; ++j)
    {
        int key = array[j];
        int i = j-1;
        while(i >= 0 && array[i] > key)
        {
            array[i+1] = array[i];
            i = i-1;
        }
        array[i+1] = key;
    }
}

int main()
{
    int array[] = {9, 1, 4, 0, 7, 2, 9, 0, 1, 8, 3, 9, 0, 1};   
    
    printf("unsorted \n");
    for(int i = 0; i < count(array); ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
   
    insertion_sort(array, count(array));

    printf("sorted \n");
    for(int i = 0; i < count(array); ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
