#include "MenuForm.h"
#include "BFunc.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Frontend::MenuForm form;
	Application::Run(% form);
}


System::Void Frontend::MenuForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	InputForm^ form = gcnew InputForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::MenuForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChangingForm^ form = gcnew ChangingForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::MenuForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	TopsisForm^ form = gcnew TopsisForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::MenuForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	SavingForm^ form = gcnew SavingForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::MenuForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	AboutForm^ form = gcnew AboutForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::MenuForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	ClearFile("data.txt");
	Application::Exit();
}