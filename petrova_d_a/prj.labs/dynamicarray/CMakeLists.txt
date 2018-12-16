#add_library(dynamicarray INTERFACE)
#target_sources(dynamicarray INTERFACE dynamicarray.h)
add_library(dynamicarray dynamicarray.cpp dynamicarray.h)
set_property(TARGET dynamicarray PROPERTY CXX_STANDARD 14)
