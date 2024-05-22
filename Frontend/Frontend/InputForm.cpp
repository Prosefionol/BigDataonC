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
	int state;
	Elem* buf = new Elem[n];

	S_to_s(textBox1->Text->ToString(), filename);
	if (GetFromFile(buf, n, state, filename))
	{
		System::Windows::Forms::MessageBox::Show("База данных считана успешно!\nВсего считано " + n + " запись(си).", "Уведомление");
		SaveToFile(buf, n, state, "data.txt");
		if (System::Windows::Forms::MessageBox::Show("Просмотреть считаные данные?", "Навигация", System::Windows::Forms::MessageBoxButtons::YesNo)
			!= System::Windows::Forms::DialogResult::No)
		{
			ChangingForm^ form = gcnew ChangingForm();
			this->Hide();
			form->Show();
		}
	}
		
	delete[] buf;
	return System::Void();
}
