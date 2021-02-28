DIRS := $(filter-out googletest Makefile, $(wildcard *))

# Define buildtools

CC = gcc
CX = g++
AR = ar

ASFLAGS_ALL =
CCFLAGS_ALL = -O3 -Wall -MMD --std=c++11
LDFLAGS_ALL =

ASFLAGS_LOCAL :=
CCFLAGS_LOCAL :=
LDFLAGS_LOCAL :=

ARCHIVE = $(AR) rcs $@ $^
COMPILE = -c -o $@ $< $(CCFLAGS_ALL) $(CCFLAGS_LOCAL)
LINK    = -o $@ $^ $(LDFLAGS_ALL) $(LDFLAGS_LOCAL)

# Define default target

.PHONY: all
all: primary

# Define global variable lists

TARGET_BINS  :=
TARGET_LIBS  :=
TARGET_TESTS :=
CLEAN_FILES  :=
CLEAN_DIRS   :=

# Subdirectories, in random order

root := .
dir  := .

subdir := list
include $(subdir)/Rules.mk

subdir := matrix
include $(subdir)/Rules.mk

subdir := tree
include $(subdir)/Rules.mk

subdir := unit_test
include $(subdir)/Rules.mk

# Describe how to build libraries

TARGET_LIB_$(dir) := libutils.a

$(TARGET_LIB_$(dir)): $(OBJS_list) \
                      $(OBJS_matrix) \
			          $(OBJS_tree)
	@echo "  AR \t$@"
	@$(ARCHIVE)

TARGET_LIBS += $(TARGET_LIB_$(dir))
CLEAN_FILES += $(TARGET_LIB_$(dir))

# Build targets

.PHONY: primary
primary: $(TARGET_LIBS) $(TARGET_BINS)

.PHONY: test
test: $(TARGET_TESTS)

.PHONY: distclean
distclean: clean

.PHONY: clean
clean:
	@rm -f $(CLEAN_FILES)
	@rm -rf $(CLEAN_DIRS)

# General directory independent rules

%.o: %.c
	@echo "  CC \t$@"
	@$(CC) $(COMPILE)

%.o: %.cpp
	@echo "  CX \t$@"
	@$(CX) $(COMPILE)