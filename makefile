# ------------------------------------------------
# Generic Makefile
#
# Author: csomos.gergo@gmail.com
# Date  : 2015-11-30
#
# Changelog :
#   2015-11-30 - first version, based on:
#                http://stackoverflow.com/questions/7004702/how-can-i-create-a-makefile-for-c-projects-with-src-obj-and-bin-subdirectories
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = DesignPatterns

CC       = g++
# compiling flags here
CFLAGS   = -std=c++11 -Wall -Werror -ggdb

LINKER   = g++
# linking flags here
LFLAGS   = -Wall

# change these to set the proper directories where each files shoould be
SRCDIR   = src
INCDIR   = include
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES = -I$(INCDIR)/
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f

all: $(BINDIR)/$(TARGET)
	@echo  "DesignPatterns has been compiled!"
	
$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) -o $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
