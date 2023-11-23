#include <stdio.h>
#include <stdlib.h>


struct Item {
    int value;
    int weight;
};


int compareItems(const void* a, const void* b) {
    double ratioA = ((double)((struct Item*)a)->value) / ((struct Item*)a)->weight;
    double ratioB = ((double)((struct Item*)b)->value) / ((struct Item*)b)->weight;
    return (ratioB - ratioA) > 0 ? 1 : -1;
}


void knapsackGreedy(struct Item items[], int n, int capacity) {
   
    qsort(items, n, sizeof(struct Item), compareItems);

    int currentWeight = 0;  
    double totalValue = 0; 

    
    for (int i = 0; i < n; i++) {
        
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Selected: Value: %d, Weight: %d\n", items[i].value, items[i].weight);
        }
    }

    printf("Total Value in Knapsack: %.2lf\n", totalValue);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item* items = (struct Item*)malloc(n * sizeof(struct Item));

   
    printf("Enter the values and weights of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    knapsackGreedy(items, n, capacity);

    free(items);

    return 0;
}
