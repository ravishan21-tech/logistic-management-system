#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 30

void manageCities(char cities[MAX_CITIES][20], int *cityCount);

int main() {
    int choice, cityCount=0;
    char cities[MAX_CITIES][20];

    do {
        printf("\nLOGISTICS MANAGEMENT SYSTEM\n");
        printf("============================\n");
        printf("1.City Management\n");
        printf("2.Distance Management\n");
        printf("3.Vehicle Management\n");
        printf("4.Delivery Request Handling\n");
        printf("5.Reports\n");
        printf("(Enter -1 for Exit)\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            manageCities(cities, &cityCount);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case -1:
            printf("Program Exited...\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != -1);
}


