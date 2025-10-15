#include <stdio.h>

#define MAX_CITIES 30
#define VEHICLE_TYPES 3

void manageDeliveries(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES], char vehicleNames[VEHICLE_TYPES][10],
                      int capacity[VEHICLE_TYPES]) {

    int from, to, vehicleType, i;
    double weight;

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

    printf("Enter weight (kg): ");
    scanf("%lf", &weight);

    printf("\n");
    for (i = 0; i < VEHICLE_TYPES; i++) {
        printf("%d. %s (capacity %d kg)\n", i + 1, vehicleNames[i], capacity[i]);
    }
    printf("\nEnter vehicle type (1-3) : ");
    scanf("%d", &vehicleType);

}



