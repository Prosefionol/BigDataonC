#include "TopsisForm.h"

System::Void Frontend::TopsisForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}
