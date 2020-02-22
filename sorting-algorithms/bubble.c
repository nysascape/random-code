#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define INPUTLIMIT 7

void swapnum(int *x, int *y) {
    /* Swap two numbers around, used for sorting algorithm */
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int toSort[], int arraySize) {
    int i, j;
    for(int i = 0; i < arraySize - 1; i++) {
        for(int j = 0; j < arraySize - i - 1; j++) {
            if(toSort[j] > toSort[j+1]) {
                swapnum(&toSort[j], &toSort[j+1]);
            }
        }
    }
}

int main() {
    bool loop = true;
    int arrtosort[5];
    char input[INPUTLIMIT];

    printf("Type anything to start adding elements to sort, or enter \"random\" to select 5 random elements (0 - 99):\n");
    fgets(input, INPUTLIMIT, stdin);

    if(strcmp(input, "random") == 0) {
        /* Intializes random number generator */
        srand(time(NULL));
        printf("Randomized array to sort: {");
        for(int i = 0; i < 5; i++) {
            if(i == 4) {
                arrtosort[i] = rand() % 100;
                printf("%i}\n", arrtosort[i]);
                break;
            }
            arrtosort[i] = rand() % 100;
            printf("%i, ", arrtosort[i]);
        }
    } else {
        int element = 0;
        int num;
        char term;

        do {
            printf("Enter value at index %i: ", element);
            if(scanf("%d%c", &num, &term) != 2 || term != '\n') {
                while(getchar() != '\n') {
                    printf("Please input an integer!!!\n");
                }
            } else if(num > 99) {
                printf("Please enter an integer lower than 100!!!\n");
            } else {
                arrtosort[element] = num;
                element++;
            }
        } while(element < 5);

        printf("Your array: {");
        for(int i = 0; i < 5; i++) {
            if(i == 4) {
                printf("%i}\n", arrtosort[i]);
                break;
            }
            printf("%i, ", arrtosort[i]);
        }
    }

    sort(arrtosort, (sizeof(arrtosort)/sizeof(arrtosort[0])));
    printf("Your new sorted array: {");
    for(int i = 0; i < 5; i++) {
        if(i == 4) {
            printf("%i}\n", arrtosort[i]);
            break;
        }
        printf("%i, ", arrtosort[i]);
    }
    return 0;
}