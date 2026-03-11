#include "wxW_Main.h"
#include <wx/artprov.h>

MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
        : wxFrame(parent, id, title, pos, size, style)
{
    CreateMainMenu();
    CreateMainToolBar();
    CreateMainStatusBar();
    BindEvents();
    // stałe pola statusbara
    SetStatusText(GetTitle(), 0);
    SetStatusText(wxString::Format("style=%ld", style), 3);
    UpdateStatusBarGeometry();
    CenterOnScreen();
}

void MyFrame::CreateMainMenu()
{
    mb = new wxMenuBar();
    mFile = new wxMenu();
    mHelp = new wxMenu();
    mFile->AppendCheckItem(ID_SHOW_DATE, wxT("Pokaż &datę\tCtrl-D"), wxT("Wyświetla bieżącą datę"));
    mFile->Append(ID_SHOW_OS, wxT("Pokaż &wersję systemu\tCtrl-W"), wxT("Wyświetla opis systemu"));
    mFile->AppendSeparator();
    mFile->Append(ID_EXIT, wxT("&Zamknij program\tCtrl-X"), wxT("Zamyka program"));
    mHelp->Append(ID_ABOUT, wxT("&O programie\tCtrl-H"), wxT("Informacje o programie"));
    mb->Append(mFile, wxT("&Plik"));
    mb->Append(mHelp, wxT("P&omoc"));
    SetMenuBar(mb);
}

void MyFrame::CreateMainToolBar()
{
    tb = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL, "MainToolbar");
    const wxSize bmpSize(24, 24);
    tb->SetToolBitmapSize(bmpSize);
    tb->AddTool(ID_TOOL_NEW,  "Nowy",   wxArtProvider::GetBitmap(wxART_NEW,       wxART_TOOLBAR, bmpSize), "Nowy");
    tb->AddTool(ID_TOOL_OPEN, "Otwórz", wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR, bmpSize), "Otwórz");
    tb->AddTool(ID_TOOL_SAVE, "Zapisz", wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR, bmpSize), "Zapisz");
    tb->AddSeparator();
    tb->AddTool(ID_ABOUT,     "Pomoc",  wxArtProvider::GetBitmap(wxART_HELP,      wxART_TOOLBAR, bmpSize), "O programie");
    tb->Realize();
    SetToolBar(tb);
}

void MyFrame::CreateMainStatusBar()
{
    sb = new wxStatusBar(this);
    int widths[4] = { 300, -1, -2, 240 };
    sb->SetFieldsCount(4, widths);
    int st[4] = { wxSB_NORMAL, wxSB_SUNKEN, wxSB_SUNKEN, wxSB_SUNKEN };
    sb->SetStatusStyles(4, st);
    SetStatusBar(sb);
}

void MyFrame::BindEvents()
{
    // Menu
    Bind(wxEVT_MENU, &MyFrame::OnShowDate, this, ID_SHOW_DATE);
    Bind(wxEVT_MENU, &MyFrame::OnShowOS,   this, ID_SHOW_OS);
    Bind(wxEVT_MENU, &MyFrame::OnExit,     this, ID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnAbout,    this, ID_ABOUT);
    // Toolbar: mapujemy do istniejących komend (tu na razie tylko przykładowo)
    Bind(wxEVT_TOOL, &MyFrame::OnAbout, this, ID_ABOUT);
    // Aktualizacja statusbara przy zmianie geometrii okna
    Bind(wxEVT_MOVE, &MyFrame::OnMove, this);
    Bind(wxEVT_SIZE, &MyFrame::OnSize, this);
}

void MyFrame::UpdateStatusBarGeometry()
{
    if (!sb) return;
    const wxPoint p = GetPosition();
    SetStatusText(wxString::Format("Pos: %d,%d", p.x, p.y), 1);
    const wxSize s = GetSize();
    SetStatusText(wxString::Format("Size: %dx%d", s.GetWidth(), s.GetHeight()), 2);
}

void MyFrame::OnShowDate(wxCommandEvent& event)
{
    const wxString dateStr = wxDateTime::Now().FormatISODate(); // YYYY-MM-DD
    wxMessageBox("Dzisiaj: " + dateStr, "Data", wxOK | wxICON_INFORMATION, this);
    event.Skip(false);
}

void MyFrame::OnShowOS(wxCommandEvent& event)
{
    const wxString os = wxGetOsDescription();
    wxMessageBox("System: " + os, "Wersja systemu", wxOK | wxICON_INFORMATION, this);
    event.Skip(false);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
    event.Skip(false);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("wxW-007\nPrzykład: menu + toolbar + statusbar + eventy","O programie", wxOK | wxICON_INFORMATION, this);
    event.Skip(false);
}

void MyFrame::OnMove(wxMoveEvent& event)
{
    UpdateStatusBarGeometry();
    event.Skip(); // pozwól wxWidgets obsłużyć zdarzenie dalej
}

void MyFrame::OnSize(wxSizeEvent& event)
{
    UpdateStatusBarGeometry();
    event.Skip(); // ważne, żeby layout działał poprawnie
}


