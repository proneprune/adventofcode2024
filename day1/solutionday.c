#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
      
      // If a is smaller, positive value will be returned
    return (*(int*)a - *(int*)b);
}

int *getArrayFromInput()
{
    
    FILE *file_ptr;
    char str[50];
    int *arr1 = (int *)malloc(1000 * sizeof(int));
    int *arr2 = (int *)malloc(1000 * sizeof(int));
    int idx = 0;  // Index to keep track of where to store numbers in arr1 and arr2
    int *arr3 = (int *)malloc(1000 * sizeof(int));
    int *arr4 = (int *)malloc(1000 * sizeof(int));

    file_ptr = fopen("input.txt", "r");

    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }

    // Reading stinrg using fgets
    printf("Content of this file are:: \n");

       while (fgets(str, sizeof(str), file_ptr) != NULL) {
        int num1, num2;
        // Parse two numbers from the string
        if (sscanf(str, "%d %d", &num1, &num2) == 2) {
            arr1[idx] = num1;
            arr2[idx] = num2;
            idx++;
        } else {
            fprintf(stderr, "Error: Invalid line format: %s", str);
        }
    }
    fclose(file_ptr);

    qsort(arr1, idx, sizeof(int), comp);
    qsort(arr2, idx, sizeof(int), comp);

    for(int i = 0; i < 1000; i++) {
        arr3[i] = abs(arr1[i]-arr2[i]);
    }
    

    for(int i = 0; i < 1000; i++) {
        int counter = 0;
        for(int j = 0; j < 1000; j++) {
            if(arr1[i] == arr2[j]) {
                counter++;
            }
        }
        arr4[i] = arr1[i]*counter;
    }

    free(arr1);
    free(arr2);


    return arr4; //arr3 for part1
}

void main()
{

    int *arr = getArrayFromInput();
    int sum = 0;
    int k = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < 1000; i++) {
        sum += arr[i];
    }
    //printf("sum of array is %d", sum); //part 1
    printf("sum of similarity score is %d", sum); //part 2

}
