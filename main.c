#include <stdio.h>
#include <stdint.h>

// maintained ? static __USER_LABEL_PREFIX__ ;
struct DataSet {
    char data1;
    int data2;
    char data3;
    short data4;
};

typedef struct
{
    unsigned int carNumber;
    uint32_t     carPrice;
    uint16_t     carMaxSpeed;
    float        carWeight;
} CarModel_t;

int main(void)
{
    CarModel_t carBMW, carFord;
    struct DataSet data;
    data.data1 = 0x11;
    data.data2 = 0xFFFFEEEE;
    data.data3 = 0x22;
    data.data4 = 0xABCD;

    uint8_t* ptr;

    ptr = (uint8_t*)&data;

    uint32_t totalSize = sizeof(struct DataSet);

    printf("Memory address \n");
    printf("========================\n");

    for (int i = 0; i < totalSize; i++) 
    {
        printf("%p       %X\n", ptr, *ptr);
        ptr++;
    }  

    // printf("Memory address \n");
    // printf("========================\n");
    // printf("data1 = %c\n", data.data1);
    // printf("data2 = %d\n", data.data2);
    // printf("data3 = %c\n", data.data3);
    // printf("data4 = %s\n", data.data4);

    // printf("ptr_data = %d\n", ptr->data1);
    return 0;
}