#include "SavingForm.h"
#include "BFunc.h"

System::Void Frontend::SavingForm::���������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::SavingForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text == "")
	{
		System::Windows::Forms::MessageBox::Show("������� �������� �����!", "�����������");
		return System::Void();
	}

	std::string filename;
	int state;
	int n = 0;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, state, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("���� ������ �� ���� ���������!", "�����������");
		delete[] buf;
		return System::Void();
	}
	S_to_s(textBox1->Text->ToString(), filename);
	if (SaveToFile(buf, n, state, filename))
	{
		System::Windows::Forms::MessageBox::Show("���� ������ ������� ���������!", "�����������");

		if (System::Windows::Forms::MessageBox::Show("����� �� ���������?", "���������", System::Windows::Forms::MessageBoxButtons::YesNo)
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
