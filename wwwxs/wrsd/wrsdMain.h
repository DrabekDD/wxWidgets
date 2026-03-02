/***************************************************************
 * Name:      wrsdMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2026-02-28
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WRSDMAIN_H
#define WRSDMAIN_H

//(*Headers(wrsdFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class wrsdFrame: public wxFrame
{
    public:

        wrsdFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wrsdFrame();

    private:

        //(*Handlers(wrsdFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wrsdFrame)
        static const wxWindowID idMenuQuit;
        static const wxWindowID idMenuAbout;
        static const wxWindowID ID_STATUSBAR1;
        //*)

        //(*Declarations(wrsdFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WRSDMAIN_H
