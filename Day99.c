// Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    double time;
};

// Compare function for descending position
int compare(const void* a, const void* b) {
    struct Car* x = (struct Car*)a;
    struct Car* y = (struct Car*)b;

    return y->position - x->position;
}

int main() {
    int target, n;

    printf("Enter target distance:\n");
    scanf("%d", &target);

    printf("Enter number of cars:\n");
    scanf("%d", &n);

    int position[n], speed[n];

    printf("Enter positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    struct Car cars[n];

    // Calculate time for each car
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Sort by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double maxTime = 0;

    // Count fleets
    for (int i = 0; i < n; i++) {

        // New fleet formed
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    printf("Number of car fleets: %d\n", fleets);

    return 0;
}