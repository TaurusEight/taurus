
dir = curses
src = window panel
local = $(foreach F,$(src),./$(dir)/$(F).o)
module = ./$(dir)/lib$(dir).a
trash += $(local) $(module)

$(lib) : $(local) ; ar rcs $@ $^
