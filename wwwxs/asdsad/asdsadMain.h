/***************************************************************
 * Name:      asdsadMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef ASDSADMAIN_H
#define ASDSADMAIN_H

//(*Headers(asdsadFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class asdsadFrame: public wxFrame
{
    public:

        asdsadFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~asdsadFrame();

    private:

        //(*Handlers(asdsadFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(asdsadFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(asdsadFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ASDSADMAIN_H
