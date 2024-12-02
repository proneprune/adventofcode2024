#include <stdio.h>
#include <stdlib.h>
// Defining file pointer and opening the file.
/*     FILE *file_ptr;
    char str[50];

    // a+ Mode Means that the file is opened in the
    // append + reading mode
    file_ptr = fopen("test.txt", "r");

    if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }

      // Reading stinrg using fgets
    printf("Content of this file are:: \n");
    while (fgets(str, 50, file_ptr) != NULL) {
        printf("%s", str);
    }

    fclose(file_ptr);
    return 0; */

int *getArrayFromInput()
{
    int *arrOfStrings = (int *)malloc(1000 * sizeof(int));

    FILE *file_ptr;
    char str[50];

    file_ptr = fopen("input.txt", "r");

        if (NULL == file_ptr) {
        printf("File can't be opened \n");
    }

    // Reading stinrg using fgets
    printf("Content of this file are:: \n");
    while (fgets(str, 50, file_ptr) != NULL) {
        printf("%s", str);
    }

    fclose(file_ptr);

    return arrOfStrings;
}



void main()
{
    int *arr = getArrayFromInput();
    //printf("Array is %d", arr[0]);
}