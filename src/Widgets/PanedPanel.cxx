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
#include "PanedPanel.hpp"

//////////////////////////////////////////////////////////
PanedPanel::PanedPanel(
        const char*  _name, 
        const Dimension _width, 
        const  Dimension _height
        ) : name(_name), width(_width), height(_height)
//////////////////////////////////////////////////////////
{

}


//////////////////////////
PanedPanel::~PanedPanel()
//////////////////////////
{

}


////////////////////////////////////////////
void PanedPanel::Create(const Widget parent)
////////////////////////////////////////////
{
    widget = XtVaCreateManagedWidget(name,
                              panedWidgetClass,
                              parent,
                              XtNwidth, width,
                              XtNheight, height,
                              NULL);
    
    childs.create(widget);
}


//////////////////////////////////////////////////
void PanedPanel::AddChild(const IWidget& iwidget)
//////////////////////////////////////////////////
{
    childs.add(iwidget);
}

