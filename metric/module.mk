
#
# Metric Module
#

# Variables
metric_ = point

metric_src = $(foreach F,$(metric_),metric/$(F).cc)
src += $(metric_src)

metric_target = $(call libname,metric)
target_objs += $(metric_target)

# Target
$(target_objs) : $(metric_src:.cc=.o) ; ar rcs $@ $^
