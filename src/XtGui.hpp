/* 
XtGui -  Copyright (©) 2012,2021 daltomi <daltomi@disroot.org>

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

#ifndef XTGUI_HPP
#define XTGUI_HPP

#include "Widgets/XtApplication.hpp"
#include "Widgets/PanedPanel.hpp"
#include "Widgets/BoxPanel.hpp"
#include "Widgets/Menu/MenuPanel.hpp"
#include "Widgets/FormPanel.hpp"
#include "Widgets/MessageBox.hpp"

#include "Widgets/Components.hpp"

class XtGui : protected XtApplication
{
    public:
        explicit XtGui(const char*, int, char**, const Dimension, const Dimension);
        virtual ~XtGui();

        void Run(QuitCallback);
        void Message(const char*, const char*, const char*);
        void AddMenu(const char*);
        void AddSubMenu(const char*, Callback) const;
        void AddLineMenu() const;
        void Attach(const IWidget&); 


    private:
        XtGui(const XtGui&) = delete;
        XtGui operator=(const XtGui&) = delete;
        
        static const char* appResources[];
        FormPanel  form; 
        PanedPanel paned;
        BoxPanel   body;
        MenuPanel  menuPanel;
        Menu*      menu;
        MessageBox* message;
        Components childs;

        void AddChild(const IWidget&);
        void CreateXtGui();
};
#endif

