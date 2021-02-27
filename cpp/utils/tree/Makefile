CX = g++
AR = ar
CFLAGS = -Wall --std=c++11 -O3

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
DEPS = $(patsubst %.cpp, %.d, $(SRCS))

BIN = libutils.a

.PHONY: default
default: all

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	@echo "Building $@..."
	@$(AR) rcsD $@ $^

%.o: %.cpp
	@echo "Compiling $@..."
	@$(CX) $(CFLAGS) -c -MMD $^ -I. -o $@ 

.PHONY: clean
clean:
	@find . -name "*.[ado]" -exec rm -rf {} \;