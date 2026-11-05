#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    if (size == 0) {
        printf("The array is currently empty.\n");
        return;
    }
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 100;
    int arr[100];
    int current_size = 0;
    int choice, value, index;

    printf("--- 1. Create Your Array ---\n");
    printf("How many elements would you like to start with? ");
    if (scanf("%d", &current_size) != 1 || current_size < 0 || current_size > capacity) {
        printf("Invalid size entered.\n");
        return 1;
    }

    printf("Enter %d integers separated by spaces or newlines:\n", current_size);
    for (int i = 0; i < current_size; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, current_size);

    while (1) {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert a value\n");
        printf("2. Delete a value\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (current_size >= capacity) {
                    printf("Error: Array is full!\n");
                    break;
                }
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the index where you want to insert it (0 to %d): ", current_size);
                scanf("%d", &index);

                if (index < 0 || index > current_size) 
				{
                    printf("Invalid index! Position out of bounds.\n");
                    break;
                }
                
                for (int i = current_size; i > index; i--) 
				{
                    arr[i] = arr[i - 1];
                }
                arr[index] = value;
                current_size++;

                printf("Successfully inserted %d at index %d.\n", value, index);
                printArray(arr, current_size);
                break;

            case 2:
                if (current_size <= 0) {
                    printf("Error: Array is already empty!\n");
                    break;
                }
                printf("Enter the index of the element you want to delete (0 to %d): ", current_size - 1);
                scanf("%d", &index);

                if (index < 0 || index >= current_size) {
                    printf("Invalid index! Index does not exist.\n");
                    break;
                }

                
                for (int i = index; i < current_size - 1; i++) 
				{
                    arr[i] = arr[i + 1];
                }
                current_size--;

                printf("Successfully deleted element at index %d.\n", index);
                printArray(arr, current_size);
                break;

            case 3:
                printArray(arr, current_size);
                break;

            case 4:
                printf("Exiting program. Good luck with your assignment!\n");
                return 0;

            default:
                printf("Invalid choice. Please choose between 1 and 4.\n");
        }
    }

    return 0;
}