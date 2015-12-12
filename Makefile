


%.d : %.cc ; ./dep.sh $<

cxx := /usr/bin/g++


target := sample
objs = main.o

trash = $(target) $(objs)

cflags := -std=c++11
libs := -lncurses -lmetric -lcurses -L./metric -L./curses


all:	$(target)


include ./curses/module.mk
include ./module.mk

$(target):	$(modules)
	$(cxx) $(cflags) -c -o $@ $^

dump:
	@echo $(trash)
	@echo $(local)
	@echo $(src)

clean:
	rm -f $(trash)
