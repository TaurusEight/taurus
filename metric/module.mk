
#
# Metric Module
#

metric_list := metric/point.cc
metric_target := metric/libmetric.a

src += $(metric_list)
targets += $(metric_target)
libs += $(call library,metric)

# Module target
$(metric_target) : $(metric_list:.cc=.o) ; ar rcs $@ $^
