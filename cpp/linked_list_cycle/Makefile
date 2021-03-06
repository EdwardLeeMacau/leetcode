CX = g++
CFLAGS = -Wall --std=c++11 -O3

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
DEPS = $(patsubst %.cpp, %.d, $(SRCS))

INCDIRS = ../googletest/googletest/include \
          ../utils
LIBDIRS = ../googletest/build/lib
LIBS = gtest

BIN = unittest

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	@echo "Building $@..."
	@$(CX) $(CFLAGS) -pthread $^ $(addprefix -L, $(LIBDIRS)) $(addprefix -l, $(LIBS)) -o $@

%.o: %.cpp
	@echo "Compiling $@..."
	@$(CX) $(CFLAGS) -c -MMD $^ $(addprefix -I, $(INCDIRS)) -o $@ 

.PHONY: clean
clean:
	@find . -name "*.[do]" -exec rm -rf {} \;
	@find . -name "$(BIN)" -exec rm -rf {} \;