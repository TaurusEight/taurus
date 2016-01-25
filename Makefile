
# Rules
%.d : %.cc ; ./dep.sh $<
%.o : %.d ; g++ -std=c++11 -c -o $@ $

# Macro
cc := /usr/bin/g++
libs = -lncurses
libname = $(1)/lib$(1).a
ccflags = -std=c++11

# Main target
all : demo

library = $(subst LIB,$(1),-lLIB -L./LIB)

modules := . curses metric
cflags += $(patsubst %,-I%,$(modules))
src =
targets =

#include ./module.mk
include $(patsubst %,%/module.mk,$(modules))

obj := $(src:.cc=.o)
dependents := $(src:.cc=.d)
include $(dependents)


clean:
	rm --force $(targets)
	rm --force $(src:.cc=.o)
	rm --force $(dependents)


dump:
	@echo ===========================
	@echo libs: $(libs)
	@echo src: $(src)
	@echo obj: $(obj)
	@echo targets: $(targets)
	@echo dependets: $(dependents)
