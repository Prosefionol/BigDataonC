#pragma once

#include "InputForm.h"
#include "MenuForm.h"
#include "SavingForm.h"
#include "TopsisForm.h"
#include "ChangingForm.h"


namespace Frontend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AboutForm
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ наГлавнуюToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::LinkLabel^ linkLabel2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->наГлавнуюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->наГлавнуюToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(344, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// наГлавнуюToolStripMenuItem
			// 
			this->наГлавнуюToolStripMenuItem->Name = L"наГлавнуюToolStripMenuItem";
			this->наГлавнуюToolStripMenuItem->Size = System::Drawing::Size(124, 24);
			this->наГлавнуюToolStripMenuItem->Text = L"<- На главную";
			this->наГлавнуюToolStripMenuItem->Click += gcnew System::EventHandler(this, &AboutForm::наГлавнуюToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"GOST type A", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(320, 154);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Программа была разработана в качестве выпускной квалификационной работы, а также "
				L"для последующего применения на предприятии.";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"GOST type A", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 213);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(320, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Разработчик: ";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"GOST type A", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 242);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(320, 32);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Купаренков И.А. ИУ3-41М.";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"GOST type A", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 274);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(320, 29);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Контакты для связи: ";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// linkLabel1
			// 
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->linkLabel1->Location = System::Drawing::Point(12, 303);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(320, 23);
			this->linkLabel1->TabIndex = 5;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"vk.com/prosefionol";
			this->linkLabel1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"GOST type A", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 377);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(320, 68);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Код программы доступен по ссылке:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// linkLabel2
			// 
			this->linkLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->linkLabel2->Location = System::Drawing::Point(12, 445);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(320, 28);
			this->linkLabel2->TabIndex = 7;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"github.com/Prosefionol/BigDataonC";
			this->linkLabel2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(344, 505);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(362, 552);
			this->MinimumSize = System::Drawing::Size(362, 552);
			this->Name = L"AboutForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"О программе";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void наГлавнуюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
