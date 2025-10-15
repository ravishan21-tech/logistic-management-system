#include <stdio.h>

#define VEHICLE_TYPES 3

void showVehicles(char vehicleNames[VEHICLE_TYPES][10], int capacity[VEHICLE_TYPES], int ratePerKm[VEHICLE_TYPES], int speed[VEHICLE_TYPES], int efficiency[VEHICLE_TYPES]);

void showVehicles(char vehicleNames[VEHICLE_TYPES][10], int capacity[VEHICLE_TYPES], int ratePerKm[VEHICLE_TYPES], int speed[VEHICLE_TYPES], int efficiency[VEHICLE_TYPES]) {
    printf("\nVEHICLE DETAILS\n");
    printf("Type\t\tCapacity(kg)\t\tRate/km\tSpeed(km/h)\tEfficiency(km/l)\n");
    printf("------------------------------------------------------------------\n");

    int i;
    for (i = 0; i < VEHICLE_TYPES; i++) {
        printf("%d. %-6s \t%6d\t\t%3d\t%3d\t\t\t%3d\n",
               i + 1,
               vehicleNames[i],
               capacity[i],
               ratePerKm[i],
               speed[i],
               efficiency[i]);
    }
    printf("\n");
}
