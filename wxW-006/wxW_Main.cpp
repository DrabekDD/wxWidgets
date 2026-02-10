#include "wxW_Main.h"
#include <wx/artprov.h>


MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
                 const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    {//CreateMyToolbar();
    tb = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                              wxTB_HORIZONTAL | wxNO_BORDER | wxTB_FLAT, "MainToolbar");
    tb->SetToolBitmapSize(wxSize(125,125));
    tb->AddTool(wxID_ANY, "Nowy",  wxArtProvider::GetBitmap(wxART_NEW,  wxART_TOOLBAR, wxSize(16,16)), "Nowy");
    tb->AddTool(wxID_ANY, "Otwórz", wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR), "Otwórz");
    tb->AddTool(wxID_ANY, "Zapisz", wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR), "Zapisz");
    tb->AddSeparator();
    tb->AddTool(wxID_ANY, "Pomoc", wxArtProvider::GetBitmap(wxART_HELP, wxART_TOOLBAR), "Pomoc");
    tb->Realize();
    this->SetToolBar(tb); // ramka przejmuje własność — NIE usuwaj tb ręcznie !!!!

    //tb = CreateToolBar(wxTB_HORIZONTAL | wxNO_BORDER | wxTB_FLAT);
    //tb->AddTool(, "Nowy", wxArtProvider::GetBitmap(wxART_NEW, wxART_TOOLBAR), "Nowy");
    //tb->AddTool(wxID_ANY, "Otwórz", wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR), "Otwórz");
    //tb->AddTool(wxID_ANY, "Zapisz", wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR), "Zapisz");
    //tb->AddSeparator();
    //tb->AddTool(wxID_ANY, "Pomoc", wxArtProvider::GetBitmap(wxART_HELP, wxART_TOOLBAR), "Pomoc");
    //tb->Realize();
    }

    {mb = new wxMenuBar(); // tworzymy poszczególne elementy menu
    mFile = new wxMenu();
    mHelp = new wxMenu();

    mFile->AppendCheckItem(wxID_ANY, wxT("Pokaż &datę\tCtrl-D"), wxT("Data"));
    mFile->Append(wxID_ANY, wxT("Pokaż &wersję systemu\tCtrl-W"), wxT("Wersja systemu"));
    mFile->AppendSeparator();
    mFile->Append(wxID_ANY, wxT("&Zamknij program\tCtrl-x"), wxT("Zamykam program"));
    mHelp->Append(wxID_ANY, wxT("&O programie\tCtrl-H"), wxT("O programie"));
    mb->Append(mFile, wxT("&Plik"));
    mb->Append(mHelp, wxT("P&omoc"));
    this->SetMenuBar(mb);
    }

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

#include "wxW_Main.h"
#include <wx/artprov.h> // wxArtProvider dla standardowych ikon

enum
{
    ID_TOOL_NEW = wxID_HIGHEST + 1,
    ID_TOOL_OPEN,
    ID_TOOL_SAVE,
    ID_TOOL_HELP
};

void MyFrame::CreateMyToolbar()
{
    // tworzymy toolbar
    wxToolBar* tb = CreateToolBar(wxTB_HORIZONTAL | wxNO_BORDER | wxTB_FLAT);
    // Dodaj narzędzia używając standardowych ikon z wxArtProvider
    tb->AddTool(ID_TOOL_NEW, "Nowy", wxArtProvider::GetBitmap(wxART_NEW, wxART_TOOLBAR), "Nowy");
    tb->AddTool(ID_TOOL_OPEN, "Otwórz", wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR), "Otwórz");
    tb->AddTool(ID_TOOL_SAVE, "Zapisz", wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR), "Zapisz");
    tb->AddSeparator();
    tb->AddTool(ID_TOOL_HELP, "Pomoc", wxArtProvider::GetBitmap(wxART_HELP, wxART_TOOLBAR), "Pomoc");

    // finalize toolbar (upewnij się, że jest widoczny)
    tb->Realize();
}


