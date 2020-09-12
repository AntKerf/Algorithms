cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(Sortings)			# Название проекта

set(SOURCE_EXE Sortings.cpp)		# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB Sorts.cpp)			# Тоже самое, но для библиотеки

add_library(Sorts STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_executable(Sortings ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(Sortings Sorts)	