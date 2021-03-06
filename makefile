#==============================================================================
# Quad Bot: Makefile
#------------------------------------------------------------------------------
# Makefile for compiling the application for controlling the quadruped robot.
#
# Created:  April 2, 2017
# Author:   Matt Mumau
#==============================================================================

# The c compiler
CC=gcc

# Project directories
INC_DIR=inc
SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
BIN_DIR=bin

# Compiler flags
CFLAGS=-Wall -I$(INC_DIR) -std=c11

LIBS=-lwiringPi -lwiringPiPca9685 -lrt -lpthread -lm

# Project DEPS
_DEPS = main.h \
	config.h \
	config_defaults.h \
	configset_callbacks.h \
	config_file.h \
	config_stdin.h \
	console.h \
	prompt.h \
	log.h \
	string_utils.h \
	utils.h \
	robot.h \
	events.h \
	list.h \
	keyframe_factory.h \
	keyframe_handler.h \
	prompt_commands.h \
	easing.h \
	easing_utils.h \
	math_defs.h \
	event_callbacks.h \
	http_server.h \
	http_request.h \
	http_response.h \
	http_request_handler.h \
	usd_sensor.h \
	controller_event.h \
	cJSON.h \
	mvc_data.h \
	controller_usd.h
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))

# Server Objects
_OBJ = main.o \
	config.o \
	configset_callbacks.o \
	config_file.o \
	config_stdin.o \
	log.o \
	console.o \
	prompt.o \
	string_utils.o \
	utils.o \
	robot.o \
	events.o \
	list.o \
	keyframe_factory.o \
	keyframe_handler.o \
	prompt_commands.o \
	easing.o \
	event_callbacks.o \
	easing_utils.o \
	http_server.o \
	http_request.o \
	http_response.o \
	http_request_handler.o \
	usd_sensor.o \
	controller_event.o \
	cJSON.o \
	mvc_data.o \
	controller_usd.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

peabot: $(OBJ)
	$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) $(LIBS)

debug: $(OBJ)
	$(CC) -g -o $(BIN_DIR)/peabot_debug $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/peabot $(BIN_DIR)/peabot_debug;

.PHONY: install
install:
	if [ ! -d /var/log/peabot ]; \
	then \
		mkdir /var/log/peabot; \
	fi; \
	chown -R peabot:peabot /var/log/peabot; \
	chmod -R 770 /var/log/peabot; \

	mv bin/peabot /bin/peabot; \
	chown root:root /bin/peabot; \
	
	if [ ! -e etc/peabot.conf ]; \
	then \
	    cp etc/peabot.conf.orig etc/peabot.conf; \
	fi; \
	
.PHONY: full_uninstall
full_uninstall:
	if [ -e /bin/peabot_server ]; \
	then \
		rm /bin/peabot_server; \
	fi; \