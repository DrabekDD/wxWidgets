/***************************************************************
 * Name:      stery0Main.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-26
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef STERY0MAIN_H
#define STERY0MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "stery0App.h"

class stery0Frame: public wxFrame
{
    public:
        stery0Frame(wxFrame *frame, const wxString& title);
        ~stery0Frame();
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


#endif // STERY0MAIN_H
