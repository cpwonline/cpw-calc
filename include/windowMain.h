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

        // Widgets de la ventana
            Gtk::Box boxMain, boxText, boxButtons, boxNumbers, boxControls;
            Gtk::Box boxNCol1, boxNCol2, boxNCol3;
            Gtk::Entry txtCalcs;
            Gtk::Button btnN1, btnN2, btnN3, btnN4, btnN5;
            Gtk::Button btnN6, btnN7, btnN8, btnN9;
            Gtk::Button btnN0, btnPlus, btnLess, btnMult;
            Gtk::Button btnDiv, btnIqual, btnC, btnCA;
};

#endif // WINDOWMAIN_H
