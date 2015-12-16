
# Rules
%.d : %.cc ; ./dep.sh $<
%.o : %.d ; g++ -std=c++11 -c -o $@ $

# Macro
cc := /usr/bin/g++
libs := -lncurses -lmetric -lcurses -L./metric -L./curses
libname = $(1)/lib$(1).a
ccflags = -std=c++11

# Main target
all : demo


modules := curses metric
cflags += $(patsubst %,-I%,$(modules))
target := demo
src =
target_objs =


include ./module.mk
include $(patsubst %,%/module.mk,$(modules))

obj := $(src:.cc=.o)

include $(obj:.o=.d)

$(target):	$(target_objs)
	$(cc) $(cflags) -o $@ $< $(libs)


clean:
	rm -f $(obj) $(obj:.o=.d) $(target_objs) $(target)

$(target):	$(modules)
	$(cc) $(ccflags) -c -o $@ $^

dump:
	@echo ===========================
	@echo libs: $(libs)
	@echo src: $(src)
	@echo obj: $(obj)
	@echo target_objs: $(target_src)

sample:	exception.o sample.o
	$(cc) $(ccflag) -o $@ $^

sample.o:	sample.cc exception.hh
	$(cc) $(ccflag) -c -o $@ $<
