#include <stdio.h>

#define MAX_CITIES 30

void inputDistance(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES]);
void viewDistance(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES]);

void manageDistances(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES]) {
    int key;

    do {
        printf("\nDistance Management Menu\n");
        printf("1.Add a new distance\n");
        printf("2.View distances\n");
        printf("(Enter -1 to back to Main menu)\n\n");
        printf("Enter your choice: ");
        scanf("%d", &key);

        switch(key) {
        case 1:
            inputDistance(cities, cityCount, distance);
            break;
        case 2:
            viewDistance(cities, cityCount, distance);
            break;
        case -1:
            break;
        default:
            printf("Invalid Choice!");
        }

    } while(key != -1);
}

void inputDistance(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES]) {
    char choice;
    int value, cityOne, cityTwo, i;

    do {
        printf("Index\tCity\n");
        for (i = 0; i < cityCount; i++) {
            printf("%2d \t%s\n", i + 1, cities[i]);
        }

        printf("Enter city 1 index : ");
        scanf("%d",&cityOne);
        printf("Enter city 2 index : ");
        scanf("%d",&cityTwo);
        printf("Distance(km) : ");
        scanf("%d",&value);

        cityOne--;
        cityTwo--;
        if(cityOne < 0 || cityOne >= cityCount || cityTwo < 0 || cityTwo >= cityCount) {
            printf("Invalid city index!\n");
        } else {
            if(cityOne == cityTwo) {
                distance[cityOne][cityTwo] = 0;
            } else {
                distance[cityOne][cityTwo] = value;
                distance[cityTwo][cityOne] = value;
            }
        }

        printf("Do you want to add new distance? (y/n) : ");
        scanf(" %c",&choice);

    } while(choice != 'n');

}

void viewDistance(char cities[MAX_CITIES][20], int cityCount, int distance[MAX_CITIES][MAX_CITIES]) {
    int i, j;
    if (cityCount == 0) {
        printf("No cities. Add cities first!\n");
    } else {
        printf("\n\t");
        for (i = 0; i < cityCount; i++) {
            printf("%-10s", cities[i]);
        }
        printf("\n");
        for (i = 0; i < cityCount; i++) {
            printf("%s\t", cities[i]);
            for (j = 0; j < cityCount; j++) {
                printf("%3d\t", distance[i][j]);
            }
            printf("\n");
        }
    }
}
