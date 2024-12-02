/* #include <stdio.h>
#include <stdlib.h>

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
        //printf("%s", str);

    }

    fclose(file_ptr);

    return arrOfStrings;
}



void main()
{
    int *arr = getArrayFromInput();
    //printf("Array is %d", arr[0]);
} */


#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100  // Adjust as needed for the maximum number of lines in your file

int main() {
    FILE *file;
    int left[MAX_LINES], right[MAX_LINES];
    int leftIndex = 0, rightIndex = 0;

    // Open the file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file line by line
    while (!feof(file)) {
        int num1, num2;
        if (fscanf(file, "%d %d", &num1, &num2) == 2) {
            left[leftIndex++] = num1;
            right[rightIndex++] = num2;
        }
    }

    fclose(file);

    // Print the arrays to verify
    printf("Left Array:\n");
    for (int i = 0; i < leftIndex; i++) {
        printf("%d ", left[i]);
    }
    printf("\n");

    printf("Right Array:\n");
    for (int i = 0; i < rightIndex; i++) {
        printf("%d ", right[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
