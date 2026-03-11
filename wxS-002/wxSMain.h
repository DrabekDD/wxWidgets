/***************************************************************
 * Name:      wxSMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-01
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXSMAIN_H
#define WXSMAIN_H
#include <wx/gdicmn.h>   //timer


//(*Headers(wxSFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/timer.h>
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
        void OnShowSysVersion(wxCommandEvent& event);
        void OnMouseMove(wxMouseEvent& event);
        void OnLeftUp(wxMouseEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnMouseClick(wxMouseEvent& event);
        void OnLeftDClick(wxMouseEvent& event);
        void OnResize(wxSizeEvent& event);
        void OnKeyDown(wxKeyEvent& event);
        void OnKeyPress(wxKeyEvent& event);
        void Onpanel1Paint(wxPaintEvent& event);
        void OnMouseDclik(wxMouseEvent& event);
        void OnSingleClickTimer(wxTimerEvent& event);
        //*)
        //(*Identifiers(wxSFrame)
        static const long ID_PANEL1;
        static const long ID_SHOW_DATE;
        static const long ID_SHOW_SYS_VERSION;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(wxSFrame)
        wxMenuItem* MenuItem1;
        wxMenuItem* MenuItem3;
        wxPanel* panel1;
        wxStatusBar* StatusBar1;
        wxTimer Timer1;
        //*)

        wxPoint m_clickPos;
        int licznik=0;
        DECLARE_EVENT_TABLE()
};

#endif // WXSMAIN_H
