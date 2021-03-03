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

#ifndef XTAPPLICATION_HPP
#define XTAPPLICATION_HPP
#include "IWidget.hpp"

typedef void (*QuitCallback)();

class XtApplication
{
    protected:
        
        XtApplication(
                const char*  app_name,
                int argc, 
                char** argv,  
                const char*  app_resources[],
                const Dimension width, 
                const Dimension height
                );

        virtual ~XtApplication();
        void Run();
        void CenterOfScreen();
        const Dimension Width() const;
        const Dimension Height() const;
        static void SetQuitHandler(QuitCallback cb_quit);
        
        Widget       appWidget;
    
    private:

        static Atom wm_delete_window;
        static QuitCallback ptr_quit;
        const Dimension mainWidth;
        const Dimension mainHeight;
        XtAppContext appContext;
        Display* display;
        int screen;

        XtApplication(const XtApplication&) = delete;
        XtApplication operator=(const XtApplication&) = delete;
        void MakeQuitHandler(Widget);
        static void quit(Widget, XEvent*, char**, unsigned int*);
        int Root_Window() const ;
        const int Display_Width() const;
        const int Display_Height() const;
        unsigned long White_Pixel() const;
        unsigned long Black_Pixel() const;
        Colormap Default_Colormap() const;
        int Display_Cells() const;
        int Default_Depth() const;
        Visual* Default_Visual() const;
        int Screen_Count() const;
        void Loop() const; 
};
#endif
