#include <stdio.h>

#define MAX_CITIES 30
#define VEHICLE_TYPES 3

void manageDeliveries(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES], char vehicleNames[VEHICLE_TYPES][10],
                      int capacity[VEHICLE_TYPES]) {

    int from, to, vehicleType, i;
    double weight;

    if (cityCount < 2) {
        printf("Add at least 2 cities first!\n");
        return;
    }

    printf("\nDELIVERY REQUEST\n");
    printf("---------------------\n");
    printf("Index\tCity\n");

    for (i = 0; i < cityCount; i++) {
        printf("%2d \t%s\n", i + 1, cities[i]);
    }

    printf("Enter current city index: ");
    scanf("%d", &from);
    printf("Enter destination city index: ");
    scanf("%d", &to);

    if (from < 1 || from > cityCount || to < 1 || to > cityCount) {
        printf("Invalid city index!\n");
        return;
    }
    if (from == to) {
        printf("Source and destination cannot same!\n");
        return;
    }

    printf("Enter weight (kg): ");
    scanf("%lf", &weight);

    printf("\n");
    for (i = 0; i < VEHICLE_TYPES; i++) {
        printf("%d. %s (capacity %d kg)\n", i + 1, vehicleNames[i], capacity[i]);
    }
    printf("\nEnter vehicle type (1-3) : ");
    scanf("%d", &vehicleType);

    if (vehicleType < 1 || vehicleType > VEHICLE_TYPES) {
        printf("Invalid vehicle!\n");
        return;
    }
    if (weight > capacity[vehicleType - 1]) {
        printf("Weight exceeds vehicle capacity!\n");
        return;
    }
}



