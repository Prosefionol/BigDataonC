#include "InputForm.h"
#include "BFunc.h"

System::Void Frontend::InputForm::наГлавнуюToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::InputForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text == "")
	{
		System::Windows::Forms::MessageBox::Show("Укажите название файла!", "Уведомление");
		return System::Void();
	}

	std::string filename;
	int n = 0;
	Elem* buf = new Elem[n];

	S_to_s(textBox1->Text->ToString(), filename);
	if (GetFromFile(buf, n, filename))
	{
		System::Windows::Forms::MessageBox::Show("База данных считана успешно!\nВсего считано " + n + " запись(си).", "Уведомление");
		SaveToFile(buf, n, "data.txt");
	}
	
	delete[] buf;
	return System::Void();
}
