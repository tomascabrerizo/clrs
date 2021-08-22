#include <stdlib.h>
#include <stdio.h>

#define count(array) (sizeof(array)/sizeof(array[0]))

void Merge(int *array, int begin, int mid, int end)
{
    int n0 = mid - begin;
    int n1 = end - mid;
    
    int n0_size = n0 + 1;
    int n1_size = n1 + 1;
    int *left = (int *)malloc(n0_size*sizeof(int));
    int *right = (int *)malloc(n1_size*sizeof(int));

    for(int i = 0; i < n0; ++i)
    
    {
        left[i] = array[begin+i];
    }
    for(int i = 0; i < n1; ++i)
    {
        right[i] = array[mid+i];
    }
    left[n0_size-1] = INT_MAX;
    right[n1_size-1] = INT_MAX;

    int i = 0;
    int j = 0;
    for(int k = begin; k < end; ++k)
    {
        if(left[i] <= right[j])
        {
            array[k] = left[i];
            ++i;
        }
        else
        {
            array[k] = right[j];
            ++j;
        }
    }

    free(left);
    free(right);
}

void MergeSort(int *array, int begin, int end)
{
    if(begin < end-1)
    {
        int mid = (int)(0.5f*(begin+end) + 0.5f);
        MergeSort(array, begin, mid);
        MergeSort(array, mid, end);
        Merge(array, begin, mid, end);
    }
}

int main()
{
#if 1 
    int array[] = {
        9,8,3,2,9,0,1,8,3,9,0,2,8,1,9,0,3,8,9,2,0,1,8,3,9,0,
        2,7,8,1,4,9,7,2,8,7,4,98,2,1,7,3,9,8,1,2,78,39,7,2,1,
        9,7,3,8,2,9,1,7,3,8,972,1,98,73,8,123,
    };
#else
    int array[] = {7,3,8};    
#endif
    printf("not sorted (count:%llu)\n", count(array));
    for(int i = 0; i < count(array); ++i)
    {
        printf("[%d] ", array[i]);
    }
    printf("\n");
    
    MergeSort(array, 0, count(array));
    printf("\nsorted (count:%llu)\n", count(array));
    for(int i = 0; i < count(array); ++i)
    {
        printf("[%d] ", array[i]);
    }
    printf("\n");
    return 0;
}
