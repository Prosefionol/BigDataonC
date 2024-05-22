#include "ChangingForm.h"

System::Void Frontend::ChangingForm::наГлавнуюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::ChangingForm::ChangingForm_Shown(System::Object^ sender, System::EventArgs^ e)
{
	int n = 0;
	int state;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, state, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("Информация не была загружена или в текущей базе данных отсутствуют сведения!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	Header();
	dataGridView1->RowCount = n + 1;
	dataGridView1->ColumnCount = 9;
	DataTables(buf, n);

	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();

	delete[] buf;
	return System::Void();
}

System::Void Frontend::ChangingForm::Header()
{
	DataGridViewTextBoxColumn^ c0 = gcnew DataGridViewTextBoxColumn();
	c0->HeaderText = "Поставщик";
	c0->Width = 150;
	dataGridView1->Columns->Add(c0);

	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->HeaderText = "Товар";
	c1->Width = 150;
	dataGridView1->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->HeaderText = "Цена";
	c2->Width = 150;
	dataGridView1->Columns->Add(c2);

	DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
	c3->HeaderText = "Уровень инноваций";
	c3->Width = 150;
	dataGridView1->Columns->Add(c3);

	DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
	c4->HeaderText = "Транспортная логистика";
	c4->Width = 150;
	dataGridView1->Columns->Add(c4);

	DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
	c5->HeaderText = "Гарантийные обязательства";
	c5->Width = 150;
	dataGridView1->Columns->Add(c5);
	
	DataGridViewTextBoxColumn^ c6 = gcnew DataGridViewTextBoxColumn();
	c6->HeaderText = "Репутация поставщика";
	c6->Width = 150;
	dataGridView1->Columns->Add(c6);

	DataGridViewTextBoxColumn^ c7 = gcnew DataGridViewTextBoxColumn();
	c7->HeaderText = "Коммуникация";
	c7->Width = 150;
	dataGridView1->Columns->Add(c7);

	DataGridViewTextBoxColumn^ c8 = gcnew DataGridViewTextBoxColumn();
	c8->HeaderText = "Масштабируемость и гибкость";
	c8->Width = 150;
	dataGridView1->Columns->Add(c8);

	dataGridView1->TopLeftHeaderCell->Value = "Данные";
	dataGridView1->AutoResizeColumns();
}

System::Void Frontend::ChangingForm::DataTables(Elem* (&el), int& n)
{
	for (int i = 0; i < dataGridView1->RowCount - 1; i++)
	{
		dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView1->Rows[i]->Cells[0]->Value = stoS(el[i].GetSupplier());
		dataGridView1->Rows[i]->Cells[1]->Value = stoS(el[i].GetProduct().name);
		dataGridView1->Rows[i]->Cells[2]->Value = el[i].GetProduct().property[0];
		dataGridView1->Rows[i]->Cells[3]->Value = el[i].GetProduct().property[1];
		dataGridView1->Rows[i]->Cells[4]->Value = el[i].GetProduct().property[2];
		dataGridView1->Rows[i]->Cells[5]->Value = el[i].GetProduct().property[3];
		dataGridView1->Rows[i]->Cells[6]->Value = el[i].GetProduct().property[4];
		dataGridView1->Rows[i]->Cells[7]->Value = el[i].GetProduct().property[5];
		dataGridView1->Rows[i]->Cells[8]->Value = el[i].GetProduct().property[6];
	}
}

System::Void Frontend::ChangingForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int n = 0;
	int state;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, state, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("Информация не была загружена или в текущей базе данных отсутствуют сведения!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	if (dataGridView1->RowCount == 1)
	{
		System::Windows::Forms::MessageBox::Show("Информация не была загружена или в текущей базе данных отсутствуют сведения!", "Уведомление");
		delete[] buf;
		return System::Void();
	}
	
	if (dataGridView1->SelectedRows->Count == 0)
	{
		System::Windows::Forms::MessageBox::Show("Выделите строку!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	int ch = dataGridView1->CurrentCell->RowIndex;

	std::string supp;
	std::string sbuf;
	Product prod;

	S_to_s(dataGridView1->Rows[ch]->Cells[0]->Value->ToString(), supp);
	S_to_s(dataGridView1->Rows[ch]->Cells[1]->Value->ToString(), prod.name);

	S_to_s(dataGridView1->Rows[ch]->Cells[2]->Value->ToString(), sbuf);
	prod.property[0] = atoi(sbuf.c_str());
	if (prod.property[0] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 3", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[ch]->Cells[3]->Value->ToString(), sbuf);
	prod.property[1] = atoi(sbuf.c_str());
	if (prod.property[1] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 4", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[ch]->Cells[4]->Value->ToString(), sbuf);
	prod.property[2] = atoi(sbuf.c_str());
	if (prod.property[2] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 5", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[ch]->Cells[5]->Value->ToString(), sbuf);
	prod.property[3] = atoi(sbuf.c_str());
	if (prod.property[3] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 6", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[ch]->Cells[6]->Value->ToString(), sbuf);
	prod.property[4] = atoi(sbuf.c_str());
	if (prod.property[4] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 7", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[ch]->Cells[7]->Value->ToString(), sbuf);
	prod.property[5] = atoi(sbuf.c_str());
	if (prod.property[5] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 8", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[ch]->Cells[8]->Value->ToString(), sbuf);
	prod.property[6] = atoi(sbuf.c_str());
	if (prod.property[6] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 9", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	prod.relevance = 0.;
	state = 3;

	buf[ch].GetDatabase(supp, prod);

	SaveToFile(buf, n, state, "data.txt");
	Frontend::ChangingForm::ChangingForm_Shown(sender, e);

	delete[] buf;
	return System::Void();
}

System::Void Frontend::ChangingForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	int n = 0;
	int state;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, state, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("Информация не была загружена или в текущей базе данных отсутствуют сведения!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	dataGridView1->Rows->Add();
	AddData(buf, n);

	
	std::string supp;
	std::string sbuf;
	Product prod;

	S_to_s(dataGridView1->Rows[n-1]->Cells[0]->Value->ToString(), supp);
	S_to_s(dataGridView1->Rows[n-1]->Cells[1]->Value->ToString(), prod.name);

	S_to_s(dataGridView1->Rows[n-1]->Cells[2]->Value->ToString(), sbuf);
	prod.property[0] = atoi(sbuf.c_str());
	if (prod.property[0] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 3", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[n-1]->Cells[3]->Value->ToString(), sbuf);
	prod.property[1] = atoi(sbuf.c_str());
	if (prod.property[1] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 4", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[n-1]->Cells[4]->Value->ToString(), sbuf);
	prod.property[2] = atoi(sbuf.c_str());
	if (prod.property[2] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 5", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[n-1]->Cells[5]->Value->ToString(), sbuf);
	prod.property[3] = atoi(sbuf.c_str());
	if (prod.property[3] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 6", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[n-1]->Cells[6]->Value->ToString(), sbuf);
	prod.property[4] = atoi(sbuf.c_str());
	if (prod.property[4] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 7", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[n-1]->Cells[7]->Value->ToString(), sbuf);
	prod.property[5] = atoi(sbuf.c_str());
	if (prod.property[5] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 8", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	S_to_s(dataGridView1->Rows[n-1]->Cells[8]->Value->ToString(), sbuf);
	prod.property[6] = atoi(sbuf.c_str());
	if (prod.property[6] == 0)
	{
		System::Windows::Forms::MessageBox::Show("Неправильный формат входных данных в столбце 9", "Уведомление");
		delete[] buf;
		Frontend::ChangingForm::ChangingForm_Shown(sender, e);
		return System::Void();
	}

	prod.relevance = 0.;
	state = 3;

	buf[n-1].GetDatabase(supp, prod);
	
	SaveToFile(buf, n, state, "data.txt");
	Frontend::ChangingForm::ChangingForm_Shown(sender, e);

	delete[] buf;
	return System::Void();
}

System::Void Frontend::ChangingForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	int n = 0;
	int state;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, state, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("Информация не была загружена или в текущей базе данных отсутствуют сведения!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	if (dataGridView1->RowCount == 1)
	{
		System::Windows::Forms::MessageBox::Show("Информация не была загружена или в текущей базе данных отсутствуют сведения!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	if (dataGridView1->SelectedRows->Count == 0)
	{
		System::Windows::Forms::MessageBox::Show("Выделите строку!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	int del = dataGridView1->CurrentCell->RowIndex;
	DeleteData(buf, n, del);
	dataGridView1->Rows->RemoveAt(del);
	state = 3;

	SaveToFile(buf, n, state, "data.txt");
	Frontend::ChangingForm::ChangingForm_Shown(sender, e);

	delete[] buf;
	return System::Void();
}
