#ifndef MPU_9250_H_DEF
#define MPU_9250_H_DEF

#define MPU_9250_ADDR 0x68

#define MPU_9250_REG_WHO_AM_I 0x75

typedef struct MPU_9250 {
    int fd;
    uint8_t who_am_i;
} MPU_9250;

#endif