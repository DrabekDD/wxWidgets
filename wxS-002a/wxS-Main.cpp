/***************************************************************
 * Name:      wxS001Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-25
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxS-Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxS001Frame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
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

//(*IdInit(wxS001Frame)
const long wxS001Frame::idMenuQuit = wxNewId();
const long wxS001Frame::idMenuAbout = wxNewId();
const long wxS001Frame::ID_STATUSBAR = wxNewId();
const long wxS001Frame::ID_TBSTART = wxNewId();
const long wxS001Frame::wxID_TB = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxS001Frame,wxFrame)
    //(*EventTable(wxS001Frame)
    //*)
END_EVENT_TABLE()

wxS001Frame::wxS001Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxS001Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* mb;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxToolBar* tb;

    Create(parent, id, _("OKNO - projekt"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxVSCROLL|wxHSCROLL, _T("id"));
    SetClientSize(wxSize(800,300));
    SetFocus();
    SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
    wxFont thisFont(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    mb = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_CHECK);
    Menu1->Append(MenuItem1);
    mb->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_RADIO);
    Menu2->Append(MenuItem2);
    mb->Append(Menu2, _("Help"));
    SetMenuBar(mb);
    StatusBar = new wxStatusBar(this, ID_STATUSBAR, wxBORDER_DOUBLE, _T("ID_STATUSBAR"));
    int __wxStatusBarWidths_1[3] = { -3, -2, -1 };
    int __wxStatusBarStyles_1[3] = { wxSB_RAISED, wxSB_RAISED, wxSB_RAISED };
    StatusBar->SetFieldsCount(3,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(3,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);
    ///////////////////////////////////////// TO TU WPISUJEMY MY
        int myWidths[3] = {-3, -2, -1 };
        StatusBar->SetFieldsCount(3, myWidths);
        SetStatusText(GetTitle(), 0);
        wxSize s = GetSize();
        SetStatusText(wxString::Format("Size: %dx%d", s.GetWidth(), s.GetHeight()), 1);
        SetStatusText("DeDe", 2);
    ///////////////////////////////////////// TO TU WPISUJEMY MY
    tb = new wxToolBar(this, wxID_TB, wxDefaultPosition, wxDefaultSize, wxTB_VERTICAL|wxTB_HORIZONTAL|wxTB_RIGHT, _T("wxID_TB"));
    tbStart = tb->AddTool(ID_TBSTART, _("Start"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_QUIT")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    tb->Realize();
    SetToolBar(tb);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxS001Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxS001Frame::OnAbout);
    Connect(ID_TBSTART,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&wxS001Frame::OntbStartClicked);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&wxS001Frame::OnClose);
    //*)




}

wxS001Frame::~wxS001Frame()
{
    //(*Destroy(wxS001Frame)
    //*)
}

void wxS001Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxS001Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Serdecznie witam..."));
}

void wxS001Frame::OnClose(wxCloseEvent& event)
{
        event.Skip();
}

void wxS001Frame::OntbStartClicked(wxCommandEvent& event)
{
    Close(true);
}
