#include <stdio.h>
#include <malloc.h>
#include <mem.h>

int main() {
    runTask1();
}



typedef struct{
    int horsepower;
    int horsepowerTuned;
    int torque;
    int torgueTuned;
    char * brand;
    char * model;
} Car ;

void showCarInformation(Car * car){
    printf("Brand: %s ; Model: %s ; Horse power: %d ; Torque: %d RPM ; Horse power tuned: %d ; Torque tuned: %d RPM",
           car->brand, car->model, car->horsepower, car->torque, car->horsepowerTuned, car->torgueTuned);

}

void initCarVariables(Car* car, int horsepower, int horsepowerTuned, int torque, int torqueTuned, char * brand, char * model){
    car->torque = torque;
    car->torgueTuned = torqueTuned;
    car->horsepower = horsepower;
    car->horsepowerTuned = horsepowerTuned;
    car->brand = brand;
    car->model = model;
}

int numberOfCars = 10;

Car** initDatabase(void){
    Car** cars = malloc(sizeof(Car*)*numberOfCars);
    for (int i = 0; i < numberOfCars; ++i) {
        cars[i] = malloc(sizeof(Car));
    }
    initCarVariables(cars[0], 5, 6, 10, 12, "WV", "Golf");
    initCarVariables(cars[1], 10, 11, 11, 13, "WV", "Golf 2");
    initCarVariables(cars[2], 11, 12, 12, 14, "WV", "Golf 3");
    initCarVariables(cars[3], 12, 13, 12, 14, "WV", "Golf 4");
    initCarVariables(cars[4], 13, 12, 50, 60, "WV", "Golf 5");
    initCarVariables(cars[5], 20, 22, 12, 14, "WV", "Golf 6");
    initCarVariables(cars[6], 14, 18, 12, 14, "WV", "Golf 7");
    initCarVariables(cars[7], 30, 36, 20, 22, "WV", "Golf 8");
    initCarVariables(cars[8], 10, 20, 22, 23, "WV", "Golf 9");
    initCarVariables(cars[9], 20, 24, 12, 14, "WV", "Golf 10");
    return cars;
}

void freeDatabase(Car** cars){
    for (int i = 0; i < numberOfCars; ++i) {
        free(cars[i]);
    }
    free(cars);
    cars = NULL;
}

Car* getMostHP(Car** cars){
    Car * tmpCar = NULL;
    tmpCar = cars[0];
    for (int i = 1; i < numberOfCars; ++i) {
        if ( cars[i]->horsepowerTuned > tmpCar->horsepowerTuned ) {
            tmpCar = cars[i];
        }
    }
    return tmpCar;
}

Car* getMostTorque(Car** cars){
    Car * tmpCar = NULL;
    tmpCar = cars[0];
    for (int i = 1; i < numberOfCars; ++i) {
        if ( cars[i]->torgueTuned > tmpCar->torgueTuned ) {
            tmpCar = cars[i];
        }
    }
    return tmpCar;
}

Car* getCarByModel(Car** cars, char * model){
    Car * tmpCar = NULL;
    for (int i = 0; i < numberOfCars; ++i) {
        if ( strcmp(cars[i]->model, model) == 0 ){
            tmpCar = cars[i];
        }
    }
    return tmpCar;
}

void runTask1(){
    Car** carArr = NULL;
    carArr = initDatabase();

    int loop = 1;
    while (loop == 1){
        int userInput = 0;
        printf("\n\nWhat do you want to do?\n1: Get the car with most horsepower when tuned\n2: Get the car with most torque when tuned\n3: Get a car info by model\n4: Exit\nEnter your choice: \n");
        scanf("%d", &userInput);
        switch (userInput){
            case 1:{
                Car * car = getMostHP(carArr);
                showCarInformation(car);
                break;
            } case 2:{
                Car * car = getMostTorque(carArr);
                showCarInformation(car);
                break;
            } case 3: {
                printf("\nEnter model: \n");
                char model[256];
                scanf("%s", model);
                Car * car = getCarByModel(carArr, &model);
                if (car != NULL){
                    showCarInformation(car);
                } else {
                    printf("\nCar not found");
                }
                break;
            } case 4: {
                loop = 0;
                break;
            } default: {
                printf("\nWrong input...\n");
            }

        }
    }


    freeDatabase(carArr);
}
