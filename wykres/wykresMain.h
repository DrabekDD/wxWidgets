/***************************************************************
 * Name:      wykresMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-05-17
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WYKRESMAIN_H
#define WYKRESMAIN_H

//(*Headers(wykresFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
//*)

class wykresFrame: public wxFrame
{
    public:

        wykresFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wykresFrame();

    private:

        //(*Handlers(wykresFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanelPaint(wxPaintEvent& event);
        void OnSin(wxCommandEvent& event);
        void OnCos(wxCommandEvent& event);
        void OnTg(wxCommandEvent& event);
        void OnCtg(wxCommandEvent& event);
        //*)

        //(*Identifiers(wykresFrame)
        static const long ID_PANEL;
        static const long ID_SIN;
        static const long ID_COS;
        static const long ID_TG;
        static const long ID_CTG;
        //*)

        //(*Declarations(wykresFrame)
        wxMenuItem* Menu1;
        wxMenuItem* MenuItem1;
        wxMenuItem* MenuItem2;
        wxMenuItem* MenuItem3;
        wxPanel* Panel;
        //*)
        int funkcja;

        DECLARE_EVENT_TABLE()
};

#endif // WYKRESMAIN_H
