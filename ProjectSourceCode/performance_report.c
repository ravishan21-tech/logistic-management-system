#include <stdio.h>

#define MAX_DELIVERIES 50
#define MAX_CITIES 30

void showReport(char cities[MAX_CITIES][20], int distance[MAX_CITIES][MAX_CITIES], int fromList[MAX_DELIVERIES],
                      int toList[MAX_DELIVERIES], double totalCostList[MAX_DELIVERIES], double timeList[MAX_DELIVERIES],
                      int deliveryCount) {
    if (deliveryCount == 0) {
        printf("No deliveries yet!\n");
        return;
    }

    double totalRevenue = 0.0, totalTime = 0.0;
    int totalDistance = 0, i;
    int longest = distance[fromList[0] - 1][toList[0] - 1], shortest = distance[fromList[0] - 1][toList[0] - 1];

    for (i = 0; i < deliveryCount; i++) {
        totalRevenue += totalCostList[i];
        totalTime += timeList[i];

        int d = distance[fromList[i] - 1][toList[i] - 1];
        totalDistance += d;
        if (d > longest) {
            longest = d;
        }
        if (d < shortest) {
            shortest = d;
        }
    }

    printf("\n========== PERFORMANCE REPORT ==========\n");
    printf("Total Deliveries: %d\n", deliveryCount);
    printf("Total Distance Covered: %d km\n", totalDistance);
    printf("Average Delivery Time: %.2f hours\n", totalTime / deliveryCount);
    printf("Total Revenue: %.2f LKR\n", totalRevenue);
    printf("Longest Route: %d km\n", longest);
    printf("Shortest Route: %d km\n", shortest);
    printf("========================================\n");

}



