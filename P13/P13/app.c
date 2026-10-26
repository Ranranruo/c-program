#include "app.h"
#include <stdio.h>

void clear() {
    printf("\033[2J\033[H");
}

void showMain() {
    clear();
    printf("\n");
    printf("========================================\n");
    printf("       PARKING MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("  [ Main ]\n");
    printf("----------------------------------------\n");
    printf("  1. EntryCar\n");
    printf("  2. ViewCar\n");
    printf("  3. ExitCar\n");
    printf("----------------------------------------\n");
    printf("  0. Exit\n");
    printf("========================================\n");
}

void showEntry() {
    clear();
    printf("\n");
    printf("========================================\n");
    printf("       PARKING MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("  [ Entry Car ]\n");
    printf("----------------------------------------\n");
    printf("  1. Car Id\n");
    printf("  2. Car EntryTime(HH:MM)\n");
    printf("  3. Car DIscount(0/1)\n");
    printf("----------------------------------------\n");
    printf("========================================\n");
}

void showView() {
    clear();
    printf("\n");
    printf("========================================\n");
    printf("       PARKING MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("  [ View Car ]\n");
    printf("----------------------------------------\n");
    printf("  1. Car Id\n");
    printf("----------------------------------------\n");
    printf("========================================\n");
}