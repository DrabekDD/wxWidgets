/***************************************************************
 * Name:      wxSMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2026-02-28
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef WXSMAIN_H
#define WXSMAIN_H

//(*Headers(wxSDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class wxSDialog: public wxDialog
{
    public:

        wxSDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxSDialog();

    private:

        //(*Handlers(wxSDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxSDialog)
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_STATICLINE1;
        static const wxWindowID ID_BUTTON2;
        //*)

        //(*Declarations(wxSDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXSMAIN_H
