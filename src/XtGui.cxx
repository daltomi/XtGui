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
#include "XtGui.hpp"

const char* XtGui::appResources[] = {
        "*.background: Gray",              // all class
        "*.foreground: Black",             // all class
        "*Label.borderWidth:0",            // class type Label
        "*Command.background : Gray80",    // class type Command
        "*.menuPanel.background: #6495ED", // obj here
        "*MenuButton.background: #6495ED", // class type (menu)
        "*MenuButton.borderWidth: 0",      // idem  ^
        "*SimpleMenu.background: #6495ED", // class type (sub-menu)
        "*SimpleMenu.borderColor: Black",  // idem  ^
        NULL
};


///////////////////////////////////////////////////////////////////////////////////////
XtGui::XtGui(const char* _name, 
             int argc, 
             char** argv, 
             const Dimension _w, 
             const Dimension _h) : XtApplication(_name, argc, argv, appResources, _w, _h),
                                   form("mainForm"),
                                   paned("mainPaned", _w, _h),
                                   body("programBox"),
                                   menuPanel("menuPanel")
///////////////////////////////////////////////////////////////////////////////////////
{

    form.AddChild(paned);      // layer
    paned.AddChild(menuPanel); // menu
    paned.AddChild(body);      // body
    AddChild(form);            // finally, all to application
}


///////////////
XtGui::~XtGui()
///////////////
{

}



/////////////////////////////////////////////////////////////////////////////
void XtGui::Message(const char* title, const char* label, const char* button)
/////////////////////////////////////////////////////////////////////////////
{
    message = new MessageBox(title, label, button, appWidget);
    delete message;
}



//////////////////////////////////
void XtGui::Run(QuitCallback _cb)
//////////////////////////////////
{
    SetQuitHandler(_cb);
    
    CreateXtGui();

    XtApplication::Run();
}


///////////////////////////////////////////////
inline void XtGui::AddChild(const IWidget& iw)
///////////////////////////////////////////////
{
    childs.add(iw);
}


/////////////////////////////////
inline void XtGui::CreateXtGui() 
/////////////////////////////////
{
    childs.create(appWidget);
}


//////////////////////////////////////
void XtGui::AddMenu(const char* _name)
//////////////////////////////////////
{
    menu = menuPanel.AddItem(_name);
}


////////////////////////////////////////////////////////////////////
void XtGui::AddSubMenu(const char* _name, Callback _cb=0) const
////////////////////////////////////////////////////////////////////
{
    menu->AddItem(_name, _cb);
}



////////////////////////////////
void XtGui::AddLineMenu() const
////////////////////////////////
{
    menu->AddLine();
}



///////////////////////////////////////////////
void XtGui::Attach(const IWidget& child) 
///////////////////////////////////////////////
{
    body.AddChild(child);
}

