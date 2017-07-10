#include "MPU6050.h"

MPU6050::MPU6050 (void)
{
    AcX = 0;
    AcY = 0;
    AcZ = 0;
    GyX = 0;
    GyY = 0;
    GyZ = 0;
    Temp = 0;
}

 void MPU6050::begin (void)
 {
    Wire.begin();
    Wire.beginTransmission(MPU_Adress);
    //Inicializa o MPU-6050
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(false);

    //Config Escalas para Gyro e Accel, a maior nas duas
    Wire.beginTransmission(MPU_Adress);
    Wire.write(0x1B);
    Wire.write(24);
    Wire.write(24);
    Wire.endTransmission(true);
 }

void MPU6050::doReadings(void)
{
    Wire.beginTransmission(MPU_Adress);
    Wire.write(0x3B);  // inicia leitura do registrador 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    //Solicita os dados do sensor
    Wire.requestFrom(MPU_Adress,14,true);//pedindo 14 bytes
    //Armazena o valor dos sensores nas variaveis correspondentes
    AcX = (Wire.read()<<8|Wire.read())/2048.0;  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    AcY = (Wire.read()<<8|Wire.read())/2048.0;  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    AcZ = (Wire.read()<<8|Wire.read())/2048.0;  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
    Temp = (Wire.read()<<8|Wire.read())/340.0 + 36.53;  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
    GyX = (Wire.read()<<8|Wire.read())/16.4;  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
    GyY = (Wire.read()<<8|Wire.read())/16.4;  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
    GyZ = (Wire.read()<<8|Wire.read())/16.4;  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
}


float MPU6050::getAcX (void)
{
    return AcX;
}
float MPU6050::getAcY (void)
{
    return AcY;
}
float MPU6050::getAcZ (void)
{
    return AcZ;
}
float MPU6050::getTemperaturaCelsius(void)
{
    return Temp;
}
float MPU6050::getGyX (void)
{
    return GyX;
}
float MPU6050::getGyY (void)
{
    return GyY;
}
float MPU6050::getGyZ (void)
{
    return GyZ;
}

