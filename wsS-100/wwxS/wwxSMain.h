/***************************************************************
 * Name:      wwxSMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-04
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WWXSMAIN_H
#define WWXSMAIN_H

//(*Headers(wwxSFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class wwxSFrame: public wxFrame
{
    public:

        wwxSFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wwxSFrame();

    private:

        //(*Handlers(wwxSFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnShowDate(wxCommandEvent& event);
        void OnShowVersion(wxCommandEvent& event);
        void OnUseMouse(wxMouseEvent& event);
        //*)

        //(*Identifiers(wwxSFrame)
        static const long ID_SHOW_DATE;
        static const long ID_SHOW_VERSION;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wwxSFrame)
        wxMenuItem* miData;
        wxMenuItem* miWersja;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WWXSMAIN_H
