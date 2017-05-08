#ifndef CONFIG_H_DEF
#define CONFIG_H_DEF

/*
 File:          config.h
 Description:   Peabot application-level configuration
 Created:       May 5, 2017
 Author:        Matt Mumau
 */

/* Application settings */
#define LOG_FILENAME_MAXLEN 64
#define LOG_STDIN 1

/* PCA-9685 config */
#define PCA_9685_PIN_BASE 300
#define PCA_9685_MAX_PWM 4096
#define PCA_9685_HERTZ 50

/* Robot related*/
#define SERVOS_NUM 8
#define ROBOT_TICK 0.1
#define SERVO_DEFAULT_MIN 200
#define SERVO_DEFAULT_MAX 400

/* PCA_9685 servo pins*/
#define FRONT_RIGHT_KNEE 6
#define FRONT_RIGHT_HIP 7
#define FRONT_LEFT_KNEE 3
#define FRONT_LEFT_HIP 2
#define BACK_RIGHT_KNEE 4
#define BACK_RIGHT_HIP 5
#define BACK_LEFT_KNEE 0
#define BACK_LEFT_HIP 1

void config_init();

void config_pipe(int argc, char * argv[]);

char *config_logfile();

#endif