/***************************************************************
 * Name:      wxSMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-02
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXSMAIN_H
#define WXSMAIN_H

//(*Headers(wxSFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
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
        void OnShowDate(wxCommandEvent& event);
        void OnShowVersion(wxCommandEvent& event);
        void OnMousePush(wxMouseEvent& event);
        //*)

        //(*Identifiers(wxSFrame)
        static const long ID_SHOW_DATE;
        static const long ID_SHOW_VERSION;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxSFrame)
        wxMenuItem* MenuItem1;
        wxMenuItem* miData;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXSMAIN_H
