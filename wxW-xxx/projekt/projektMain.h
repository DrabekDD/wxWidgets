/***************************************************************
 * Name:      projektMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-10
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef PROJEKTMAIN_H
#define PROJEKTMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "projektApp.h"

class projektFrame: public wxFrame
{
    public:
        projektFrame(wxFrame *frame, const wxString& title);
        ~projektFrame();
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


#endif // PROJEKTMAIN_H
