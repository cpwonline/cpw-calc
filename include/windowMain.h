#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include <gtkmm.h>

class windowMain : public Gtk::Window
{
    public:
        windowMain();
        virtual ~windowMain();

    protected:
        // Manejadores de señal
            void on_click_0();
            void on_click_1();
            void on_click_2();
            void on_click_3();
            void on_click_4();
            void on_click_5();
            void on_click_6();
            void on_click_7();
            void on_click_8();
            void on_click_9();
            void on_click_plus();
            void on_click_less();
            void on_click_mult();
            void on_click_div();
            void on_click_c();
            void on_click_ca();
            void on_click_cpa();
            void on_click_opa();
            void on_click_iqual();

            void on_click_quit();
            void on_click_copy();
            void on_click_cut();
            void on_click_paste();
            void on_click_about();

        // Widgets de la ventana
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

            Gtk::MessageDialog dialogAbout;
};

#endif // WINDOWMAIN_H
