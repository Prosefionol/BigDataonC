#include "SavingForm.h"
#include "BFunc.h"

System::Void Frontend::SavingForm::на√лавнуюToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::SavingForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text == "")
	{
		System::Windows::Forms::MessageBox::Show("”кажите название файла!", "”ведомление");
		return System::Void();
	}

	std::string filename;
	int n = 0;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("Ѕаза данных не была загружена!", "”ведомление");
		delete[] buf;
		return System::Void();
	}
	S_to_s(textBox1->Text->ToString(), filename);
	if (SaveToFile(buf, n, filename))
	{
		System::Windows::Forms::MessageBox::Show("Ѕаза данных успешно сохранена!", "”ведомление");
	}

	delete[] buf;
	return System::Void();
}
