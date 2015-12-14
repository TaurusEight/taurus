
base_ = main exception

base_src = $(foreach F,$(base_),$(F).cc)
src += $(base_src)

target_objs += $(base_src:.cc=.o)
