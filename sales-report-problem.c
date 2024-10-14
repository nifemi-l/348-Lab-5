#include <stdio.h>
// define the months macros
#define MONTHS 12

// define function that prints the monthly sales report
void printMonthlySales(float sales[]) {
    char* months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};
    
    // print headers
    printf("Monthly Sales Report for 2024\n");
    printf("Month      Sales\n");
    
    // loop through to print the month and sales, include formatting
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
}

// define function that prints sales summary (min, max, avg)
void printSalesSummary(float sales[]) {
    // default values
    float min = sales[0], max = sales[0], total = 0;
    int minMonth = 0, maxMonth = 0;
    
    for (int i = 0; i < MONTHS; i++) {
        total += sales[i];
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
    }
    
    // calculate the average
    float avg = total / MONTHS;

    char* months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};
    
    // print header and formatted content
    printf("\nSales Summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: $%.2f\n", avg);
}

// define function that prints six-month moving average
void printSixMonthAverage(float sales[]) {
    // print header
    printf("\nSix-Month Moving Average Report:\n");
    char* months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};

    // calculate the sum for 6 months
    for (int i = 0; i <= MONTHS - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];  
        }

        // print the moving average
        printf("%s - %s: $%.2f\n", months[i], months[i+5], sum / 6);
    }
}

// define function that sort sales and months by sales, done in descending order
void sortSales(float sales[], char* months[]) {
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = i + 1; j < MONTHS; j++) {
            if (sales[i] < sales[j]) {
                // swap sales
                float tempSales = sales[i];
                sales[i] = sales[j];
                sales[j] = tempSales;

                // swap months
                char* tempMonth = months[i];
                months[i] = months[j];
                months[j] = tempMonth;
            }
        }
    }
}

// define function that print the sales report sorted from highest to lowest
void printSalesSorted(float sales[], char* months[]) {
    printf("\nSales Report (Highest to Lowest):\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);  // print sorted sales and months
    }
}

int main() {
    // sample input from assmt doc
    float sales[MONTHS] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 
                           60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 
                           80950.34, 95225.22};
    
    char* months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};

    // print monthly sales report
    printMonthlySales(sales);
    
    // print sales summary
    printSalesSummary(sales);
    
    // print six-month moving average
    printSixMonthAverage(sales);

    // sort nd print sales from highest to lowest
    sortSales(sales, months);
    printSalesSorted(sales, months);

    return 0;
}