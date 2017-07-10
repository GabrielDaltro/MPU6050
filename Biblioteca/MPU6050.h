#ifndef MPU6050_H
#define MPU6050_H

#include<Wire.h>
#define MPU_Adress 0x68


class MPU6050 {

    public:

        MPU6050(void);

        void begin (void);
        void doReadings(void);

        float getAcX (void);
        float getAcY (void);
        float getAcZ (void);
        float getTemperaturaCelsius(void);
        float getGyX (void);
        float getGyY (void);
        float getGyZ (void);

    private:

        float AcX;
        float AcY;
        float AcZ;
        float GyX;
        float GyY;
        float GyZ;
        float Temp;
};

#endif
