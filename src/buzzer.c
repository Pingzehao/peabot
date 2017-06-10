#ifndef BUZZER_DEF
#define BUZZER_DEF

/*
 File:          buzzer.c
 Description:   Immplementation of piezo buzzer (sound) functionality.
 Created:       June 10, 2017
 Author:        Matt Mumau
 */

#define _POSIX_C_SOURCE 199309L

/* System includes */
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

/* Raspberry Pi libraries */
#include <wiringPi.h>

/* Application includes */
#include "main.h"
#include "log.h"
#include "utils.h"

/* Header */
#include "buzzer.h"

bool running = true;
pthread_t buzzer_thread;
int error;

static double note_freq = 3000;

void buzzer_init() {
    error = pthread_create(&buzzer_thread, NULL, buzzer_main, NULL);
    if (error)
        APP_ERROR("Could not create buzzer thread.", 1);
}

void buzzer_halt()
{
    running = false;
    error = pthread_join(buzzer_thread, NULL);
    if (error)
        log_error("Could not rejoin from buzzer thread.", error);
}

void *buzzer_main(void *arg) {
    // todo: move these to config vars
    unsigned short buzzer_pin_a = 3;
    unsigned short buzzer_pin_b = 4;

    bool flipped = false;

    pinMode(buzzer_pin_a, OUTPUT);
    pinMode(buzzer_pin_b, OUTPUT);

    struct timespec time;
    struct timespec last_time;

    double tick = 0.0;
    double diff = 0.0;

    clock_gettime(CLOCK_MONOTONIC, &last_time);

    while (running)
    {
        digitalWrite(buzzer_pin_a, flipped ? HIGH : LOW);
        digitalWrite(buzzer_pin_b, flipped ? LOW : HIGH);

        // clock_gettime(CLOCK_MONOTONIC, &time);
        // diff = utils_timediff(time, last_time);
        // last_time = time;

        // tick += diff;

        // if (tick < (1 / note_freq))
        //     continue;

        // tick = 0.0;
        flipped = !flipped;
    }

    digitalWrite(buzzer_pin_a, LOW);
    digitalWrite(buzzer_pin_b, LOW);

    return (void *) NULL;
}


#endif