/***************************************************************
 * Name:      wxSMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-13
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxSFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/image.h>
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

//(*IdInit(wxSFrame)
const long wxSFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long wxSFrame::ID_MENUITEM1 = wxNewId();
const long wxSFrame::ID_MENUITEM2 = wxNewId();
const long wxSFrame::idMenuQuit = wxNewId();
const long wxSFrame::idMenuAbout = wxNewId();
const long wxSFrame::ID_STATUSBAR1 = wxNewId();
const long wxSFrame::ID_TOOLBARITEM1 = wxNewId();
const long wxSFrame::ID_TOOLBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxSFrame,wxFrame)
    //(*EventTable(wxSFrame)
    //*)
END_EVENT_TABLE()

wxSFrame::wxSFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxSFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* mb;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    ScrolledWindow1 = new wxScrolledWindow(this, ID_SCROLLEDWINDOW1, wxPoint(512,112), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    ScrolledWindow1->SetFocus();
    mb = new wxMenuBar();
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("O mnie"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    Menu3->AppendSeparator();
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM2, _("O Tobie"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    mb->Append(Menu3, _("Info"));
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    mb->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    mb->Append(Menu2, _("Help"));
    SetMenuBar(mb);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, wxBORDER_DOUBLE|wxBORDER_SUNKEN, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[4] = { -1, -10, 1, 2 };
    int __wxStatusBarStyles_1[4] = { wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(4,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(4,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(ID_TOOLBARITEM1, _("New item"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FLOPPY")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSFrame::OnAbout);
    //*)
}

wxSFrame::~wxSFrame()
{
    //(*Destroy(wxSFrame)
    //*)
}

void wxSFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxSFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
