/***************************************************************
 * Name:      wxsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxsMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxsFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxsFrame)
const long wxsFrame::miData = wxNewId();
const long wxsFrame::idMenuAbout = wxNewId();
const long wxsFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxsFrame,wxFrame)
    //(*EventTable(wxsFrame)
    //*)
END_EVENT_TABLE()

wxsFrame::wxsFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxsFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* mb;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    mb = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, miData, _("Pokaż datę\tAlt-F4"), _("wyświetla datę"), wxITEM_CHECK);
    Menu1->Append(MenuItem1);
    mb->Append(Menu1, _("&Info"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    mb->Append(Menu2, _("Help"));
    SetMenuBar(mb);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(miData,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxsFrame::OnAbout);
    //*)
}

wxsFrame::~wxsFrame()
{
    //(*Destroy(wxsFrame)
    //*)
}

void wxsFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxsFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
