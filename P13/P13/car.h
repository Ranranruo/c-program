#pragma once
typedef struct {
	char name[20];
	int entryTime;
	int exitTime;
	int isDiscount;
} Car;

void entryCar(Car** cars, int* carCount, Car car);