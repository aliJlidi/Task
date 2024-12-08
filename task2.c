#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 10

// Function prototypes
void fillArray(int heights[]);
void sortArray(int heights[]);
void displayReverse(int heights[]);
int validateString(char *input);
double calculateAverage(char *type, int heights[]);
int findPosition(int heights[], int height);

int main() {
    int heights[SIZE];
    char input[10];
    char type[10];

    fillArray(heights);
    sortArray(heights);

    printf("Sorted heights: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", heights[i]);
    }
    printf("\n");

    displayReverse(heights);

    printf("Enter 'tall' or 'short': ");
    scanf("%9s", input); 
    if (!validateString(input)) {
        printf("Invalid input. Please enter 'tall' or 'short'.\n");
        return 1;
    }
    strcpy(type, input);

    double average = calculateAverage(type, heights);
    printf("Average height of %s students: %.2f cm\n", type, average);

    int position = findPosition(heights, 165);
    if (position != -1) {
        printf("Position of height 165 cm: %d\n", position);
    } else {
        printf("Height 165 cm not found in the array.\n");
    }

    return 0;
}

// Function definitions
void fillArray(int heights[]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        heights[i] = 140 + rand() % 41; // Random between 140 and 180
    }
}

void sortArray(int heights[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i+1; j < SIZE ; j++) {
            if (heights[i] > heights[j ]) {
                int temp = heights[i];
                heights[i] = heights[j];
                heights[j] = temp;
            }
        }
    }
}

void displayReverse(int heights[]) {
    printf("Heights in reverse order:\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", heights[i]);
    }
    printf("\n");
}

int validateString(char *input) {
    if (strcmp(input, "tall") == 0 || strcmp(input, "short") == 0) {
        return 1; 
    }
    return 0; 
}

double calculateAverage(char *type, int heights[]) {
    int sum = 0, count = 0;
    int threshold = 160;

    for (int i = 0; i < SIZE; i++) {
        if ((strcmp(type, "short") == 0 && heights[i] < threshold) ||
            (strcmp(type, "tall") == 0 && heights[i] >= threshold)) {
            sum += heights[i];
            count++;
        }
    }

    return count > 0 ? (double)sum / count : 0.0;
}

int findPosition(int heights[], int height) {
    for (int i = 0; i < SIZE; i++) {
        if (heights[i] == height) {
            return i;
        }
    }
    return -1; // Return -1 if height not found
}
