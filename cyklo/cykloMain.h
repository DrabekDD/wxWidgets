/***************************************************************
 * Name:      cykloMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-05-14
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef CYKLOMAIN_H
#define CYKLOMAIN_H

//(*Headers(cykloFrame)
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/timer.h>
//*)

class cykloFrame: public wxFrame
{
    public:

        cykloFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~cykloFrame();

    private:

        //(*Handlers(cykloFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanelPaint(wxPaintEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnTimerTrigger(wxTimerEvent& event);
        void OnChoiceCykloSelect(wxCommandEvent& event);
        //*)

        //(*Identifiers(cykloFrame)
        static const long ID_CHOICE_CYKLO;
        static const long ID_PANEL;
        static const long ID_TIMER_CYKLO;
        //*)

        //(*Declarations(cykloFrame)
        wxChoice* ChoiceCyklo;
        wxPanel* Panel;
        wxTimer TimerCyklo;
        //*)
        void DrawCyklo(wxDC& dc, int type, wxColour color);
        double currentT = 0;

        DECLARE_EVENT_TABLE()
};

#endif // CYKLOMAIN_H
