/***************************************************************
 * Name:      test11Main.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-04-29
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef TEST11MAIN_H
#define TEST11MAIN_H

//(*Headers(test11Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class test11Frame: public wxFrame
{
    public:

        test11Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~test11Frame();

    private:

        //(*Handlers(test11Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(test11Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(test11Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TEST11MAIN_H
