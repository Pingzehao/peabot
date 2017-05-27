#ifndef HTTP_REQUEST_DEF
#define HTTP_REQUEST_DEF

/*
 File:          http_request.h
 Description:   Object for parsing HTTP requests.
 Created:       May 23, 2017
 Author:        Matt Mumau
 */

/* System headers */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Application headers */
#include "http_server.h"
#include "string_utils.h"

/* Header */
#include "http_request.h"

/* Forward decs */
static void http_request_handle_lines(HTTPRequest *http_request, HTTPRequestLine *lines, unsigned int size);
static void http_request_handle_request_line(HTTPRequest *http_request, HTTPRequestLine *line);

void http_request_parse(HTTPRequest *http_request, char *raw, int buff_size)
{
    if (http_request == NULL || raw == NULL)
        return;

    char buffer_cpy[DEFAULT_HTTP_MAX_BUFFER];
    memset(buffer_cpy, '\0', DEFAULT_HTTP_MAX_BUFFER);
    memcpy(buffer_cpy, raw, DEFAULT_HTTP_MAX_BUFFER - 1);
    buffer_cpy[DEFAULT_HTTP_MAX_BUFFER - 1] = '\0'; 

    printf("\n[buffer_cpy:%d]\n%s\n", strlen(buffer_cpy), buffer_cpy);

    bool add_extra_line = (DEFAULT_HTTP_MAX_BUFFER % DEFAULT_HTTP_LINE_LEN) > 0;
    int max_lines = (DEFAULT_HTTP_MAX_BUFFER - (DEFAULT_HTTP_MAX_BUFFER % DEFAULT_HTTP_LINE_LEN)) / DEFAULT_HTTP_LINE_LEN;
    
    if (add_extra_line)
        max_lines++;

    HTTPRequestLine lines[max_lines];

    int max_body_len = DEFAULT_HTTP_MAX_BUFFER - ((DEFAULT_HTTP_MAX_HEADERS + 1) * DEFAULT_HTTP_LINE_LEN);

    unsigned int i;

    char body_str[max_body_len];
    char *body_substr = strstr(buffer_cpy, "\r\n\r\n");
    memset(body_str, '\0', max_body_len);
    memcpy(body_str, body_substr, max_body_len);
    body_str[max_body_len - 1] = '\0';

    int body_count = strlen(body_str);
    char *body = NULL;

    if (body_count > 4)
    {
        body = &(body_str[4]);
        printf("[body:%d]\n%s\n", body_count, body);
    }
    
    //char *header_lines_p = strtok(buffer_cpy, body_delim);
    // HTTPRequestLine *next_line;
    // for (i = 0; i < max_lines; i++)
    // {
    //     if (line_cursor == NULL)
    //         break;

    //     next_line = &(lines[i]);

    //     memset(next_line, '\0', DEFAULT_HTTP_LINE_LEN);
    //     memcpy(next_line, line_cursor, (size_t) DEFAULT_HTTP_LINE_LEN - 1);

    //     line_cursor = strtok(NULL, delim);
    // }

    // http_request->total_lines = i + 1;

    // http_request_handle_lines(http_request, lines, http_request->total_lines);
}

static void http_request_handle_lines(HTTPRequest *http_request, HTTPRequestLine *lines, unsigned int size)
{
    if (lines == NULL || size <= 0)
        return;

    http_request_handle_request_line(http_request, &(lines[0]));

    if (size == 1)
        return;

    for (int i = 1; i < size; i++)
    {
        // todo: handle headers as neccessary
        printf("[H#%d]: %s\n", i, lines[i]);
    }
}

static void http_request_handle_request_line(HTTPRequest *http_request, HTTPRequestLine *line)
{
    if (line == NULL)
        return;

    char line_cpy[DEFAULT_HTTP_LINE_LEN];
    memset(line_cpy, '\0', DEFAULT_HTTP_LINE_LEN);
    memcpy(line_cpy, line, DEFAULT_HTTP_LINE_LEN - 1);

    char *line_cursor;
    char delim[] = " ";
    
    http_request->method = HTTP_BADREQUEST;
    line_cursor = strtok((char *) line, delim);
    if (line_cursor == NULL)
        return;
    if (strcmp(line_cursor, "POST") == 0)
        http_request->method = HTTP_POST;    
    if (strcmp(line_cursor, "GET") == 0)
        http_request->method = HTTP_GET;
    if (strcmp(line_cursor, "PUT") == 0)
        http_request->method = HTTP_PUT;
    if (strcmp(line_cursor, "DELETE") == 0)
        http_request->method = HTTP_DELETE;

    memset(http_request->uri, '\0', DEFAULT_HTTP_URI_LEN);
    line_cursor = strtok(NULL, delim);
    if (line_cursor == NULL)
        return;
    memcpy(http_request->uri, line_cursor, DEFAULT_HTTP_URI_LEN);

    http_request->v11 = false;
    line_cursor = strtok(NULL, delim);
    if (line_cursor == NULL)
        return;

    if (strcmp(line_cursor, "HTTP/1.1") == 0)
        http_request->v11 = true;
}

#endif