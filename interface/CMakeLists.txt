cmake_minimum_required(VERSION 3.5)

project(interface LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    frmprincipal.h frmprincipal.cpp frmprincipal.ui
    frmcontribuicao.h frmcontribuicao.cpp frmcontribuicao.ui
    moradores.h moradores.cpp
    botao.h botao.cpp
)


target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE config
    PRIVATE logica
)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})



