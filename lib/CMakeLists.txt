include_directories(include)

add_library(CFGUtils SHARED
    CFGUtils.cpp
)
set_target_properties(CFGUtils PROPERTIES
    SOVERSION 0
    COMPILE_FLAGS "-std=c++14 -fno-rtti"
)

include(GNUInstallDirs)
install(TARGETS CFGUtils
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
