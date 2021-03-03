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

#include "MessageBox.hpp"

Widget MessageBox::pshell_w ;

/////////////////////////////////////////////////////
MessageBox::MessageBox(
        const char* _title,
        const char* _label, 
        const char* _label_button,
        const Widget _parent
        ) 
/////////////////////////////////////////////////////
{
    pshell_w  = XtVaCreatePopupShell(_title,
                                transientShellWidgetClass,
                                _parent,
                                NULL);


    Widget dialog_w = XtVaCreateManagedWidget("MessageBoxClass",
                                   dialogWidgetClass,
                                   pshell_w,
                                   NULL);

    Widget label_w = XtNameToWidget(dialog_w, "label");

    if( 0 != label_w )
    {
        Arg arg[1];
        XtSetArg(arg[0], XtNlabel, _label);
        XtSetValues(label_w, arg, 1);
    }

    Widget button_w = XtVaCreateManagedWidget(_label_button,
                                   commandWidgetClass,
                                   dialog_w,
                                   NULL);

    XtAddCallback(button_w, XtNcallback, cb_done, NULL);

    XtPopup(pshell_w , XtGrabNonexclusive);
}


//////////////////////////
MessageBox::~MessageBox()
//////////////////////////
{

}



///////////////////////////////////////////////////////////////////////////
void MessageBox::cb_done(Widget parent, XtPointer unused1, XtPointer data)
///////////////////////////////////////////////////////////////////////////
{
    XtPopdown(pshell_w );
    XtDestroyWidget(pshell_w );
}



