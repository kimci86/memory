# files
file(GLOB_RECURSE header_files "${PROJECT_SOURCE_DIR}/include/*")
file(GLOB_RECURSE source_files "${PROJECT_SOURCE_DIR}/src/*")

# executable
add_executable(memory ${header_files} ${source_files})

# link
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(memory ${SFML_LIBRARIES})

# install rules
install(TARGETS memory DESTINATION bin)
