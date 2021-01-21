#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <gtkmm.h>

class windowMain : public Gtk::Window
{
    public:
        windowMain();
        virtual ~windowMain();

    protected:
        // Signals handlers
            void on_click_operation(std::string operation_type);

            void on_click_quit();
            void on_click_copy();
            void on_click_cut();
            void on_click_paste();
            void on_clipboard_paste(const Glib::ustring& text);
            void on_click_about();

        // Widgets
            Gtk::Box boxMain, boxText;
            Gtk::Grid gridButtons;

            Gtk::Entry txtCalcs;
            Gtk::Button btnN1, btnN2, btnN3, btnN4, btnN5;
            Gtk::Button btnN6, btnN7, btnN8, btnN9;
            Gtk::Button btnN0, btnPlus, btnLess, btnMult;
            Gtk::Button btnDiv, btnIqual, btnC, btnCA, btnOPa, btnCPa;

            Gtk::MenuBar menuBarMain;

            Gtk::MenuItem itemFile, itemEdit, itemHelp;
            Gtk::Menu menuFile, menuEdit, menuHelp;

            Gtk::ImageMenuItem itemQuit;
            Gtk::ImageMenuItem itemCopy;
            Gtk::ImageMenuItem itemCut;
            Gtk::ImageMenuItem itemPaste;
            Gtk::ImageMenuItem itemAbout;
};

#endif // WINDOWMAIN_H
