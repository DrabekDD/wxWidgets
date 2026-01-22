#include "wxW_Main.h"


/*
MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
    Centre();
}
*/

// konstruktor okna
MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                 const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style) // w sumie taka sama jak wyżej
{
    //CenterOnScreen();
}

