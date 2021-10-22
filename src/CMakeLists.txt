add_avr_library(ICM7212 ICM7212.cpp ICM7212A.cpp ICM7212M.cpp ICM7212AM.cpp)
avr_target_include_directories(ICM7212 PUBLIC ../inc)

add_subdirectory(demo)
