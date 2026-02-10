#pragma once
#include <wx/wx.h>

class MyApp : public wxApp
{
private:
    wxFrame* frame= nullptr;
public:
    bool OnInit() override;
};
