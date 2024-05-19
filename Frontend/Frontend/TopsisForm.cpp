#include "TopsisForm.h"

System::Void Frontend::TopsisForm::наГлавнуюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MenuForm^ form = gcnew MenuForm();
	this->Hide();
	form->Show();
}

System::Void Frontend::TopsisForm::TopsisForm_Shown(System::Object^ sender, System::EventArgs^ e)
{
	int n = 0;
	double avg;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("Информация не была загружена или в текущей базе данных отсутствуют сведения!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	ApplyMCDM(buf, n);
	// ApplyTopsis(buf, n);
	SaveToFile(buf, n, "data.txt");

	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	HeaderT();
	dataGridView1->RowCount = n + 1;
	dataGridView1->ColumnCount = 3;
	DataTablesT(buf, n);

	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();

	DrawChart(buf, n);

	delete[] buf;
	return System::Void();
}

System::Void Frontend::TopsisForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int n = 0;
	Elem* buf = new Elem[n];

	GetFromFile(buf, n, "data.txt");
	if (n == 0)
	{
		System::Windows::Forms::MessageBox::Show("Информация не была загружена или в текущей базе данных отсутствуют сведения!", "Уведомление");
		delete[] buf;
		return System::Void();
	}

	if ((!radioButton1->Checked) && (!radioButton2->Checked))
	{
		System::Windows::Forms::MessageBox::Show("Выберите параметры сортировки!", "Уведомление");
		delete[] buf;
		return System::Void();
	}
	else
	{
		if (radioButton1->Checked)
		{
			SortingRelevance(buf, n);
		}
		else
		{
			RelevanceSorting(buf, n);
		}
	}

	SaveToFile(buf, n, "data.txt");
	delete[] buf;
	Frontend::TopsisForm::TopsisForm_Shown(sender, e);
	return System::Void();
}

System::Void Frontend::TopsisForm::HeaderT()
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
	c2->HeaderText = "Релевантность";
	c2->Width = 150;
	dataGridView1->Columns->Add(c2);

	dataGridView1->TopLeftHeaderCell->Value = "Результаты";
	dataGridView1->AutoResizeColumns();
}

System::Void Frontend::TopsisForm::DataTablesT(Elem* (&el), int& n)
{
	for (int i = 0; i < dataGridView1->RowCount - 1; i++)
	{
		dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView1->Rows[i]->Cells[0]->Value = stoS(el[i].GetSupplier());
		dataGridView1->Rows[i]->Cells[1]->Value = stoS(el[i].GetProduct().name);
		dataGridView1->Rows[i]->Cells[2]->Value = el[i].GetProduct().relevance;
	}
}

System::Void Frontend::TopsisForm::DrawChart(Elem* (&el), int& n)
{
	double avg;

	avg = FindAverageRelevance(el, n);	
	
	this->chart1->Series["Рейтинг поставщиков"]->Points->Clear();
	this->chart1->Series["Среднее арифметическое значение рейтинга"]->Points->Clear();

	for (int i = 0; i < n; i++)
	{
		this->chart1->Series["Рейтинг поставщиков"]->Points->AddXY(stoS(el[i].GetSupplier()), el[i].GetProduct().relevance);
		this->chart1->Series["Среднее арифметическое значение рейтинга"]->Points->AddXY(stoS(el[i].GetSupplier()), avg);
	}
}
