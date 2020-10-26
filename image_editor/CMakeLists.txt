add_executable (image_editor "image_editor.cpp" "image_editor.h")

#include_directories(${CMAKE_INSTALL_PREFIX}/include)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(image_editor opencv_world)


