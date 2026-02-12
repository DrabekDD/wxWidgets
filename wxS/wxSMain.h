/***************************************************************
 * Name:      wxSMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-13
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXSMAIN_H
#define WXSMAIN_H

//(*Headers(wxSFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/scrolwin.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
//*)

class wxSFrame: public wxFrame
{
    public:

        wxSFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxSFrame();

    private:

        //(*Handlers(wxSFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxSFrame)
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TOOLBARITEM1;
        static const long ID_TOOLBAR1;
        //*)

        //(*Declarations(wxSFrame)
        wxMenu Menu4;
        wxMenu* Menu3;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxScrolledWindow* ScrolledWindow1;
        wxStatusBar* StatusBar1;
        wxToolBar* ToolBar1;
        wxToolBarToolBase* ToolBarItem1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXSMAIN_H
