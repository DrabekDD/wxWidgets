/***************************************************************
 * Name:      wxsMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXSMAIN_H
#define WXSMAIN_H

//(*Headers(wxsFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class wxsFrame: public wxFrame
{
    public:

        wxsFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxsFrame();

    private:

        //(*Handlers(wxsFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxsFrame)
        static const long miData;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxsFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXSMAIN_H
