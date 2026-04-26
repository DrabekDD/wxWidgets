/***************************************************************
 * Name:      wxSgrafEuklidesMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-04-26
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXSGRAFEUKLIDESMAIN_H
#define WXSGRAFEUKLIDESMAIN_H

//(*Headers(wxSgrafEuklidesFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class wxSgrafEuklidesFrame: public wxFrame
{
    public:

        wxSgrafEuklidesFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxSgrafEuklidesFrame();

    private:

        //(*Handlers(wxSgrafEuklidesFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbntNWDClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxSgrafEuklidesFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXM;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTN;
        static const long ID_BTNNWD;
        static const long ID_TEXEUK;
        static const long ID_LBLNWD;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(wxSgrafEuklidesFrame)
        wxButton* bntNWD;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* lblNWD;
        wxTextCtrl* txtEuk;
        wxTextCtrl* txtM;
        wxTextCtrl* txtN;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXSGRAFEUKLIDESMAIN_H
