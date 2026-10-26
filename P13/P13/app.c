#pragma warning (disable:4996)
#include "app.h"
#include "car.h"
#include <stdio.h>

void clear(void) {
    printf("\033[2J\033[H");
}

void showMain(void) {
    clear();
    printf("\n");
    printf("========================================\n");
    printf("       PARKING MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("  [ Main ]\n");
    printf("----------------------------------------\n");
    printf("  1. EntryCar\n");
    printf("  2. ViewCar\n");
    printf("  3. ViewFee\n");
    printf("  4. ExitCar\n");
    printf("----------------------------------------\n");
    printf("  0. Exit\n");
    printf("========================================\n");
}

void showEntry(void) {
    clear();
    printf("\n");
    printf("========================================\n");
    printf("       PARKING MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("  [ Entry Car ]\n");
    printf("----------------------------------------\n");
    printf("  1. Car Id\n");
    printf("  2. Car EntryTime(HH:MM)\n");
    printf("  3. Car Discount(0/1)\n");
    printf("----------------------------------------\n");
    printf("========================================\n");
}

void showView(Car* cars, int carCount) {
    clear();
    printf("\n");
    printf("========================================\n");
    printf("       PARKING MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("  [ Entry Car ]\n");
    printf("----------------------------------------\n");
    printf("%-15s %-12s %-12s %-10s\n","Car Id", "Entry Time", "Exit Time", "Discount");
    printf("-----------------------------------------------\n");

    if (carCount == 0) {
        printf("                    No cars registered.\n");
    }

    for (int i = 0; i < carCount; i++) {
        printf("%-15s ", cars[i].name);

        printf("%02d:%02d          ",
            cars[i].entryTime / 60,
            cars[i].entryTime % 60);

        if (cars[i].exitTime == -1) {
            printf("%-15s ", "Parking");
        }
        else {
            printf("%02d:%02d          ",
                cars[i].exitTime / 60,
                cars[i].exitTime % 60);
        }

        printf("%-10s\n",
            cars[i].isDiscount ? "Yes" : "No");
    }

    printf("===============================================================\n");
}

void showFee(Car* cars, int carCount) {
    char name[20];
    int hour, minute;
    int exitTime, duration;
    int fee, totalFee = 0;

    printf("Input (ID,Exit) > ");
    scanf("%19[^,],%d:%d", name, &hour, &minute);
    exitTime = hour * 60 + minute;

    for (int i = 0; i < carCount; i++) {
        if (strcmp(cars[i].name, name) == 0) {
            duration = exitTime - cars[i].entryTime;

            if (duration < 0 || hour > 23 || minute > 59) {
                printf("Invalid time.\n");
                return;
            }

            fee = 1000;

            if (duration > 30) {
                int extra = duration - 30;
                int units = (extra + 9) / 10;
                fee += units * 500;
            }

            if (cars[i].isDiscount == 1) {
                fee /= 2;
            }

            cars[i].exitTime = exitTime;

            printf("%s: %d won\n", name, fee);
            return;
        }
    }

    printf("Car not found.\n");
}