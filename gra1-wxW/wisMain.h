/***************************************************************
 * Name:      wisMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-18
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WISMAIN_H
#define WISMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wisApp.h"

class wisFrame: public wxFrame
{
    public:
        wisFrame(wxFrame *frame, const wxString& title);
        ~wisFrame();
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


#endif // WISMAIN_H
