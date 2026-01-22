#include "wxW_Main.h"
/*
MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
                 const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{

    //CreateStatusBar(2, wxSB_FLAT);   // pasek stanu: 2 pola, styl płaski
    //SetStatusText(title, 0);         // pole 0: tytuł okna
    //SetStatusText("abc", 1);         // pole 1: tekst przykładowy


    wxStatusBar* sb = CreateStatusBar(2,wxSTB_DEFAULT_STYLE | wxSTB_SHOW_TIPS); // tworzymy dwa pola w pasku
    int sbwd[4] = {150, -1, -2, 100};
    sb->SetFieldsCount(4, sbwd);          // robimy 4 pola o zadanej szerokości

    for (int i = 0; i < 4; i++)           // Wypisanie szerokości pól
        SetStatusText(wxString::Format("Szer.: %d", sbwd[i]), i);

    int st[4] = { wxSB_RAISED, wxSB_SUNKEN, wxSB_RAISED, wxSB_SUNKEN};
    sb->SetStatusStyles(4, st);

    sb->SetBackgroundColour(*wxLIGHT_GREY);
//    sb->SetForegroundColour(*wxBLACK);
    sb->Refresh();

    CenterOnScreen();
}
*/


MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
                 const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{
    wxStatusBar* sb = CreateStatusBar();

    int widths[4] = { 250, 170, -1, 140 };     // 4 pola: 250px, 170px, elastyczne, 140px
    sb->SetFieldsCount(4, widths);

    // Style pól
    int st[4] = { wxSB_NORMAL, wxSB_SUNKEN, wxSB_NORMAL, wxSB_SUNKEN };
    sb->SetStatusStyles(4, st);

    // 1) Tytuł okna (to samo co parametr "title")
    SetStatusText(GetTitle(), 0);

    // 2) Pozycja okna na ekranie
    wxPoint p = GetPosition();
    SetStatusText(wxString::Format("Pos: %d,%d", p.x, p.y), 1);

    // 3) Rozmiar okna
    wxSize s = GetSize();
    SetStatusText(wxString::Format("Size: %dx%d", s.GetWidth(), s.GetHeight()), 2);

    // 4) Styl okna (tu po prostu liczba)
    SetStatusText(wxString::Format("style=%ld", style), 3);

    CenterOnScreen();
}


