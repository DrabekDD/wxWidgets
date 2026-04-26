/***************************************************************
 * Name:      aaaMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-25
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef AAAMAIN_H
#define AAAMAIN_H

//(*Headers(aaaFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class aaaFrame: public wxFrame
{
    public:

        aaaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~aaaFrame();

    private:

        //(*Handlers(aaaFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(aaaFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(aaaFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // AAAMAIN_H
