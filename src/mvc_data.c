#ifndef MVC_DATA_DEF
#define MVC_DATA_DEF

/*
 File:          mvc_data.c
 Description:   An object for wrapping all data for an MVC request.
 Created:       May 29, 2017
 Author:        Matt Mumau
 */

/* System includes */
#include <stdio.h>
#include <string.h>

/* Libraries */
#include "cJSON.h"

/* Application includes */
#include "http_request.h"
#include "http_response.h"
#include "string_utils.h"

/* Header */
#include "mvc_data.h"

/* Forward decs */
static int mvcdata_get_model(char *model_str);
static int mvcdata_get_controller(char *controller_str);

void mvcdata_set(MVCData *mvc_data, HTTPRequest *http_request, HTTPResponse *http_response, char *model, char *controller, char *query)
{
    mvc_data->http_request = http_request;
    mvc_data->http_response = http_response;
    mvc_data->model = mvcdata_get_model(model);
    mvc_data->controller = mvcdata_get_controller(controller);
    //mvc_data->query_str = query; todo: parse the query string
    mvc_data->request_json = cJSON_Parse(http_request->body);
    mvc_data->response_json = cJSON_CreateObject();  
}

void mvcdata_destroy(MVCData *mvc_data)
{
    cJSON_Delete(mvc_data->request_json);
    cJSON_Delete(mvc_data->response_json);
}

const char *mvcdata_get_modelstr(MVCData *mvc_data)
{
    switch (mvc_data->model)
    {
        case MODEL_EVENT:
            return "EVENT";
        case MODEL_USD:
            return "USD";
        case MODEL_POSITION:
            return "POSITION";
    }

    return "INVALID";
}

const char *mvcdata_get_controllerstr(MVCData *mvc_data)
{
    switch (mvc_data->controller)
    {
        case CONTROLLER_WALK:
            return "WALK";
        case CONTROLLER_TURN:
            return "TURN";
        case CONTROLLER_ELEVATE:
            return "ELEVATE";
        case CONTROLLER_EXTEND:
            return "EXTEND";
        case CONTROLLER_RESET:
            return "RESET";
        case CONTROLLER_GET:
            return "GET";
        case CONTROLLER_HALT:
            return "HALT";
        case CONTROLLER_STRAFE:
            return "STRAFE";
    }

    return "INVALID";
}

static int mvcdata_get_model(char *model_str)
{
    if (strcmp(model_str, "event") == 0)
        return MODEL_EVENT;

    if (strcmp(model_str, "usd") == 0)
        return MODEL_USD;

    if (strcmp(model_str, "position") == 0)
        return MODEL_POSITION;

    return MODEL_NONE;
}

static int mvcdata_get_controller(char *controller_str)
{
    if (strcmp(controller_str, "walk") == 0)
        return CONTROLLER_WALK;

    if (strcmp(controller_str, "turn") == 0)
        return CONTROLLER_TURN;

    if (strcmp(controller_str, "elevate") == 0)
        return CONTROLLER_ELEVATE;

    if (strcmp(controller_str, "extend") == 0)
        return CONTROLLER_EXTEND;

    if (strcmp(controller_str, "reset") == 0)
        return CONTROLLER_RESET;

    if (strcmp(controller_str, "get") == 0)
        return CONTROLLER_GET;    

    if (strcmp(controller_str, "halt") == 0)
        return CONTROLLER_HALT;

    if (strcmp(controller_str, "strafe") == 0)
        return CONTROLLER_STRAFE;

    return CONTROLLER_NONE;
}

#endif