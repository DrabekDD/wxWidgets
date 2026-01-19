/***************************************************************
 * Name:      wxWMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-01-18
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXWMAIN_H
#define WXWMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wxWApp.h"

class wxWFrame: public wxFrame
{
    public:
        wxWFrame(wxFrame *frame, const wxString& title);
        ~wxWFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // WXWMAIN_H
