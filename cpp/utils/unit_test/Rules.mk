# Directory Traversal (Don't touch)

sp             := $(sp).x
dirstack_$(sp) := $(dir)
dir            := $(subdir)

# Local rules and targets

SRCS_$(dir) := $(wildcard $(dir)/*.cpp)
INCS_$(dir) := $(root) \
               $(dir) \
			   ../googletest/include/gtest
LIBDIRS_$(dir) := ../googletest/build/lib
LIBS_$(dir) := gtest

# Dependency (Don't touch)

OBJS_$(dir) := $(SRCS_$(dir):.cpp=.o)
DEPS_$(dir) := $(SRCS_$(dir):.cpp=.d)

$(OBJS_$(dir)): CCFLAGS_LOCAL := $(addprefix -iquote,$(INCS_$(dir)))
-include $(DEPS_$(dir))

CLEAN_FILES += $(OBJS_$(dir)) $(DEPS_$(dir))

TARGET_TEST_$(dir) := $(root)/unittest
$(TARGET_TEST_$(dir)): LDFLAGS_LOCAL := $(addprefix -L,$(LIBDIRS_$(dir))) $(addprefix -l,$(LIBS_$(dir)))
$(TARGET_TEST_$(dir)): $(OBJS_$(dir))
	@echo "  CX\t$@"
	@$(CX) $(LINK)

TARGET_TESTS += $(TARGET_TEST_$(dir))
CLEAN_FILES  += $(TARGET_TEST_$(dir))

# Directory Traversal (Don't touch)

dir            := $(dirstack_$(sp))
sp             := $(basename $(sp))