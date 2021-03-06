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

#include "Grip.hpp"

///////////////////////////////////////////
Grip::Grip(
        const char*  _name 
        ) : name(_name)
///////////////////////////////////////////
{

}

/////////////////
Grip::~Grip() 
/////////////////
{ 

}


/////////////////////////////////////////
void Grip::Create(const Widget parent)
/////////////////////////////////////////
{
    widget = XtVaCreateManagedWidget(name,
                              portholeWidgetClass,
                              parent,
                              NULL);

    childs.create(widget);

    //SetText(text);
}

//////////////////////////////////////////////////////
void Grip::AddChild(const IWidget& iwidget) 
//////////////////////////////////////////////////////
{
    childs.add(iwidget);
}
