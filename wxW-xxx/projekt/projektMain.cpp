#include <wx/wx.h>
#include <wx/artprov.h>
#include <wx/scrolwin.h>
#include <vector>

// Prosta struktura: id jako const char* (unikamy mieszaniny wxChar / char)
struct ArtEntry {
    const char* id;
    const char* name;
};

class ArtFrame : public wxFrame
{
public:
    ArtFrame() : wxFrame(nullptr, wxID_ANY, "wxArtProvider - icons viewer", wxDefaultPosition, wxSize(900,600))
    {
        wxScrolledWindow* sc = new wxScrolledWindow(this);
        sc->SetScrollRate(10,10);

        const int cols = 6;
        wxGridSizer* gs = new wxGridSizer(cols, 10, 10);

        // Lista identyfikatorów - trzymaj tutaj tylko te, które są dostępne w Twojej wersji wxWidgets.
        // Jeśli jakaś stała nie jest zdefiniowana w Twojej wersji, kompilator zgłosi błąd.
        // Możesz owinąć taką linię w #ifdef wxART_HOME ... #endif jeśli chcesz.
        std::vector<ArtEntry> arts = {
            { wxART_NEW,               "wxART_NEW" },
            { wxART_FILE_OPEN,         "wxART_FILE_OPEN" },
            { wxART_FILE_SAVE,         "wxART_FILE_SAVE" },
            { wxART_HELP,              "wxART_HELP" },
            { wxART_FIND,              "wxART_FIND" },
            { wxART_COPY,              "wxART_COPY" },
            { wxART_CUT,               "wxART_CUT" },
            { wxART_PASTE,             "wxART_PASTE" },
            { wxART_DELETE,            "wxART_DELETE" },
            { wxART_ERROR,             "wxART_ERROR" },
            { wxART_WARNING,           "wxART_WARNING" },
            { wxART_INFORMATION,       "wxART_INFORMATION" },
            { wxART_QUESTION,          "wxART_QUESTION" },
            { wxART_PRINT,             "wxART_PRINT" },
            { wxART_FOLDER,            "wxART_FOLDER" },
            { wxART_FOLDER_OPEN,       "wxART_FOLDER_OPEN" },
            { wxART_GO_BACK,           "wxART_GO_BACK" },
            { wxART_GO_FORWARD,        "wxART_GO_FORWARD" },
            { wxART_REFRESH,          "wxART_REFRESH" },
            { wxART_STOP,             "wxART_STOP" },
            { wxART_TIP,              "wxART_TIP" }
            // UWAGA: jeśli np. wxART_HOME nie jest zdefiniowane w Twojej instalacji,
            // dodanie { wxART_HOME, "wxART_HOME" } spowoduje błąd kompilacji.
        };

        const wxSize iconSize(48,48);

        for (const auto &a : arts)
        {
            wxBitmap bmp = wxArtProvider::GetBitmap(a.id, wxART_TOOLBAR, iconSize);

            wxBoxSizer* vs = new wxBoxSizer(wxVERTICAL);

            if (bmp.IsOk())
            {
                // jeżeli dostarczona bitmapa ma inny rozmiar, przeskaluj (opcjonalnie)
                if (bmp.GetWidth() != iconSize.x || bmp.GetHeight() != iconSize.y)
                {
                    wxImage img = bmp.ConvertToImage();
                    img = img.Scale(iconSize.x, iconSize.y, wxIMAGE_QUALITY_HIGH);
                    bmp = wxBitmap(img);
                }
                // pokazujemy ikonę i wypisujemy jej rozmiar do loga (debug)
                wxStaticBitmap* sbmp = new wxStaticBitmap(sc, wxID_ANY, bmp);
                vs->Add(sbmp, 0, wxALIGN_CENTER);
                wxLogMessage("%s -> %d x %d", a.name, bmp.GetWidth(), bmp.GetHeight());
            }
            else
            {
                vs->Add(new wxStaticText(sc, wxID_ANY, "(brak ikony)"), 0, wxALIGN_CENTER);
                wxLogMessage("%s -> (brak ikony)", a.name);
            }

            wxStaticText* label = new wxStaticText(sc, wxID_ANY, wxString::FromUTF8(a.name));
            vs->Add(label, 0, wxALIGN_CENTER | wxTOP, 4);

            wxStaticBox* box = new wxStaticBox(sc, wxID_ANY, "");
            wxStaticBoxSizer* boxs = new wxStaticBoxSizer(box, wxVERTICAL);
            boxs->Add(vs, 0, wxALL | wxALIGN_CENTER, 6);

            gs->Add(boxs, 0, wxEXPAND);
        }

        sc->SetSizer(gs);
        gs->Fit(sc);
        Layout();
    }
};

class MyApp : public wxApp
{
public:
    bool OnInit() override
    {
        ArtFrame* f = new ArtFrame();
        f->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
