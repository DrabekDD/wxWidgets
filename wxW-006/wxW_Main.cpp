#include "wxW_Main.h"


MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
                 const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    // tworzymy poszczególne elementy menu
    mb = new wxMenuBar();
    mFile = new wxMenu();
    mHelp = new wxMenu();
    //                  wxMenuItem(menu_rodzic, identyfikator, tekst wyświetlany, tekst pomocy, rodzaj, submenu);
    // mShowDateTime = new wxMenuItem(NULL, wxID_ANY, wxT("Pokaż datę"), wxT("Data"), wxITEM_CHECK, NULL);
    // mShowSystemVersion = new wxMenuItem(NULL, wxID_ANY, wxT("Pokaż wersję systemu"), wxT("Wersja systemu"), wxITEM_NORMAL, NULL);
    // mClose = new wxMenuItem(NULL, wxID_ANY, wxT("Zamknij program"), wxT("Zamykam program"), wxITEM_NORMAL, NULL);
    // mAboutProgram = new wxMenuItem(NULL, wxID_ANY, wxT("O programie"), wxT("Program"), wxITEM_NORMAL, NULL);

    // struktura menu
    // mFile->Append(mShowDateTime);
    mFile->AppendCheckItem(wxID_ANY, wxT("Pokaż &datę\tCtrl-D"), wxT("Data"));
    //mFile->Append(mShowSystemVersion);
    mFile->Append(wxID_ANY, wxT("Pokaż &wersję systemu\tCtrl-W"), wxT("Wersja systemu"));
    mFile->AppendSeparator();
    // mFile->Append(mClose);
    mFile->Append(wxID_ANY, wxT("&Zamknij program\tCtrl-x"), wxT("Zamykam program"));
    // mHelp->Append(mAboutProgram);
    mHelp->Append(wxID_ANY, wxT("&O programie\tCtrl-H"), wxT("O programie"));
    mb->Append(mFile, wxT("&Plik"));
    mb->Append(mHelp, wxT("P&omoc"));
    //SetMenuBar(mb);
    this->SetMenuBar(mb);


    {sb = new wxStatusBar(this);

    int widths[4] = { 300, -1, -2, 240 };
    sb->SetFieldsCount(4, widths);
    int st[4] = { wxSB_NORMAL, wxSB_SUNKEN, wxSB_SUNKEN, wxSB_SUNKEN };
    sb->SetStatusStyles(4, st);
    sb->SetBackgroundColour(*wxLIGHT_GREY);
    sb->SetForegroundColour(*wxWHITE);

    this->SetStatusBar(sb);

    SetStatusText(GetTitle(), 0);
    wxPoint p = GetPosition();
    SetStatusText(wxString::Format("Pos: %d,%d", p.x, p.y), 1);
    wxSize s = GetSize();
    SetStatusText(wxString::Format("Size: %dx%d", s.GetWidth(), s.GetHeight()), 2);
    SetStatusText(wxString::Format("style=%ld", style), 3);
    CenterOnScreen();
    }
}


