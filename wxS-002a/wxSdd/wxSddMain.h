/***************************************************************
 * Name:      wxSddMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXSDDMAIN_H
#define WXSDDMAIN_H

//(*Headers(wxSddFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class wxSddFrame: public wxFrame
{
    public:

        wxSddFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxSddFrame();

    private:

        //(*Handlers(wxSddFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxSddFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxSddFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXSDDMAIN_H
