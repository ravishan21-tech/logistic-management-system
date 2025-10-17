#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 30

void saveData(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES]) {
    FILE *routeFile = fopen("routes.txt", "w");

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
}

void loadData(char cities[MAX_CITIES][20], int *cityCount, int distance[MAX_CITIES][MAX_CITIES]) {
    FILE *routeFile = fopen("routes.txt", "r");

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
}

