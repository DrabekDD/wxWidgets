/***************************************************************
 * Name:      stery01Main.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-26
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef STERY01MAIN_H
#define STERY01MAIN_H

//(*Headers(stery01Frame)
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
//*)

class stery01Frame: public wxFrame
{
    public:

        stery01Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~stery01Frame();

    private:

        //(*Handlers(stery01Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnListCtrl2BeginDrag(wxListEvent& event);
        //*)

        //(*Identifiers(stery01Frame)
        static const long ID_LISTCTRL2;
        static const long ID_LISTBOX1;
        static const long ID_LISTCTRL1;
        //*)

        //(*Declarations(stery01Frame)
        wxListBox* ListBox1;
        wxListCtrl* ListCtrl1;
        wxListCtrl* ListCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // STERY01MAIN_H
