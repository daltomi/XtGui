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

#ifndef IWIDGET_HPP
#define IWIDGET_HPP

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h> 


//TODO: for debug only
#include <iostream>
using std::cerr;
using std::endl;

// C++0x-style, make app more big.
//#include <functional>
//using std::function;
//typedef function< void (const char*)> Callback;

// C-style
typedef void (*Callback)(const char*);


/*
 *  Interface
 */
class IWidget
{
    public:

        virtual ~IWidget();
        virtual void Create(const Widget);
        Widget operator()() const;
        void Show() const;
        void Hide() const;
        void SetText(const char*);
   
    protected:
        
        IWidget();
        Widget widget;
        static void WidgetCallback(Widget, XtPointer, XtPointer);
    
    private:

        IWidget(const IWidget&) = delete;
        IWidget& operator=(const IWidget&) = delete;
        
};
#endif
