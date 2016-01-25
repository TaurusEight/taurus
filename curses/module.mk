
#
# Curses Module
#

curses_list := curses/window.cc curses/panel.cc
curses_target := curses/libcurses.a

src += $(curses_list)
targets += $(curses_target)
libs += $(call library,curses)

# Module target
$(curses_target) : $(curses_list:.cc=.o) ; ar rcs $@ $^
