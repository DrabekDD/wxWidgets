#pragma once
#include <wx/wx.h>

class MyFrame;

class MyApp : public wxApp
{
private:
    MyFrame* frame = nullptr;
public:
    bool OnInit() override;
};

