#include "Contact.h"

using namespace Model;

Contact::Contact(string name, int phone) {
	this->id = getCount();
	this->name = name;
	this->phone = phone;
}

string Contact::toString() {
	stringstream n;
	n << "\n\t - Informacion de Contacto - \n";
	n << "\t ID: " << this->id << "\n";
	n << "\t Nombre: " << this->name << "\n";
	n << "\t Telefono: " << this->phone << "\n\n";
	return n.str();
}

Contact* Contact::create(string name, int phone) {
	Contact* contact = new Contact(name, phone);
	contact->save();
	return contact;
}

void Contact::save() {
	ofstream file(FILE_NAME, ios::app);
	file << this->id << "," << this->name << "," << this->phone << endl;
	file.close();
}

void Contact::update() {
	ifstream file(FILE_NAME);

	if (!file) {
		file.close();
		return;
	}

	ofstream temp(TEMP_NAME);

	while (!file.eof()) {
		string contact_id, contact_name, contact_phone;

		getline(file, contact_id, ',');
		getline(file, contact_name, ',');
		getline(file, contact_phone);

		if (!file.eof()) {
			if (atoi(contact_id.c_str()) == this->id) {
				temp << this->id << "," << this->name << "," << this->phone << endl;
			}
			else {
				temp << contact_id << "," << contact_name << "," << contact_phone << endl;
			}
		}
	}

	file.close();
	temp.close();

	remove(FILE_NAME);
	int result = rename(TEMP_NAME, FILE_NAME);
}

void Contact::del() {
	ifstream file(FILE_NAME);

	if (!file) {
		file.close();
		return;
	}

	ofstream temp(TEMP_NAME); 

	while (!file.eof()) {
		string contact_id, contact_name, contact_phone;

		getline(file, contact_id, ',');
		getline(file, contact_name, ',');
		getline(file, contact_phone);

		if (!file.eof()) {
			if (contact_name != this->name) {
				temp << contact_id << "," << contact_name << "," << contact_phone << endl;
			}
		}
	}

	file.close();
	temp.close();

	remove(FILE_NAME);
	int result = rename(TEMP_NAME, FILE_NAME);
}

Contact* Contact::find(string name) {
	ifstream file(FILE_NAME);

	if (!file) {
		file.close();
		return NULL;
	}

	Contact* contact = NULL;

	while (!file.eof()) {
		string contact_id, contact_name, contact_phone;

		getline(file, contact_id, ',');
		getline(file, contact_name, ',');
		getline(file, contact_phone);

		if (contact_name == name) {
			contact = new Contact(contact_name, atoi(contact_phone.c_str()));
			contact->id = atoi(contact_id.c_str());
			break;
		}
	}

	file.close();
	return contact;
}

int Contact::getCount() {
	ifstream file(FILE_NAME);

	int count = 1;

	if (!file) {
		file.close();
		return count;
	}

	while (!file.eof()) {
		string contact_id, contact_name, contact_phone;

		getline(file, contact_id, ',');
		getline(file, contact_name, ',');
		getline(file, contact_phone);

		if (!file.eof()) {
			count = atoi(contact_id.c_str()) + 1;
		}
	}

	file.close();
	return count;
}


