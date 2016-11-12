#pragma once

namespace Прокект {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace  System::IO;
	using namespace  System::Xml;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private:
		/// <summary>
		XmlDocument ^ xd;
		void GetTableRow(XmlNode^ node_2_, int count){

			if( (dataGridView1->Rows[count]->Cells[2]->Value) != nullptr)
				node_2_->InnerText = dataGridView1->Rows[count]->Cells[2]->Value->ToString();
			else
			node_2_->InnerText= nullptr;
		}
		void GetTableAttribute(XmlAttribute^ yo, int count){
			if ((dataGridView1->Rows[count]->Cells[2]->Value) != nullptr)
				yo->InnerText = dataGridView1->Rows[count]->Cells[2]->Value->ToString();
			else yo->Value = nullptr;

		}

		void ParseDom(XmlDocument^ xdoc){
			int count = 0;
			XmlNodeList ^ np = xdoc->ChildNodes;
			for each(XmlNode^ node in np)
			{
				count++;
				XmlNodeList ^ node_2 = node->ChildNodes;
				for each(XmlNode^ node_2_ in node_2)
				{
					GetTableRow(node_2_, count);
					count++;
					XmlAttributeCollection ^atr = node_2_->Attributes;
					for each(XmlAttribute^yo in atr)
					{
						if (yo != nullptr) GetTableAttribute(yo,count);
						count++;
					}
				}
			}
		}

		void AddTableAttrib(XmlAttribute ^atr){
			
			dataGridView1->DefaultCellStyle->BackColor = Color::LightGreen;
			int index = dataGridView1->Rows->Add(atr);
			DataGridViewCell^ cell = dataGridView1->Rows[index]->Cells[0];
			cell->Value = index;
			cell = dataGridView1->Rows[index]->Cells[1];
			cell->Value = atr->Name;
			cell->ToolTipText = "Имя атрибута";
			cell = dataGridView1->Rows[index]->Cells[2];
			cell->Value = atr->InnerText;
			cell->ToolTipText = "Значение атрибута";
		/*	dataGridView1->AllowUserToAddRows;
			dataGridView1->AllowUserToDeleteRows;*/
		}
		void AddTableRow(XmlNode^ xd, bool rflag){
			DataGridViewRow ^tmp=gcnew DataGridViewRow;
			if (rflag)
				tmp->DefaultCellStyle->BackColor = Color::LightGray; /*= Color::FromArgb(1, 1, 111, 0);*/
			else
				tmp->DefaultCellStyle->BackColor = Color::LightBlue;
			if (xd->Name == "#text") return;
			int index = dataGridView1->Rows->Add(tmp);
			DataGridViewCell^ cell = dataGridView1->Rows[index]->Cells[0];
			
			cell->Value = index;
			cell = dataGridView1->Rows[index]->Cells[1];
			cell->Value = xd->Name;
			cell->ToolTipText=xd->ParentNode->Name;
			cell = dataGridView1->Rows[index]->Cells[2];
			cell->ReadOnly=(rflag);
			
				if (rflag)
					cell->ToolTipText = "Нередактируемое поле";
				else 
					cell->ToolTipText = "Редактируемое поле";

			cell->Value = xd->InnerText;
			/*dataGridView1->AllowUserToAddRows;
			dataGridView1->AllowUserToDeleteRows;*/

		}
		void ProcessDom(XmlNode^xdoc)
		{
			if (xdoc == nullptr)return;
		
				AddTableRow(xdoc, 1);
				XmlAttributeCollection ^atr = xdoc->Attributes;
				if (atr != nullptr)
					for each(XmlAttribute^yo in atr)
					{
						AddTableAttrib(yo);
					}
				if (xdoc->FirstChild!=nullptr)
				ProcessDom(xdoc->FirstChild);
				if (xdoc->NextSibling != nullptr)
				ProcessDom(xdoc->NextSibling);
				
			//		ProcessDom(node->ChildNodes
				/*for each(XmlNode^ node_2_ in node_2)
				{
				AddTableRow(node_2_, 0);
				XmlAttributeCollection ^atr = node_2_->Attributes;
				for each(XmlAttribute^yo in atr)
				{
				if (yo != nullptr) AddTableAttrib(yo);


				}

				}*/


		}
		
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::Lavender;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(462, 218);
			this->button1->Margin = System::Windows::Forms::Padding(0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 25);
			this->button1->TabIndex = 0;
			this->button1->Text = L"  Загрузить XML";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button1_MouseMove);
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(580, 199);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->DividerWidth = 1;
			this->Column1->HeaderText = L"Номер";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Название";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"Значение";
			this->Column3->Name = L"Column3";
			this->Column3->ToolTipText = L"Информация содержащаяся в тэге";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::SystemColors::Control;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(342, 217);
			this->button2->Margin = System::Windows::Forms::Padding(0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 26);
			this->button2->TabIndex = 2;
			this->button2->Text = L"    Сохранить XML";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(604, 255);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->MinimumSize = System::Drawing::Size(400, 200);
			this->Name = L"MyForm";
			this->Text = L"XmlRead";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{

		OpenFileDialog ^dlg = gcnew OpenFileDialog();
		Stream^ myStream;
		dlg->Title = "Open XML";
		dlg->Filter = "Xml files(*.xml) | *.xml | All files(*.*) | *.*";
		dlg->InitialDirectory = "D:\\";
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = dlg->OpenFile()) != nullptr)
			{
				FileInfo^ finfo = gcnew FileInfo(dlg->FileName);

				if (!((finfo->Exists) && (finfo->Length != 0)))
				{
					MessageBox::Show("()()"); return;
				}
			

				FileStream^ fs = File::OpenRead(dlg->FileName);
				XmlReader ^xr = XmlReader::Create(fs);
				xd = nullptr;
				xd = gcnew XmlDocument;
				xd->Load(xr);
				dataGridView1->Rows->Clear();
				ProcessDom(xd->ChildNodes->Item(0));
				// Insert code to read the stream here.
				myStream->Close();
				fs->Close();

			}
		}
	}
	private: System::Void button1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	};
	private: System::Void webBrowser1_DocumentCompleted(System::Object^  sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (xd == nullptr){ MessageBox::Show("&&?"); Close(); }
		SaveFileDialog^ sd = gcnew SaveFileDialog;
		sd->Title = "Save Xml file";
		sd->Filter = "Text files(*.xml) | *.xml | All files(*.*) | *.*";
		sd->InitialDirectory = "D:\\";

		if (sd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
					FileInfo^ finfo = gcnew FileInfo(sd->FileName);
					
					FileStream^ fs = File::OpenWrite(sd->FileName);
					XmlWriter ^xr = XmlWriter::Create(fs);
					ParseDom(xd);
					xd->Save(xr);
					fs->Close();
		};
	}

		
	};
}
			