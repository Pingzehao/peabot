#ifndef CONFIGSET_CALLBACKS_DEF
#define CONFIGSET_CALLBACKS_DEF

/*
 File:          config_callbacks.c
 Description:   Implementation of configuration variable set functions.
 Created:       May 15, 2017
 Author:        Matt Mumau
 */

/* System includes */
#include <stdbool.h>
#include <stdlib.h>

/* Application includes */
#include "config.h"
#include "robot.h"
#include "string_utils.h"

/* Header */
#include "configset_callbacks.h"

void configset_log_file_dir(Config *config, void *data, bool is_string)
{
    config->log_file_dir = (const char *) data;
    return;
}

void configset_log_filename(Config *config, void *data, bool is_string)
{
    config->log_filename = (const char *) data;
    return;
}

void configset_log_configfile(Config *config, void *data, bool is_string)
{
    config->config_file = (const char *) data;
    return;
}

void configset_log_stdin(Config *config, void *data, bool is_string)
{
    bool val;

    if (is_string)
        val = str_equals((const char *) data, "true") ? true : false;
    else
    {
        bool *data_p = (bool *) data;
        val = *data_p;
    }
    
    config->log_stdin = val;
    return;
}

void configset_log_prompt_commands(Config *config, void *data, bool is_string)
{
    bool val;

    if (is_string)
        val = str_equals((const char *) data, "true") ? true : false;
    else
    {
        bool *data_p = (bool *) data;
        val = *data_p;
    }

    config->log_prompt_commands = val;
    return;
}

void configset_log_event_add(Config *config, void *data, bool is_string)
{
    bool val;

    if (is_string)
        val = str_equals((const char *) data, "true") ? true : false;
    else
    {
        bool *data_p = (bool *) data;
        val = *data_p;
    }

    config->log_event_add = val;
    return;
}

void configset_log_event_callbacks(Config *config, void *data, bool is_string)
{
    bool val;

    if (is_string)
        val = str_equals((const char *) data, "true") ? true : false;
    else
    {
        bool *data_p = (bool *) data;
        val = *data_p;
    }

    config->log_event_callbacks = val;
    return;
}

void configset_log_keyframes(Config *config, void *data, bool is_string)
{
    bool val;

    if (is_string)
        val = str_equals((const char *) data, "true") ? true : false;
    else
    {
        bool *data_p = (bool *) data;
        val = *data_p;
    }

    config->log_keyframes = val;
    return;
}

void configset_pca_9685_pin_base(Config *config, void *data, bool is_string) 
{
    unsigned int val;

    if (is_string)
        val = (unsigned int) atoi((const char *) data);
    else
    {
        unsigned int *data_p = (unsigned int *) data;
        val = *data_p;
    }

    config->pca_9685_pin_base = val;
    return;
}

void configset_pca_9685_max_pwm(Config *config, void *data, bool is_string)
{
    unsigned int val;

    if (is_string)
        val = (unsigned int) atoi((const char *) data);
    else
    {
        unsigned int *data_p = (unsigned int *) data;
        val = *data_p;
    }

    config->pca_9685_max_pwm = val;
    return;
}

void configset_pca_9685_hertz(Config *config, void *data, bool is_string)
{
    unsigned int val;

    if (is_string)
    {
        val = (unsigned int) atoi((const char *) data);
    }
    else
    {
        unsigned int *data_p = (unsigned int *) data;
        val = *data_p;
    }

    config->pca_9685_hertz = val;
    return;
}

void configset_servos_num(Config *config, void *data, bool is_string)
{
    unsigned short val;

    if (is_string)
        val = (unsigned short) atoi((const char *) data);
    else
    {
        unsigned short *data_p = (unsigned short *) data;
        val = *data_p;
    }

    config->servos_num = val;
    return;
}

void configset_robot_tick(Config *config, void *data, bool is_string)
{
    double val;

    if (is_string)
        val = (double) atof((const char *) data);
    else
    {
        double *data_p = (double *) data;
        val = *data_p;
    }

    config->robot_tick = val;
    return;
}

void configset_transitions_enable(Config *config, void *data, bool is_string)
{
    bool val;

    if (is_string)
        val = str_equals((const char *) data, "true") ? true : false;
    else
    {
        bool *data_p = (bool *) data;
        val = *data_p;
    }

    config->transitions_enable = val;
    return;
}

void configset_transition_time(Config *config, void *data, bool is_string)
{
    double val;

    if (is_string)
        val = (double) atof((const char *) data);
    else
    {
        double *data_p = (double *) data;
        val = *data_p;
    }

    config->transition_time = val;
    return;
}

void configset_walk_hip_delta(Config *config, void *data, bool is_string)
{
    double val;

    if (is_string)
        val = (double) atof((const char *) data);
    else
    {
        double *data_p = (double *) data;
        val = *data_p;
    }

    config->walk_hip_delta = val;
    return;
}

void configset_walk_knee_delta(Config *config, void *data, bool is_string)
{
    double val;

    if (is_string)
        val = (double) atof((const char *) data);
    else
    {
        double *data_p = (double *) data;
        val = *data_p;
    }

    config->walk_knee_delta = val;
    return;
}

void configset_walk_knee_pad_a(Config *config, void *data, bool is_string)
{
    double val;

    if (is_string)
        val = (double) atof((const char *) data);
    else
    {
        double *data_p = (double *) data;
        val = *data_p;
    }

    config->walk_knee_pad_a = val;
    return;
}

void configset_walk_knee_pad_b(Config *config, void *data, bool is_string)
{
    double val;

    if (is_string)
        val = (double) atof((const char *) data);
    else
    {
        double *data_p = (double *) data;
        val = *data_p;
    }

    config->walk_knee_pad_b = val;
    return;
}

void configset_servo_pins(Config *config, void *data, bool is_string)
{
    ServoPinData *data_p = (ServoPinData *) data;
    config->servo_pins[data_p->id] = data_p->val;
    return;
}

void configset_servo_limits(Config *config, void *data, bool is_string)
{
    ServoLimitData *data_p = (ServoLimitData *) data;
    ServoLimit *servo_limit = &(config->servo_limits[data_p->id]);
    servo_limit->min = data_p->min;
    servo_limit->max = data_p->max;
    return;
}

void configset_http_enabled(Config *config, void *data, bool is_string)
{
    bool val;

    if (is_string)
    {
        val = str_equals(data, "true") ? true : false;
    }
    else
    {
        bool *data_p = (bool *) data;
        val = *data_p;
    }

    config->http_enabled = val;
    return;
}

void configset_http_port(Config *config, void *data, bool is_string)
{
    int val;

    if (is_string)
    {
        val = (int) atof((char *) data);
    }
    else
    {
        int *data_p = (int *) data;
        val = *data_p;
    }

    config->http_port = val;
    return;
}

#endif