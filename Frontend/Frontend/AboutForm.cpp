#include "AboutForm.h"

System::Void Frontend::AboutForm::íàÃëàâíóþToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}
