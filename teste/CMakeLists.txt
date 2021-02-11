cmake_minimum_required(VERSION 3.5)

set(THIS teste)
project(${THIS} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set( TESTES
    testMorador.cpp
)


add_executable(
    ${THIS} 
    ${TESTES} 
)

target_link_libraries(${THIS}
    PUBLIC gtest_main
    PUBLIC config
    PUBLIC logica
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

add_test(
    NAME ${THIS}
    COMMAND ${THIS}
)
