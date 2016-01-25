
#
# Main Module
#

demo_list := main.cc exception.cc

src += $(demo_list) sample.cc
targets += demo sample

demo : $(demo_list:.cc=.o) curses/libcurses.a metric/libmetric.a
	$(cc) $(cflags) -o $@ $(demo_list:.cc=.o) $(libs)

sample : sample.o exception.o ; $(cc) $(cflags) -o $@ $^
