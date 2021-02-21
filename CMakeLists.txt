cmake_minimum_required(VERSION 3.5)

set( THIS coracao_caixa )
project(${THIS} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

enable_testing()

add_subdirectory( config )
add_subdirectory( logica )
add_subdirectory( interface )
add_subdirectory( googletest )
add_subdirectory( teste )


add_executable(${THIS}
    main.cpp
)

target_link_libraries(${THIS}
    PUBLIC Qt${QT_VERSION_MAJOR}::Widgets
    PUBLIC config
    PUBLIC interface
    PUBLIC logica
)


