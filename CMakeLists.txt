# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("image_editor")

# Включите подпроекты.
add_subdirectory ("opencv")
add_subdirectory ("image_editor")
