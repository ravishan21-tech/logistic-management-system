#include <stdio.h>

#define MAX_CITIES 30
#define VEHICLE_TYPES 3
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0

int calculateDelivery(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES], char vehicleNames[VEHICLE_TYPES][10],
                      int capacity[VEHICLE_TYPES], int ratePerKm[VEHICLE_TYPES], int speed[VEHICLE_TYPES], int efficiency[VEHICLE_TYPES],
                      int fromList[MAX_DELIVERIES], int toList[MAX_DELIVERIES], double weightList[MAX_DELIVERIES], int vehicleList[MAX_DELIVERIES],
                      double totalCostList[MAX_DELIVERIES], double timeList[MAX_DELIVERIES], int from, int to, double weight, int vehicleType, int deliveryCount);


void manageDeliveries(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES], char vehicleNames[VEHICLE_TYPES][10],
                      int capacity[VEHICLE_TYPES], int ratePerKm[VEHICLE_TYPES], int speed[VEHICLE_TYPES], int efficiency[VEHICLE_TYPES],
                      int fromList[MAX_DELIVERIES], int toList[MAX_DELIVERIES], double weightList[MAX_DELIVERIES], int vehicleList[MAX_DELIVERIES],
                      double totalCostList[MAX_DELIVERIES], double timeList[MAX_DELIVERIES], int *deliveryCount) {

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

    *deliveryCount = calculateDelivery(cities, cityCount, distance, vehicleNames, capacity,
                                      ratePerKm, speed, efficiency, fromList, toList, weightList, vehicleList,
                                      totalCostList, timeList, from, to, weight, vehicleType, *deliveryCount);

}

int calculateDelivery(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES], char vehicleNames[VEHICLE_TYPES][10],
                      int capacity[VEHICLE_TYPES], int ratePerKm[VEHICLE_TYPES], int speed[VEHICLE_TYPES], int efficiency[VEHICLE_TYPES],
                      int fromList[MAX_DELIVERIES], int toList[MAX_DELIVERIES], double weightList[MAX_DELIVERIES], int vehicleList[MAX_DELIVERIES],
                      double totalCostList[MAX_DELIVERIES], double timeList[MAX_DELIVERIES], int from, int to, double weight, int vehicleType, int deliveryCount) {

    int d = distance[from - 1][to - 1];
    if (d <= 0) {
        printf("Distance not found between selected cities.\n");
        return deliveryCount;
    }

    double r = ratePerKm[vehicleType - 1];
    double s = speed[vehicleType - 1];
    double e = efficiency[vehicleType - 1];

    double deliveryCost = d * r * (1 + (weight / 10000.0));
    double fuelUsed = d / e;
    double fuelCost = fuelUsed * FUEL_PRICE;
    double totalOperationalCost = deliveryCost + fuelCost;
    double profit = totalOperationalCost * 0.25;
    double customerCharge = totalOperationalCost + profit;
    double time = d / s;

    printf("\n======================================================\n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("------------------------------------------------------\n");
    printf("From: %s\n", cities[from - 1]);
    printf("To: %s\n", cities[to - 1]);
    printf("Distance: %d km\n", d);
    printf("Vehicle: %s\n", vehicleNames[vehicleType - 1]);
    printf("Weight: %.2f kg\n", weight);
    printf("------------------------------------------------------\n");
    printf("Base Cost: %d x %.0f x (1 + %.0f/10000) = %.2f LKR\n", d, r, weight, deliveryCost);
    printf("Fuel Used: %.2f L\n", fuelUsed);
    printf("Fuel Cost: %.2f LKR\n", fuelCost);
    printf("Operational Cost: %.2f LKR\n", totalOperationalCost);
    printf("Profit: %.2f LKR\n", profit);
    printf("Customer Charge: %.2f LKR\n", customerCharge);
    printf("Estimated Time: %.2f hours\n", time);
    printf("======================================================\n");

    if (deliveryCount < MAX_DELIVERIES) {
        fromList[deliveryCount] = from;
        toList[deliveryCount] = to;
        weightList[deliveryCount] = weight;
        vehicleList[deliveryCount] = vehicleType;
        totalCostList[deliveryCount] = customerCharge;
        timeList[deliveryCount] = time;
        deliveryCount++;
    } else {
        printf("Maximum delivery count reached!\n");
    }
    return deliveryCount;
}



