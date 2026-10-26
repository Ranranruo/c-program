#include <stdlib.h>
#include "car.h"

void entryCar(Car** cars, int* carCount, Car car) {
    Car* temp = realloc(*cars, (*carCount + 1) * sizeof(Car));

    if (temp == NULL) {
        return;
    }

    *cars = temp;
    (*cars)[*carCount] = car;
    (*carCount)++;
}