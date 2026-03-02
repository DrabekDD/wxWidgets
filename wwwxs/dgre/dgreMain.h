/***************************************************************
 * Name:      dgreMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2026-02-28
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef DGREMAIN_H
#define DGREMAIN_H

//(*Headers(dgreFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class dgreFrame: public wxFrame
{
    public:

        dgreFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~dgreFrame();

    private:

        //(*Handlers(dgreFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(dgreFrame)
        static const wxWindowID idMenuQuit;
        static const wxWindowID idMenuAbout;
        static const wxWindowID ID_STATUSBAR1;
        //*)

        //(*Declarations(dgreFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DGREMAIN_H
