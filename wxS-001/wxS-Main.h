/***************************************************************
 * Name:      wxS001Main.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-25
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXS001MAIN_H
#define WXS001MAIN_H

//(*Headers(wxS001Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
//*)

class wxS001Frame: public wxFrame
{
    public:

        wxS001Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxS001Frame();

    private:

        //(*Handlers(wxS001Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OntbStartClicked(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxS001Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR;
        static const long ID_TBSTART;
        static const long wxID_TB;
        //*)

        //(*Declarations(wxS001Frame)
        wxStatusBar* StatusBar;
        wxToolBarToolBase* tbStart;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXS001MAIN_H
