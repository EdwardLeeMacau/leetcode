DIRS := $(filter-out googletest Makefile, $(wildcard *))

.PHONY: default
default: all

.PHONY: all
all:

.PHONY: distclean
distclean: clean

.PHONY: clean
clean: $(addprefix clean-, $(DIRS))

.PHONY: clean-%
clean-%:
	@make -C $(patsubst clean-%, %, $@) clean
