BITNESS   ?= $(shell getconf LONG_BIT)

makefile = Makefile-x$(BITNESS).mk

ifneq (,$(wildcard ./$(makefile)))
$(info ========================)
$(info   $(BITNESS)-bit version)
$(info ========================)
include $(makefile)
else
$(info ==================================)
$(info   $(BITNESS)-bit version not found)
$(info ==================================)
endif
