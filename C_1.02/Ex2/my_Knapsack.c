#include <stdio.h>
#define SIZE 5 // Defines the number of items that can be considered for the knapsack.
#define CAPACITY 20 // Defines the maximum weight that the knapsack can hold.

// This function returns the larger of two integers. It's used to decide whether to include an item in the knapsack or not.
int max(int num1, int num2) {
    // If num1 is greater than num2, then num1 is returned; otherwise, num2 is returned.
    if (num1 > num2) return num1;
    else return num2;
}

// This function solves the 0/1 Knapsack problem using dynamic programming.
int knapSack(int weights[], int values[], int isSelected[]) {
    // maxValuesTable is a 2D array that stores the maximum value that can be obtained
    // with a given number of items up to 'i' and with a given knapsack capacity 'j'.
    int maxValuesTable[SIZE + 1][CAPACITY + 1] = {0};
    // Iterates over each item.
    int currentItem = 1;
    while(currentItem <= SIZE) {
        // Iterates over each possible capacity from 1 to CAPACITY.
        for(int currentCapacity = 1; currentCapacity <= CAPACITY; currentCapacity++){
            // If the current item's weight is more than the knapsack's current capacity,
            // it cannot be included, so the value remains the same as when the item was not considered.
            if(weights[currentItem-1] > currentCapacity){
                maxValuesTable[currentItem][currentCapacity] = maxValuesTable[currentItem-1][currentCapacity];
            } else {
                // Otherwise, it calculates the maximum value by considering two scenarios:
                // 1. Excluding the current item.
                // 2. Including the current item and adding its value to the maximum value achievable with the remaining capacity.
                int maxValExcludingCurrent = maxValuesTable[currentItem-1][currentCapacity];
                int maxValIncludingCurrent = values[currentItem-1] + maxValuesTable[currentItem-1][currentCapacity-weights[currentItem-1]];
                maxValuesTable[currentItem][currentCapacity] = max(maxValExcludingCurrent, maxValIncludingCurrent);
            }
        }
        currentItem++;
    }
    // Backtracking through the maxValuesTable to find which items to include in the knapsack.
    currentItem = SIZE;
    int availableCapacity = CAPACITY;
    while(currentItem > 0 && availableCapacity > 0) {
        // If the value at currentItem and availableCapacity is different from the value at the previous item,
        // it means including the currentItem in the knapsack contributes to the optimal solution.
        if(maxValuesTable[currentItem][availableCapacity] != maxValuesTable[currentItem-1][availableCapacity]){
            isSelected[currentItem-1] = 1; // Mark this item as included.
            availableCapacity -= weights[currentItem-1]; // Decrease the available capacity by the weight of the included item.
        } else {
            isSelected[currentItem-1] = 0; // Mark this item as not included.
        }
        currentItem--;
    }
    // Returns the maximum value that can be achieved with the given items and knapsack capacity.
    return maxValuesTable[SIZE][CAPACITY];
}


// The main function to execute the solution.
int main(){
    // Arrays to store the symbols, values, and weights of the items. These are inputs for the problem.
    char itemSymbols[SIZE];
    int itemValues[SIZE];
    int itemWeights[SIZE];
    
    // Input loop to gather the symbols, values, and weights for each item from the user.
    int i = 0;
    while(i < SIZE) {
        scanf(" %c", &itemSymbols[i]);
        scanf("%d", &itemValues[i]);
        scanf("%d", &itemWeights[i]);
        i++;
    }
    // Array to mark which items are selected in the optimal solution.
    int result[SIZE] = {0};
    // Solving the knapsack problem to find the maximum profit and which items to include.
    int maximumProfit = knapSack(itemWeights, itemValues, result);
    // Printing the maximum profit.
    printf("Maximum profit: %d\n", maximumProfit);

    // Loop to print the symbols of the selected items.
    printf("Selected items:");
    i = 0;
    while(i < SIZE) {
        if(result[i] == 1){
            printf(" %c", itemSymbols[i]);
        }
        i++;
    }
    return 0;
}
