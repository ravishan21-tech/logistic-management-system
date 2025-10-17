#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50

void saveData(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES], int fromList[MAX_DELIVERIES],
              int toList[MAX_DELIVERIES], double totalCostList[MAX_DELIVERIES], double timeList[MAX_DELIVERIES], int deliveryCount) {
    FILE *routeFile = fopen("routes.txt", "w");
    FILE *deliveriesFile = fopen("deliveries.txt", "w");

    int i, j;
    if (routeFile != NULL) {
        fprintf(routeFile, "%d\n", cityCount);
        for (i = 0; i < cityCount; i++) {
            fprintf(routeFile, "%s\n", cities[i]);
        }
        for (i = 0; i < cityCount; i++) {
            for (j = 0; j < cityCount; j++) {
                fprintf(routeFile, "%d ", distance[i][j]);
            }
            fprintf(routeFile, "\n");
        }
        fclose(routeFile);
    }

    if (deliveriesFile != NULL) {
        fprintf(deliveriesFile, "%d\n", deliveryCount);
        for (i = 0; i < deliveryCount; i++) {
            fprintf(deliveriesFile, "%d %d %.2f %.2f\n",
                    fromList[i], toList[i],
                    totalCostList[i], timeList[i]);
        }
        fclose(deliveriesFile);
    }
}

void loadData(char cities[MAX_CITIES][20], int *cityCount, int distance[MAX_CITIES][MAX_CITIES], int fromList[MAX_DELIVERIES],
              int toList[MAX_DELIVERIES], double totalCostList[MAX_DELIVERIES], double timeList[MAX_DELIVERIES], int *deliveryCount) {
    FILE *routeFile = fopen("routes.txt", "r");
    FILE *deliveriesFile = fopen("deliveries.txt", "r");

    int i, j;
    if (routeFile != NULL) {
        fscanf(routeFile, "%d", cityCount);
        for (i = 0; i < *cityCount; i++) {
            fscanf(routeFile, "%s", cities[i]);
        }
        for (i = 0; i < *cityCount; i++) {
            for (j = 0; j < *cityCount; j++) {
                fscanf(routeFile, "%d", &distance[i][j]);
            }
        }
        fclose(routeFile);
        printf("Routes loaded...\n");
    } else {
        printf("No previous routes found!\n");
    }

    if (deliveriesFile != NULL) {
        fscanf(deliveriesFile, "%d", deliveryCount);
        for (i = 0; i < *deliveryCount; i++) {
            fscanf(deliveriesFile, "%d %d %lf %lf",
                   &fromList[i], &toList[i],
                   &totalCostList[i], &timeList[i]);
        }
        fclose(deliveriesFile);
        printf("Deliveries loaded successfully.\n");
    } else {
        printf("No previous delivery data found!\n");
    }

}

