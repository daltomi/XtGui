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
#ifndef MENU_HPP 
#define MENU_HPP

#include "../IWidget.hpp"
#include <X11/Xaw/MenuButton.h>
#include <X11/Xaw/SimpleMenu.h>
#include <X11/Xaw/Sme.h>
#include <X11/Xaw/SmeBSB.h>
#include <X11/Xaw/SmeLine.h>
#include "../Components.hpp"

#include <string>
using std::string;

//typedef void (*MenuCallback)(Widget,XtPointer,XtPointer);

class ItemMenu : public IWidget
{
    public:

        ItemMenu(const char* ,Callback);
        virtual ~ItemMenu();
        void Create(const Widget);

    private:

        const char*  name;
        Callback cb_pointer;
};


class LineMenu : public IWidget
{
    public:

        LineMenu();
        virtual ~LineMenu();
        void Create(const Widget);
};

class SubMenu : public IWidget
{
    public:
        SubMenu(const char* );
        virtual ~SubMenu();
        void Create(const Widget);
        void AddChild(const IWidget&);
        string name;

    private:
        Components childs;
};


class Menu :  public IWidget 
{
    public:

        Menu(const char* );
        virtual ~Menu();
        void Create(const Widget);

        void AddItem(const char* , Callback );
        void AddLine();

    private:

        const char*  name;
        SubMenu subMenu;
};

#endif

