#include <stdio.h>

#define MAX_CITIES 30

void addCity(char cities[MAX_CITIES][20], int *cityCount);

void manageCities(char cities[MAX_CITIES][20], int *cityCount) {
    int key;

    do {
        printf("\nCity Management Menu\n");
        printf("1.Add a new City\n");
        printf("2.Rename a City\n");
        printf("3.Remove a City\n");
        printf("(Enter -1 to back to Main menu)\n\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        switch(key) {
        case 1:
            addCity(cities, cityCount);
            break;
        case 2:
            break;
        case 3:
            break;
        case -1:
            break;
        default:
            printf("Invalid Choice!");
        }

    } while(key != -1);
}

void addCity(char cities[MAX_CITIES][20], int *cityCount) {
    if ((*cityCount) >= MAX_CITIES) {
        printf("\nCity limit reached!\n");
        return;
    }
    printf("Enter city name: ");
    scanf("%s", cities[*cityCount]);
    (*cityCount)++;
}


