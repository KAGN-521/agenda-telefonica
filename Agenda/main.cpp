#include "Tool.h"
#include "Contact.h"

using namespace Model;

void addContact();
void searchContact();
void deleteContact();
void modifyContact();

int main()
{
	int mainMenu = 0;

	while (mainMenu != 5) {
		clear();
		print("\n\t -------------------\n");
		print("\t Agenda de Contactos \n");
		print("\t -------------------\n");
		print("\t 1. Agregar \n");
		print("\t 2. Buscar \n");
		print("\t 3. Eliminar \n");
		print("\t 4. Modificar \n");
		print("\t 5. Salir \n");
		print("\n\t");
		mainMenu = getInt();

		switch (mainMenu)
		{
		case 1:
			addContact();
			pause();
			break;

		case 2:
			searchContact();
			pause();
			break;

		case 3:
			deleteContact();
			pause();
			break;

		case 4:
			modifyContact();
			pause();
			break;

		case 5:
			print("\n\t Hasta Luego \n\n");
			pause();
			break;

		default:
			break;
		}
	}
}

void addContact() {
	print("\n\t Digite: \n");
	print("\t Nombre del Contacto: ");
	string name = getString();
	print("\t Telefono del Contacto: ");
	int phone = getInt();

	Contact::create(name, phone);

	print("\n\t Contacto Agregado \n\n");
}

void searchContact() {
	print("\n\t Digite: \n");
	print("\t Nombre del Contacto: ");
	string name = getString();

	Contact* contact = Contact::find(name);

	if (!contact) {
		print("\n\t El contacto no existe \n\n");
		return;
	}

	print(contact->toString());
}

void deleteContact() {
	print("\n\t Digite: \n");
	print("\t Nombre del Contacto: ");
	string name = getString();

	Contact* contact = Contact::find(name);

	if (!contact) {
		cout << "\n\t El contacto no existe \n\n";
		return;
	}

	contact->del();
	print("\n\t Contacto Eliminado \n\n");
}

void modifyContact() {
	print("\n\t Digite: \n");
	print("\t Nombre del Contacto: ");
	string name = getString();

	Contact* contact = Contact::find(name);

	if (!contact) {
		print("\n\t El contacto no existe \n\n");
		return;
	}

	print("\n\t Que desea cambiar ? \n");
	print("\t 1. Nombre \n");
	print("\t 2. Telefono \n");
	print("\n\t");
	int subMenu = getInt();

	print("\n\t Digite: \n");
	if (subMenu == 1) {
		print("\t Nuevo Nombre del Contacto: ");
		string new_name = getString();
		contact->name = new_name;
	}
	else if (subMenu == 2) {
		print("\t Nuevo Telefono del Contacto: ");
		int new_phone = getInt();
		contact->phone = new_phone;
	}

	contact->update();

	print("\n\t Contacto Modificado \n\n");
}

