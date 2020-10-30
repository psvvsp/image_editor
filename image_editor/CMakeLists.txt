add_executable (image_editor 
    "commands.cpp"
    "commands.h"
    "main.cpp"
    "lexer.cpp"
    "lexer.h"
    "parser.h"
    "parser.cpp"
    "command_parser.cpp"
    "command_parser.h"
    "executor.cpp"
    "executor.h"
    "common.h"
    "exception.h")

target_include_directories(image_editor PRIVATE
    ../opencv/include
    ../opencv/modules/calib3d/include
    ../opencv/modules/core/include
    ../opencv/modules/dnn/include
    ../opencv/modules/features2d/include
    ../opencv/modules/flann/include
    ../opencv/modules/gapi/include
    ../opencv/modules/highgui/include
    ../opencv/modules/imgcodecs/include
    ../opencv/modules/imgproc/include
    ../opencv/modules/java/include
    ../opencv/modules/js/include
    ../opencv/modules/ml/include
    ../opencv/modules/objc/include
    ../opencv/modules/objdetect/include
    ../opencv/modules/photo/include
    ../opencv/modules/python/include
    ../opencv/modules/stitching/include
    ../opencv/modules/ts/include
    ../opencv/modules/video/include
    ../opencv/modules/videoio/include
    ../opencv/modules/world/include
    ${CMAKE_BINARY_DIR}
)

target_link_libraries(image_editor opencv_world)



