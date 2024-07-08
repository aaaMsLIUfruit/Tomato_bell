cmake_minimum_required(VERSION 3.5)

project(hello VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
     main.cpp
    Clock.h  Clock.cpp  Clock.ui
    config.h
    mainClock.h mainClock.cpp mainClock.ui
    mainwindow.h mainwindow.cpp mainwindow.ui
    Register.h Register.cpp Register.ui
    Sign_in.h Sign_in.cpp Sign_in.ui
    start_task.h start_task.cpp start_task.ui
    usercenter.h usercenter.cpp usercenter.ui
    resources/resources.qrc  # 添加资源文件

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(hello
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(hello SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(hello
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(hello PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.hello)
endif()
set_target_properties(hello PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS hello
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(hello)
endif()
