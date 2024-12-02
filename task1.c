#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define YEARS 10
#define MIN_REVENUE 15000
#define MAX_REVENUE 85000

// Function prototypes
void fillArray(int revenue[], int size);
void displayArray(const int revenue[], int size);
int calculateTotalRevenue(const int revenue[], int size);
void readPeriod(int *lower, int *upper);
void displayPercentageForPeriod(const int revenue[], int lower, int upper, int totalRevenue);
int findHighestRevenueYear(const int revenue[], int lower, int upper);

int main() {
    int revenue[YEARS];
    int lowerBound, upperBound;
    int totalRevenue;

    // Fill the array with random values
    fillArray(revenue, YEARS);

    // Display the elements of the array
    printf("Annual net revenue for the last 10 years:\n");
    displayArray(revenue, YEARS);

    // Calculate and display the total revenue
    totalRevenue = calculateTotalRevenue(revenue, YEARS);
    printf("\nTotal net revenue over 10 years: $%d\n", totalRevenue);

    // Read the period (lower and upper bounds)
    readPeriod(&lowerBound, &upperBound);

    // Display percentage for the given period
    printf("\nRevenue as percentage of total for the period %d to %d:\n", lowerBound, upperBound);
    displayPercentageForPeriod(revenue, lowerBound, upperBound, totalRevenue);

    // Display the year with the highest revenue in the given period
    int highestYear = findHighestRevenueYear(revenue, lowerBound, upperBound);
    printf("\nYear with the highest revenue during the period %d to %d: Year %d\n", lowerBound, upperBound, highestYear);

    return 0;
}

// a) Fill the array with random integer values between 15,000 and 85,000.
void fillArray(int revenue[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        revenue[i] = MIN_REVENUE + rand() % (MAX_REVENUE - MIN_REVENUE + 1);
    }
}

// b) Display the elements of the array.
void displayArray(const int revenue[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Year %d: $%d\n", i + 1, revenue[i]);
    }
}

// c) Calculate the total net revenue over the 10 years.
int calculateTotalRevenue(const int revenue[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += revenue[i];
    }
    return total;
}

// d) Read two integers between 1 and 10 (the lower and upper bounds of the period).
void readPeriod(int *lower, int *upper) {
    int validInput = 0;
    while (!validInput) {
        printf("\nEnter the lower and upper bounds of the period (1-10): ");
        scanf("%d %d", lower, upper) ;
        if ( *lower >= 1 && *upper >= 1 && *lower <= 10 && *upper <= 10 && *upper > *lower) {
            validInput = 1;
        } else {
            printf("Invalid input. Please enter two integers between 1 and 10, with the second greater than the first.\n");
         
        }
    }

}

// e) Calculate revenue/total revenue for each year in the given period and display it as a percentage.
void displayPercentageForPeriod(const int revenue[], int lower, int upper, int totalRevenue) {
    for (int i = lower - 1; i < upper; i++) {
        double percentage = ((double) revenue[i] / totalRevenue) * 100.0;
        printf("Year %d: %.2f%%\n", i + 1, percentage);
    }
}

// f) Display which year had the highest revenue during the given period.
int findHighestRevenueYear(const int revenue[], int lower, int upper) {
    int highestRevenue = revenue[lower - 1];
    int highestYear = lower;

    for (int i = lower; i < upper; i++) {
        if (revenue[i] > highestRevenue) {
            highestRevenue = revenue[i];
            highestYear = i + 1;
        }
    }

    return highestYear;
}
