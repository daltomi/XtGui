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

#include "IWidget.hpp"

///////////////////////////////
IWidget::IWidget() : widget(0) 
///////////////////////////////
{ 

}

////////////////////
IWidget::~IWidget() 
////////////////////
{ 

}

//////////////////////////////////////////
void IWidget::Create(const Widget unused) 
// UNUSED
//////////////////////////////////////////
{ 

}
        

///////////////////////////////////
Widget IWidget::operator()() const 
///////////////////////////////////
{ 
    return widget; 
} 


///////////////////////////
void IWidget::Show() const
///////////////////////////
{
    XtMapWidget(widget);
}


//////////////////////////
void IWidget::Hide() const
//////////////////////////
{
    XtUnmapWidget(widget);
}


////////////////////////////////////////
void IWidget::SetText(const char* _text)
////////////////////////////////////////
{
    if( widget )
    {
        Arg arg[1];
        XtSetArg(arg[0], XtNlabel, _text);
        XtSetValues(widget,arg,1);
    }
}

///////////////////////////////////////////////////////////////////////////
void IWidget::WidgetCallback(Widget w, XtPointer data=0, XtPointer unused=0)
///////////////////////////////////////////////////////////////////////////
{
    ((Callback)data)(XtName(w));

    // for <function>
    //(*((Callback*)data))(XtName(w));
}
        

