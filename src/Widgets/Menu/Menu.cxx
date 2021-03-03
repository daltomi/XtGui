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

/****************************************************
This document contains the following classes:

 - Menu Class
 - ItemMenu Class
 - LineMenu Class
 - SubMenu Class

 *****************************************************/

#include "Menu.hpp"


///////////////////////////////////////////////////////
Menu::Menu(const char*  _name) : name(_name), subMenu(_name)
// Menu Class
///////////////////////////////////////////////////////
{

}


//////////////
Menu::~Menu() 
//////////////
{ 

}


///////////////////////////////////////
void Menu::Create(const Widget parent)
///////////////////////////////////////
{
    widget = XtVaCreateManagedWidget(name,
                              menuButtonWidgetClass,
                              parent,
                              XtNmenuName, subMenu.name.c_str(),
                              NULL);

    subMenu.Create(widget);
}



///////////////////////////////////////////////////////////////
void Menu::AddItem(const char*  _name, Callback cb_menu=0)
///////////////////////////////////////////////////////////////
{
    if( 0 != cb_menu )
    {
        subMenu.AddChild( *new ItemMenu(_name, cb_menu) );
    }
}


/////////////////////
void Menu::AddLine()
/////////////////////
{
    subMenu.AddChild( *new LineMenu() ) ;
}


////////////////////////////////////////
ItemMenu::ItemMenu(
        const char*  _name, 
        Callback _cb = 0
        ) : name(_name), cb_pointer(_cb)
// ItemMenu Class
////////////////////////////////////////
{

}


/////////////////////////////////////
void ItemMenu::Create(const Widget parent)
/////////////////////////////////////
{
    widget = XtCreateManagedWidget(name,
                            smeBSBObjectClass,
                            parent,
                            NULL,0);

    if( 0 != cb_pointer)
    {
        XtAddCallback(widget, XtNcallback, WidgetCallback, (XtPointer)cb_pointer );
    }
}



//////////////////////
ItemMenu::~ItemMenu() 
//////////////////////
{ 

}


/////////////////////
LineMenu::LineMenu()
// LineMenu Class
/////////////////////
{

}


//////////////////////
LineMenu::~LineMenu()
//////////////////////
{
}



/////////////////////////////////////
void LineMenu::Create(const Widget parent)
/////////////////////////////////////
{
    widget = XtCreateManagedWidget("lineMenuXtGui",
                            smeLineObjectClass,
                            parent,
                            NULL,0);
}



//////////////////////////////////////////////
SubMenu::SubMenu(const char*  _name)
// SubMenu Class
//////////////////////////////////////////////
{
    const char* menu = "SubMenu";
    name = _name;
    name += menu;
}



////////////////////////////////////
void SubMenu::Create(const Widget parent)
////////////////////////////////////
{
    widget = XtCreatePopupShell(name.c_str(),
                                simpleMenuWidgetClass,
                                parent,
                                NULL,0);


    childs.create(widget);
}



/////////////////////////////////////////
void SubMenu::AddChild(const IWidget& iwidget)
/////////////////////////////////////////
{
    childs.add(iwidget);
}


/////////////////////
SubMenu::~SubMenu()
/////////////////////
{
    childs.release();
}


