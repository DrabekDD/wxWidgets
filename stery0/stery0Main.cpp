#include <wx/wx.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/listbook.h>
#include <wx/notebook.h>
#include <wx/imaglist.h>

class MyFrame : public wxFrame
{
public:
    MyFrame()
        : wxFrame(nullptr, wxID_ANY, "Przyklady kontrolek wxWidgets",
                  wxDefaultPosition, wxSize(1100, 700))
    {
        CreateUI();
        Centre();
    }

private:
    wxListBox*   m_listBox   = nullptr;
    wxListCtrl*  m_listCtrl  = nullptr;
    wxListView*  m_listView  = nullptr;
    wxNotebook*  m_notebook  = nullptr;
    wxListbook*  m_listbook  = nullptr;

    void CreateUI()
    {
        wxPanel* panel = new wxPanel(this);

        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

        wxStaticText* title = new wxStaticText(
            panel, wxID_ANY,
            "Porownanie: wxListBox, wxListCtrl, wxListView, wxNotebook, wxListbook");
        wxFont font = title->GetFont();
        font.SetPointSize(font.GetPointSize() + 2);
        font.SetWeight(wxFONTWEIGHT_BOLD);
        title->SetFont(font);

        mainSizer->Add(title, 0, wxALL, 10);

        // Główna siatka 2x2
        wxGridSizer* grid = new wxGridSizer(2, 2, 10, 10);

        grid->Add(CreateListBoxPanel(panel), 1, wxEXPAND | wxALL, 5);
        grid->Add(CreateListCtrlPanel(panel), 1, wxEXPAND | wxALL, 5);
        grid->Add(CreateListViewPanel(panel), 1, wxEXPAND | wxALL, 5);
        grid->Add(CreateBooksPanel(panel), 1, wxEXPAND | wxALL, 5);

        mainSizer->Add(grid, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);

        panel->SetSizer(mainSizer);
    }

    wxPanel* CreateListBoxPanel(wxWindow* parent)
    {
        wxPanel* p = new wxPanel(parent);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        sizer->Add(new wxStaticText(p, wxID_ANY,
            "wxListBox\nProsta lista napisow do wyboru"), 0, wxALL, 5);

        wxArrayString items;
        items.Add("Czerwony");
        items.Add("Zielony");
        items.Add("Niebieski");
        items.Add("Zolty");
        items.Add("Czarny");

        m_listBox = new wxListBox(p, wxID_ANY, wxDefaultPosition, wxDefaultSize, items);
        sizer->Add(m_listBox, 1, wxEXPAND | wxALL, 5);

        m_listBox->Bind(wxEVT_LISTBOX, &MyFrame::OnListBoxSelect, this);

        p->SetSizer(sizer);
        return p;
    }

    wxPanel* CreateListCtrlPanel(wxWindow* parent)
    {
        wxPanel* p = new wxPanel(parent);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        sizer->Add(new wxStaticText(p, wxID_ANY,
            "wxListCtrl\nRozbudowana lista / tabela / raport"), 0, wxALL, 5);

        m_listCtrl = new wxListCtrl(
            p, wxID_ANY, wxDefaultPosition, wxDefaultSize,
            wxLC_REPORT | wxLC_SINGLE_SEL
        );

        m_listCtrl->InsertColumn(0, "Imie", wxLIST_FORMAT_LEFT, 140);
        m_listCtrl->InsertColumn(1, "Wiek", wxLIST_FORMAT_LEFT, 80);
        m_listCtrl->InsertColumn(2, "Miasto", wxLIST_FORMAT_LEFT, 140);

        long idx = m_listCtrl->InsertItem(0, "Anna");
        m_listCtrl->SetItem(idx, 1, "23");
        m_listCtrl->SetItem(idx, 2, "Warszawa");

        idx = m_listCtrl->InsertItem(1, "Piotr");
        m_listCtrl->SetItem(idx, 1, "31");
        m_listCtrl->SetItem(idx, 2, "Krakow");

        idx = m_listCtrl->InsertItem(2, "Maria");
        m_listCtrl->SetItem(idx, 1, "28");
        m_listCtrl->SetItem(idx, 2, "Gdansk");

        sizer->Add(m_listCtrl, 1, wxEXPAND | wxALL, 5);

        m_listCtrl->Bind(wxEVT_LIST_ITEM_SELECTED, &MyFrame::OnListCtrlSelect, this);

        p->SetSizer(sizer);
        return p;
    }

    wxPanel* CreateListViewPanel(wxWindow* parent)
    {
        wxPanel* p = new wxPanel(parent);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        sizer->Add(new wxStaticText(p, wxID_ANY,
            "wxListView\nWygodniejsza nakladka na wxListCtrl"), 0, wxALL, 5);

        m_listView = new wxListView(
            p, wxID_ANY, wxDefaultPosition, wxDefaultSize,
            wxLC_REPORT | wxLC_SINGLE_SEL
        );

        m_listView->AppendColumn("Produkt", wxLIST_FORMAT_LEFT, 180);
        m_listView->AppendColumn("Cena", wxLIST_FORMAT_LEFT, 100);
        m_listView->AppendColumn("Stan", wxLIST_FORMAT_LEFT, 100);

        long row = m_listView->InsertItem(0, "Klawiatura");
        m_listView->SetItem(row, 1, "120 zl");
        m_listView->SetItem(row, 2, "12");

        row = m_listView->InsertItem(1, "Mysz");
        m_listView->SetItem(row, 1, "65 zl");
        m_listView->SetItem(row, 2, "24");

        row = m_listView->InsertItem(2, "Monitor");
        m_listView->SetItem(row, 1, "899 zl");
        m_listView->SetItem(row, 2, "5");

        sizer->Add(m_listView, 1, wxEXPAND | wxALL, 5);

        m_listView->Bind(wxEVT_LIST_ITEM_SELECTED, &MyFrame::OnListViewSelect, this);

        p->SetSizer(sizer);
        return p;
    }

    wxPanel* CreateBooksPanel(wxWindow* parent)
    {
        wxPanel* p = new wxPanel(parent);
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

        // -------- wxNotebook --------
        wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
        leftSizer->Add(new wxStaticText(p, wxID_ANY,
            "wxNotebook\nKlasyczne zakladki"), 0, wxALL, 5);

        m_notebook = new wxNotebook(p, wxID_ANY);

        wxPanel* nbPage1 = new wxPanel(m_notebook);
        wxPanel* nbPage2 = new wxPanel(m_notebook);
        wxPanel* nbPage3 = new wxPanel(m_notebook);

        {
            wxBoxSizer* ps = new wxBoxSizer(wxVERTICAL);
            ps->Add(new wxStaticText(nbPage1, wxID_ANY, "Strona: Ogolne"), 0, wxALL, 10);
            nbPage1->SetSizer(ps);
        }
        {
            wxBoxSizer* ps = new wxBoxSizer(wxVERTICAL);
            ps->Add(new wxStaticText(nbPage2, wxID_ANY, "Strona: Siec"), 0, wxALL, 10);
            nbPage2->SetSizer(ps);
        }
        {
            wxBoxSizer* ps = new wxBoxSizer(wxVERTICAL);
            ps->Add(new wxStaticText(nbPage3, wxID_ANY, "Strona: Zaawansowane"), 0, wxALL, 10);
            nbPage3->SetSizer(ps);
        }

        m_notebook->AddPage(nbPage1, "Ogolne");
        m_notebook->AddPage(nbPage2, "Siec");
        m_notebook->AddPage(nbPage3, "Zaawansowane");

        leftSizer->Add(m_notebook, 1, wxEXPAND | wxALL, 5);

        // -------- wxListbook --------
        wxBoxSizer* rightSizer = new wxBoxSizer(wxVERTICAL);
        rightSizer->Add(new wxStaticText(p, wxID_ANY,
            "wxListbook\nStrony wybierane z listy"), 0, wxALL, 5);

        m_listbook = new wxListbook(p, wxID_ANY);

        wxPanel* lbPage1 = new wxPanel(m_listbook);
        wxPanel* lbPage2 = new wxPanel(m_listbook);
        wxPanel* lbPage3 = new wxPanel(m_listbook);

        {
            wxBoxSizer* ps = new wxBoxSizer(wxVERTICAL);
            ps->Add(new wxStaticText(lbPage1, wxID_ANY, "Kategoria: Ustawienia ogolne"), 0, wxALL, 10);
            lbPage1->SetSizer(ps);
        }
        {
            wxBoxSizer* ps = new wxBoxSizer(wxVERTICAL);
            ps->Add(new wxStaticText(lbPage2, wxID_ANY, "Kategoria: Wyglad"), 0, wxALL, 10);
            lbPage2->SetSizer(ps);
        }
        {
            wxBoxSizer* ps = new wxBoxSizer(wxVERTICAL);
            ps->Add(new wxStaticText(lbPage3, wxID_ANY, "Kategoria: Uzytkownicy"), 0, wxALL, 10);
            lbPage3->SetSizer(ps);
        }

        m_listbook->AddPage(lbPage1, "Ogolne");
        m_listbook->AddPage(lbPage2, "Wyglad");
        m_listbook->AddPage(lbPage3, "Uzytkownicy");

        rightSizer->Add(m_listbook, 1, wxEXPAND | wxALL, 5);

        sizer->Add(leftSizer, 1, wxEXPAND | wxALL, 5);
        sizer->Add(rightSizer, 1, wxEXPAND | wxALL, 5);

        p->SetSizer(sizer);
        return p;
    }

    void OnListBoxSelect(wxCommandEvent& event)
    {
        wxString text = m_listBox->GetStringSelection();
        SetStatusText("wxListBox: wybrano " + text);
        wxLogMessage("wxListBox -> %s", text);
    }

    void OnListCtrlSelect(wxListEvent& event)
    {
        long row = event.GetIndex();
        wxString name = m_listCtrl->GetItemText(row, 0);
        wxString age  = m_listCtrl->GetItemText(row, 1);
        wxString city = m_listCtrl->GetItemText(row, 2);

        wxString msg;
        msg.Printf("wxListCtrl -> %s, %s lat, %s", name, age, city);
        SetStatusText(msg);
        wxLogMessage("%s", msg);
    }

    void OnListViewSelect(wxListEvent& event)
    {
        long row = event.GetIndex();
        wxString product = m_listView->GetItemText(row, 0);
        wxString price   = m_listView->GetItemText(row, 1);
        wxString stock   = m_listView->GetItemText(row, 2);

        wxString msg;
        msg.Printf("wxListView -> %s, cena: %s, stan: %s", product, price, stock);
        SetStatusText(msg);
        wxLogMessage("%s", msg);
    }
};

class MyApp : public wxApp
{
public:
    bool OnInit() override
    {
        MyFrame* frame = new MyFrame();
        frame->CreateStatusBar();
        frame->SetStatusText("Gotowe");
        frame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
