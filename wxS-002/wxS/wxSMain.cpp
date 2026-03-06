/***************************************************************
 * Name:      wxSMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-01
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSMain.h"
#include <wx/msgdlg.h>
#include "global_kbd_event.h"

//(*InternalHeaders(wxSFrame)
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
const long wxSFrame::ID_PANEL1 = wxNewId();
const long wxSFrame::ID_SHOW_DATE = wxNewId();
const long wxSFrame::ID_SHOW_SYS_VERSION = wxNewId();
const long wxSFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxSFrame,wxFrame)
    //(*EventTable(wxSFrame)
    //*)
    //EVT_CHAR_HOOK(wxSFrame::OnKeyPress)
END_EVENT_TABLE()

wxSFrame::wxSFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxSFrame)
    wxMenu* mInfo;
    wxMenuBar* MenuBar1;

    Create(parent, wxID_ANY, _("Uzycie zdarzen"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(810,450));
    panel1 = new wxPanel(this, ID_PANEL1, wxPoint(600,208), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    panel1->SetFocus();
    MenuBar1 = new wxMenuBar();
    mInfo = new wxMenu();
    MenuItem3 = new wxMenuItem(mInfo, ID_SHOW_DATE, _("Pokaz date"), wxEmptyString, wxITEM_CHECK);
    mInfo->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(mInfo, ID_SHOW_SYS_VERSION, _("Pokaz wersje systemu"), wxEmptyString, wxITEM_NORMAL);
    mInfo->Append(MenuItem1);
    MenuBar1->Append(mInfo, _("&Informacje"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[3] = { -1, -10, -10 };
    int __wxStatusBarStyles_1[3] = { wxSB_RAISED, wxSB_RAISED, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(3,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(3,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    panel1->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&wxSFrame::OnKeyPress,0,this);
    panel1->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&wxSFrame::OnMouseClick,0,this);
    panel1->Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&wxSFrame::OnMouseClick,0,this);
    panel1->Connect(wxEVT_MOTION,(wxObjectEventFunction)&wxSFrame::OnMouseMove,0,this);
    Connect(ID_SHOW_DATE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSFrame::OnShowDate);
    Connect(ID_SHOW_SYS_VERSION,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxSFrame::OnShowSysVersion);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&wxSFrame::OnClose);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&wxSFrame::OnResize);
    //*)
    //Connect(wxID_ANY, wxEVT_KEY_DOWN, (wxObjectEventFunction)&wxSFrame::OnKeyPress);
    //Bind(wxEVT_CHAR_HOOK, &wxSFrame::OnKeyPress, this);
    //Bind(wxEVT_KEY_DOWN, &wxSFrame::OnKeyPress, this);
    GlobalKeyEvtHandler::Register(this);
    Bind(wxEVT_KEY_DOWN, &wxSFrame::OnKeyPress, this);
    SetStatusText("Licznik: 0", 0);

    //poprawki nazw polskich
    SetTitle(wxString::FromUTF8("Użycie zdarzeń"));
    mInfo->SetLabel(ID_SHOW_DATE, wxT("Pokaż &datę\tCtrl-D"));
    mInfo->SetLabel(ID_SHOW_SYS_VERSION, wxT("Pokaż &wersję systemu\tCtrl-W"));


    //parametry paska stanu
    int myWidths[3] = {-3, -2, -2 };
    StatusBar1->SetFieldsCount(3, myWidths);
    //SetStatusText(GetTitle(), 0);
    wxSize s = GetSize();
    SetStatusText(wxString::Format("Size: %dx%d", s.GetWidth(), s.GetHeight()), 2);

    panel1->SetFocus();
    Raise();
}

wxSFrame::~wxSFrame()
{
    //(*Destroy(wxSFrame)
    //*)
    Unbind(wxEVT_KEY_DOWN, &wxSFrame::OnKeyPress, this);
    GlobalKeyEvtHandler::Unregister(this);
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

void wxSFrame::OnShowDate(wxCommandEvent& event)
{
  bool status = event.IsChecked();
  if(status){
    this->SetStatusText(wxDateTime::Now().FormatISODate(), 1);
  }else{
    this->SetStatusText(wxEmptyString, 1);
  }
}



void wxSFrame::OnShowSysVersion(wxCommandEvent& event)
{
  wxString system_vers = wxPlatformInfo::Get().GetOperatingSystemDescription();
  wxMessageBox(system_vers, wxT("Informacja o systemie"), wxOK|wxICON_INFORMATION);
}

/*
void wxSFrame::OnAbout(wxCommandEvent& event)
{
  wxMessageBox(wxT("Copyright (c) 2015 by ..."), wxT("O programie..."), wxOK|wxICON_INFORMATION);
  event.Skip();
}
*/

void wxSFrame::OnMouseMove(wxMouseEvent& event)
{
    if (!GetMenuBar()->IsChecked(ID_SHOW_DATE))
        SetStatusText(wxString::Format("Kursor: %d, %d", event.GetX(), event.GetY()), 1);

}

void wxSFrame::OnMouseClick(wxMouseEvent& event)
{
    wxString key;

    if (event.LeftUp())
        key = "Lewy - klikk";
    else if (event.RightUp())
        key = "Prawy - klik";
    else
    return;

    wxMessageBox(
        wxString::Format("Przycisk: %s\nPozycja: %d, %d", key, event.GetX(), event.GetY()), "Informacja");
}

void wxSFrame::OnClose(wxCloseEvent& event)
{
     event.Skip();
}

void wxSFrame::OnKeyPress(wxKeyEvent& event)
{
    int key = event.GetKeyCode();

    if (key == WXK_LEFT)       licznik--;
    else if (key == WXK_RIGHT) licznik++;
    else if (key == 'R' || key == 'r') licznik = 0;
    else if (key == WXK_ESCAPE) { Close(); return; }
    else { event.Skip(); return; }

    SetStatusText(wxString::Format("Licznik: %d", licznik), 0);
}



void wxSFrame::OnResize(wxSizeEvent& event)
{
    wxSize s = event.GetSize();
    SetStatusText(wxString::Format("Rozmiar: %d, %d", s.GetWidth(), s.GetHeight()), 2);
    event.Skip();
}








