#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 30
#define VEHICLE_TYPES 3
#define MAX_DELIVERIES 50

void manageCities(char cities[MAX_CITIES][20], int *cityCount);
void manageDistances(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES]);
void showVehicles(char vehicleNames[VEHICLE_TYPES][10], int capacity[VEHICLE_TYPES], int ratePerKm[VEHICLE_TYPES], int speed[VEHICLE_TYPES], int efficiency[VEHICLE_TYPES]);
void manageDeliveries(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES], char vehicleNames[VEHICLE_TYPES][10],
                      int capacity[VEHICLE_TYPES], int ratePerKm[VEHICLE_TYPES], int speed[VEHICLE_TYPES], int efficiency[VEHICLE_TYPES],
                      int fromList[MAX_DELIVERIES], int toList[MAX_DELIVERIES], double weightList[MAX_DELIVERIES], int vehicleList[MAX_DELIVERIES],
                      double totalCostList[MAX_DELIVERIES], double timeList[MAX_DELIVERIES], int *deliveryCount);
void showReport(char cities[MAX_CITIES][20], int distance[MAX_CITIES][MAX_CITIES], int fromList[MAX_DELIVERIES],
                      int toList[MAX_DELIVERIES], double totalCostList[MAX_DELIVERIES], double timeList[MAX_DELIVERIES],
                      int deliveryCount);

int main() {
    int choice, cityCount=0, distance[MAX_CITIES][MAX_CITIES], i, j, fromList[MAX_DELIVERIES], toList[MAX_DELIVERIES], vehicleList[MAX_DELIVERIES], deliveryCount = 0;
    char cities[MAX_CITIES][20];
    int capacity[VEHICLE_TYPES] = {1000, 5000, 10000};
    int ratePerKm[VEHICLE_TYPES] = {30, 40, 80};
    int speed[VEHICLE_TYPES] = {60, 50, 45};
    int efficiency[VEHICLE_TYPES] = {12, 6, 4};
    char vehicleNames[VEHICLE_TYPES][10] = {"Van", "Truck", "Lorry"};
    double weightList[MAX_DELIVERIES], totalCostList[MAX_DELIVERIES], timeList[MAX_DELIVERIES];

    for (i = 0; i < MAX_CITIES; i++) {
        for (j = 0; j < MAX_CITIES; j++) {
            distance[i][j] = 0;
        }
    }

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
            manageDistances(cities, cityCount, distance);
            break;
        case 3:
            showVehicles(vehicleNames, capacity, ratePerKm, speed, efficiency);
            break;
        case 4:
            manageDeliveries(cities, cityCount, distance, vehicleNames, capacity, ratePerKm,
                            speed, efficiency, fromList, toList, weightList, vehicleList,
                            totalCostList, timeList, &deliveryCount);
            break;
        case 5:
            showReport(cities, distance, fromList, toList, totalCostList, timeList, deliveryCount);
            break;
        case -1:
            printf("Program Exited...\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != -1);
}




