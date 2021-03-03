/* 
XtGui - Copyright (©) 2012,2021 daltomi <daltomi@disroot.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or 
(at your option) any later version.

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License 
along with this program.  If not, see http://www.gnu.org/licenses/.
*/

#include "XtApplication.hpp"

Atom XtApplication::wm_delete_window;
QuitCallback XtApplication::ptr_quit = 0;

//////////////////////////////
XtApplication::XtApplication(
        const char*   app_name,
        int argc, 
        char** argv,  
        const char*  app_resources[],
        const Dimension width,
        const Dimension height
        ) : mainWidth(width), mainHeight(height)
//////////////////////////////
{

    XtSetLanguageProc(NULL, NULL, NULL);

    appWidget = XtOpenApplication(
             &appContext,
             (char*)app_name,
             NULL,0,
             &argc,argv,
             (char**)app_resources,
             applicationShellWidgetClass,
             NULL,0);


    display = XtDisplay(appWidget);
    
    screen  = DefaultScreen(display);

    CenterOfScreen();
}

////////////////////////////////
XtApplication::~XtApplication() 
////////////////////////////////
{
    XtDestroyApplicationContext(appContext);
}


////////////////////////////////////////////////////////////
void XtApplication::SetQuitHandler(QuitCallback cb_quit = 0)
////////////////////////////////////////////////////////////
{
    ptr_quit = cb_quit;
}


///////////////////////////////////////////////////////////////////////////
void XtApplication::quit(Widget w, XEvent *e, char** s , unsigned int* c)
///////////////////////////////////////////////////////////////////////////
{
    if( 0 != ptr_quit )
    {
        if(e->type == ClientMessage && e->xclient.data.l[0] == wm_delete_window)
        {
            ptr_quit();
        }
    }
}




//////////////////////////
void XtApplication::Run() 
//////////////////////////
{
    XtRealizeWidget(appWidget);

    MakeQuitHandler(appWidget);

    Loop();
}


//////////////////////////////////////////////
void XtApplication::MakeQuitHandler(Widget w)
//////////////////////////////////////////////
{
    XtActionsRec actions[] = {"quit", quit};

    XtAppAddActions(appContext, actions, XtNumber(actions) );
    
    XtOverrideTranslations(w, XtParseTranslationTable("<Message>WM_PROTOCOLS: quit()\n") );

    wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
    
    XSetWMProtocols(display, XtWindow(w), &wm_delete_window, 1);
}


/////////////////////////////////////
void XtApplication::CenterOfScreen()
// Center of screen
// Const size max and min
/////////////////////////////////////
{
    const Dimension mainX = (Display_Width() - mainWidth) / 2;
    const Dimension mainY = (Display_Height() - mainHeight) / 2;

    Arg args[8] = {
        {XtNx, (XtArgVal)mainX},
        {XtNy, (XtArgVal)mainY},
        {XtNwidth, (XtArgVal)mainWidth},
        {XtNheight, (XtArgVal)mainHeight},
        {XtNmaxWidth, (XtArgVal)mainWidth},
        {XtNmaxHeight, (XtArgVal)mainHeight},
        {XtNminWidth, (XtArgVal)mainWidth},
        {XtNminHeight, (XtArgVal)mainHeight},
    };

    XtSetValues(appWidget,args, XtNumber(args) );
}


////////////////////////////////////////////////////
inline const Dimension XtApplication::Width() const  
////////////////////////////////////////////////////
{ 
    return mainWidth; 
}


/////////////////////////////////////////////////////
inline const Dimension XtApplication::Height() const 
/////////////////////////////////////////////////////
{ 
    return mainHeight; 
}

/////////////////////////////////
inline int XtApplication::Root_Window() const 
/////////////////////////////////
{ 
    return RootWindow(display, screen); 
} 


/////////////////////////////////////////
inline const int XtApplication::Display_Width() const 
/////////////////////////////////////////
{ 
    return XDisplayWidth(display, screen); 
}


//////////////////////////////////////////
inline const int XtApplication::Display_Height() const 
//////////////////////////////////////////
{ 
    return XDisplayHeight(display, screen); 
}


///////////////////////////////////////////
inline unsigned long XtApplication::White_Pixel() const 
///////////////////////////////////////////
{ 
    return WhitePixel(display, screen); 
}



///////////////////////////////////////////
inline unsigned long XtApplication::Black_Pixel() const 
///////////////////////////////////////////
{ 
    return BlackPixel(display, screen); 
}



///////////////////////////////////////////
inline Colormap XtApplication::Default_Colormap() const 
///////////////////////////////////////////
{ 
    return XDefaultColormap(display, screen); 
}


///////////////////////////////////
inline int XtApplication::Display_Cells() const 
///////////////////////////////////
{ 
    return XDisplayCells(display, screen); 
}



///////////////////////////////////
inline int XtApplication::Default_Depth() const 
///////////////////////////////////
{ 
    return XDefaultDepth(display, screen); 
}



////////////////////////////////////////
inline Visual* XtApplication::Default_Visual() const 
////////////////////////////////////////
{ 
    return XDefaultVisual(display, screen); 
}


//////////////////////////////////
inline int XtApplication::Screen_Count() const 
//////////////////////////////////
{ 
    return XScreenCount(display); 
} 


///////////////////////////
inline void XtApplication::Loop() const
///////////////////////////
{
    XtAppMainLoop(appContext);
}

