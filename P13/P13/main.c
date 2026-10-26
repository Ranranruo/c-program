#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"
#include "car.h"

#define DISCOUNT_RATE 0.5

int main() {
    int carCount = 0;
    Car* cars = calloc(1, sizeof(Car));
    char menu[20] = "";

    while (1) {
        if (menu[0] == '\0') {
            showMain();
            printf("  Enter > ");
            scanf("%19s", menu);
        }

        if (strcmp(menu, "EntryCar") == 0) {
            char name[20];
            char entryTime[6];
            int isDiscount;

            showEntry();
            printf("  Car Id > ");
            scanf("%19s", name);

            showEntry();
            printf("  Car EntryTime (HH:MM) > ");
            scanf("%s", &entryTime);

            int hour, minute;
            sscanf(entryTime, "%d:%d", &hour, &minute);


            showEntry();
            printf("  Car isDiscount > ");
            scanf("%d", &isDiscount);

            Car car = { name, hour * 60 + minute, NULL, isDiscount };
            entryCar(&cars, &carCount, car);
        }
        else if (strcmp(menu, "ViewCar") == 0) {
            showView();
            printf("  Enter q > ");
            scanf("%d", &menu);
        }
        strcpy(menu, "");
    }

    free(cars);
    return 0;
}