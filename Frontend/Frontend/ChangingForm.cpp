#include "ChangingForm.h"

System::Void Frontend::ChangingForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}
