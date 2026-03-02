/***************************************************************
 * Name:      dddddMain.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef DDDDDMAIN_H
#define DDDDDMAIN_H

//(*Headers(dddddFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class dddddFrame: public wxFrame
{
    public:

        dddddFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~dddddFrame();

    private:

        //(*Handlers(dddddFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(dddddFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(dddddFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DDDDDMAIN_H
