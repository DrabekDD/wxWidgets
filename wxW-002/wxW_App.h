#pragma once
#include <wx/wx.h>

// tylko deklaracja klasy MyApp (programu), bez definicji i metod
class MyApp : public wxApp
{
public:
    bool OnInit() override;
};
