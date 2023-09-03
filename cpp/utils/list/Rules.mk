# Directory Traversal (Don't touch)

sp             := $(sp).x
dirstack_$(sp) := $(dir)
dir            := $(subdir)

# Local rules and targets

SRCS_$(dir) := $(wildcard $(dir)/*.cpp)
INCS_$(dir) := $(dir)

# Dependency (Don't touch)

OBJS_$(dir) := $(SRCS_$(dir):.cpp=.o)
DEPS_$(dir) := $(SRCS_$(dir):.cpp=.d)

$(OBJS_$(dir)): CCFLAGS_LOCAL := $(addprefix -iquote,$(INCS_$(dir)))
-include $(DEPS_$(dir))

CLEAN_FILES += $(OBJS_$(dir)) $(DEPS_$(dir))

# Directory Traversal (Don't touch)

dir            := $(dirstack_$(sp))
sp             := $(basename $(sp))