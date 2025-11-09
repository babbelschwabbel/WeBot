# WEBOTS CONTROLLER MAKEFILE
# Definiert die Quelldateien und den Controller-Namen.

# --- PFAD-SETUP FÜR WEBOTS (NICHT ÄNDERN) ---
# Diese Zeilen stellen sicher, dass der WEBOTS_HOME Pfad korrekt verarbeitet wird.
null :=
space := $(null) $(null)
WEBOTS_HOME = C:\PROGRA~1\Webots
WEBOTS_HOME_PATH?=$(subst $(space),\ ,$(strip $(subst \,/,$(WEBOTS_HOME))))

# -------------------
# WEBOTS CONTROLLER KONFIGURATION
# -------------------

# 1. Definieren Sie den Namen der ausführbaren Datei
NAME = epuck_avoid_collision

# 2. Definieren Sie ALLE Quelldateien (.c), die kompiliert werden müssen
SOURCES = epuck_avoid_collision.c \
          epuck_hardware.c \
          epuck_logic.c

# 3. Binden Sie die Haupt-Webots-Regeln ein.
# Diese Datei enthält die Regeln für 'make', 'make clean', etc.
include $(WEBOTS_HOME_PATH)/resources/Makefile.include