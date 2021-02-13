#include "cpw-calcConfig.h"
#include "windowMain.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
	// Creamos la aplicación
		Glib::RefPtr<Gtk::Application> mi_app = Gtk::Application::create(
			argc,
			argv,
			"net.cpwonline.cpw-calc"
		);
	// Creamos un objeto de la clase
		windowMain mi_ventana1;

	//Mostramos la ventana y retornamos cuando se cierre
		return mi_app->run(mi_ventana1);
}
