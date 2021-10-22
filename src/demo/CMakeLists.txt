add_avr_executable(demo-ICM7212 main.cpp)
avr_target_include_directories(demo-ICM7212 PUBLIC ../inc)
avr_target_link_libraries(demo-ICM7212 PUBLIC ICM7212)
