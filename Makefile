# WEBOTS CONTROLLER MAKEFILE

# --- PATH SETUP FOR WEBOTS (DO NOT CHANGE) ---
null :=
space := $(null) $(null)
WEBOTS_HOME = C:\PROGRA~1\Webots
WEBOTS_HOME_PATH?=$(subst $(space),\ ,$(strip $(subst \,/,$(WEBOTS_HOME))))

# -------------------
# WEBOTS CONTROLLER CONFIGURATION
# -------------------

# 1. Define the name of the executable file
NAME = epuck_avoid_collision

# 2. Define ALL source files (.c) that need to be compiled
# Wichtig: Alle drei Module müssen hier gelistet sein!

# SOURCES = 	epuck_logic.c \
# 			epuck_hardware.c \
# 			epuck_avoid_collision.c 
SOURCES = $(wildcard *.c)

# 3. Include the main Webots rules.
include $(WEBOTS_HOME_PATH)/resources/Makefile.include