CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

FIND_PACKAGE(X11 REQUIRED)

ADD_DEFINITIONS("-O2 -std=c++0x -fpermissive -Wno-write-strings")

INCLUDE_DIRECTORIES([AFTER] src)

ADD_EXECUTABLE(
    test 
    test/test.cxx 
    src/Widgets/XtApplication.cxx 
    src/Widgets/Components.cxx 
    src/Widgets/FormPanel.cxx 
    src/Widgets/BoxPanel.cxx 
    src/Widgets/PanedPanel.cxx 
    src/Widgets/Menu/Menu.cxx
    src/Widgets/Menu/MenuPanel.cxx
    src/Widgets/Label.cxx 
    src/Widgets/MessageBox.cxx
    src/Widgets/IWidget.cxx
    src/Widgets/Button.cxx
    src/XtGui.cxx
    )

# I use classic Athena Widget
TARGET_LINK_LIBRARIES(test -lXaw ${X11_Xt_LIB} ${X11_Xext_LIB} ${X11_X11_LIB})

# Or Xaw3d
#TARGET_LINK_LIBRARIES(test -lXaw3d ${X11_Xt_LIB} ${X11_Xext_LIB} ${X11_X11_LIB})

# Or neXtaw
#TARGET_LINK_LIBRARIES(test -lneXtaw ${X11_Xt_LIB} ${X11_Xext_LIB} ${X11_X11_LIB})


