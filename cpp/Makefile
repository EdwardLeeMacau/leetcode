DIRS := $(filter-out googletest Makefile, $(wildcard *))

.PHONY: distclean
distclean: clean

.PHONY: clean
clean: $(addprefix clean-, $(DIRS))

.PHONY: clean-%
clean-%:
	@make -C $(patsubst clean-%, %, $@) clean
