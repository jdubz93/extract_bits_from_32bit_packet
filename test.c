#include <stdio.h>
#include <stdint.h>

typedef struct {
    unsigned int carNumber;
    uint32_t carWeight;
    uint8_t carSpeed;
} CarModel_t;

// struct CarModel {
//     unsigned int carNumber;
//     uint32_t carWeight;
//     uint8_t carSpeed;
// };


int main(void)
{

    // CarModel_t data = { 12, 2035, 120};

    // struct CarModel data;
    // data.carNumber = 12;
    // data.carWeight = 2035;
    // data.carSpeed = 120;

    CarModel_t data;
    data.carNumber = 12;
    data.carWeight = 2035;
    data.carSpeed = 120;

    printf("Car speed: %d\n", data.carSpeed);
    
    CarModel_t *pCar;

    pCar = &data;

    pCar->carSpeed = 135;

    printf("Car speed: %d\n", pCar->carSpeed);


    return 0;
}