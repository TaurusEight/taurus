
#
# Curses Module
#

# Variables
curses_ := window panel

curses_src = $(foreach F,$(curses_),curses/$(F).cc)
src += $(curses_src)

curses_target = $(call libname,curses)
target_objs += $(curses_target)

# Target
$(curses_target) : $(curses_src:.cc=.o) ; ar rcs $@ $^
