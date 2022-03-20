#include "SavingForm.h"
#include "BFunc.h"

System::Void Frontend::SavingForm::наГлавнуюToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::SavingForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text == "")
	{
		System::Windows::Forms::MessageBox::Show("Укажите название файла!", "Уведомление");
		return System::Void();
	}

	std::string filename;
	int n = 0;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("База данных не была загружена!", "Уведомление");
		delete[] buf;
		return System::Void();
	}
	S_to_s(textBox1->Text->ToString(), filename);
	if (SaveToFile(buf, n, filename))
	{
		System::Windows::Forms::MessageBox::Show("База данных успешно сохранена!", "Уведомление");

		if (System::Windows::Forms::MessageBox::Show("Выйти из программы?", "Навигация", System::Windows::Forms::MessageBoxButtons::YesNo)
			!= System::Windows::Forms::DialogResult::No)
		{
			ClearFile("data.txt");
			delete[] buf;
			Application::Exit();
			return System::Void();
		}
	}

	delete[] buf;
	return System::Void();
}
