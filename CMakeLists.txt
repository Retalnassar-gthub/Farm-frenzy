cmake_minimum_required(VERSION 3.16)

project(FarmFrenzy C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FarmFrenzy
    main.cpp
    Core/Drawable.cpp
    Core/GameObject.cpp
    Core/Game.cpp
    Entities/Animal.cpp
    UI/BudgetBar.cpp
    UI/StatusBar.cpp
    UI/Toolbar.cpp
    CMUgraphicsLib/auxil.cpp
    CMUgraphicsLib/CMUgraphics.cpp
    CMUgraphicsLib/image.cpp
    CMUgraphicsLib/keyqueue.cpp
    CMUgraphicsLib/mousequeue.cpp
    CMUgraphicsLib/windowinput.cpp
    CMUgraphicsLib/jpegload.c
    CMUgraphicsLib/jpeg/jcomapi.c
    CMUgraphicsLib/jpeg/jcparam.c
    CMUgraphicsLib/jpeg/jdapimin.c
    CMUgraphicsLib/jpeg/jdapistd.c
    CMUgraphicsLib/jpeg/jdatasrc.c
    CMUgraphicsLib/jpeg/jdcoefct.c
    CMUgraphicsLib/jpeg/jdcolor.c
    CMUgraphicsLib/jpeg/jddctmgr.c
    CMUgraphicsLib/jpeg/jdhuff.c
    CMUgraphicsLib/jpeg/jdinput.c
    CMUgraphicsLib/jpeg/jdmainct.c
    CMUgraphicsLib/jpeg/jdmarker.c
    CMUgraphicsLib/jpeg/jdmaster.c
    CMUgraphicsLib/jpeg/jdmerge.c
    CMUgraphicsLib/jpeg/jdphuff.c
    CMUgraphicsLib/jpeg/jdpostct.c
    CMUgraphicsLib/jpeg/jdsample.c
    CMUgraphicsLib/jpeg/jdtrans.c
    CMUgraphicsLib/jpeg/jerror.c
    CMUgraphicsLib/jpeg/jidctflt.c
    CMUgraphicsLib/jpeg/jidctfst.c
    CMUgraphicsLib/jpeg/jidctint.c
    CMUgraphicsLib/jpeg/jidctred.c
    CMUgraphicsLib/jpeg/jmemmgr.c
    CMUgraphicsLib/jpeg/jmemnobs.c
    CMUgraphicsLib/jpeg/jquant1.c
    CMUgraphicsLib/jpeg/jquant2.c
    CMUgraphicsLib/jpeg/jutils.c
)

target_compile_definitions(FarmFrenzy PRIVATE WIN32)

if (WIN32)
    target_link_libraries(FarmFrenzy PRIVATE gdi32 winmm comdlg32)
endif()

# Automatically copy the images folder to the build directory so the game can find it
add_custom_command(TARGET FarmFrenzy POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/images"
        "$<TARGET_FILE_DIR:FarmFrenzy>/images"
)
