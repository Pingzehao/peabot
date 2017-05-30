#ifndef CONTROLLER_EVENT_H_DEF
#define CONTROLLER_EVENT_H_DEF

/*
 File:          controller_event.h
 Description:   Controller function for HTTP event models.
 Created:       May 28, 2017
 Author:        Matt Mumau
 */

#include <stdbool.h>

bool cntlevent_walk(MVCData *mvc_data);

bool cntlevent_turn(MVCData *mvc_data);

bool cntlevent_elevate(MVCData *mvc_data);

bool cntlevent_extend(MVCData *mvc_data);

bool cntlevent_delay(MVCData *mvc_data);

bool cntlevent_reset(MVCData *mvc_data);

#endif