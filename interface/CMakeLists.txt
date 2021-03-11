cmake_minimum_required(VERSION 3.5)

set(THIS interface)
project(${THIS} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(FORMS
    frmPrincipal.h frmPrincipal.cpp frmPrincipal.ui
    frmContribuicao.h frmContribuicao.cpp frmContribuicao.ui
    frmNovoMorador.h frmNovoMorador.cpp frmNovoMorador.ui
)

set(WIDGETS
    wgtCasa.h wgtCasa.cpp
    wgtMorador.h wgtMorador.cpp
    wgtConta.h wgtConta.cpp
)
set(BASE_POLIMORFICA
    
    poliDialog.h
)

add_library(${THIS} SHARED ${FORMS} ${WIDGETS} ${BASE_POLIMORFICA})

target_link_libraries(${THIS}
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE config
    PRIVATE logica
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)


qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})



