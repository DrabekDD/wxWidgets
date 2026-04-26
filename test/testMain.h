/***************************************************************
 * Name:      testMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-23
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef TESTMAIN_H
#define TESTMAIN_H

//(*Headers(testFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class testFrame: public wxFrame
{
    public:

        testFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~testFrame();

    private:

        //(*Handlers(testFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(testFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(testFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TESTMAIN_H
