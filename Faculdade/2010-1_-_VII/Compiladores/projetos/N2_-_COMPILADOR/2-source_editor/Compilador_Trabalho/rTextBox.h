#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Compilador_Trabalho {

	/// <summary>
	/// Summary for rTextBox
	/// </summary>
	public ref class rTextBox : public System::Windows::Forms::UserControl
	{
	public:
		rTextBox(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~rTextBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected: 
	private: System::Windows::Forms::Label^  numberLabel;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;

	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->numberLabel = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(513, 405);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->WordWrap = false;
			this->richTextBox1->VScroll += gcnew System::EventHandler(this, &rTextBox::richTextBox1_VScroll);
			this->richTextBox1->Resize += gcnew System::EventHandler(this, &rTextBox::richTextBox1_Resize);
			this->richTextBox1->FontChanged += gcnew System::EventHandler(this, &rTextBox::richTextBox1_FontChanged);
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &rTextBox::richTextBox1_TextChanged);
			// 
			// numberLabel
			// 
			this->numberLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numberLabel->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->numberLabel->Location = System::Drawing::Point(3, 0);
			this->numberLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numberLabel->Name = L"numberLabel";
			this->numberLabel->Size = System::Drawing::Size(37, 267);
			this->numberLabel->TabIndex = 1;
			this->numberLabel->Text = L"1\r\n2\r\n3\r\n4\r\n5\r\n6\r\n7\r\n8\r\n9\r\n10\r\n11\r\n12\r\n13\r\n14\r\n15\r\n16";
			this->numberLabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->numberLabel);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->richTextBox1);
			this->splitContainer1->Size = System::Drawing::Size(555, 405);
			this->splitContainer1->SplitterDistance = 41;
			this->splitContainer1->SplitterWidth = 1;
			this->splitContainer1->TabIndex = 1;
			// 
			// rTextBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->splitContainer1);
			this->DoubleBuffered = true;
			this->Name = L"rTextBox";
			this->Size = System::Drawing::Size(555, 405);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		private: void updateNumberLabel(void)
				 {
					 Point pos (0, 0);
					 int firstIndex = richTextBox1->GetCharIndexFromPosition(pos);
					 int firstLine = richTextBox1->GetLineFromCharIndex(firstIndex);

					 pos.X = ClientRectangle.Width;
					 pos.Y = ClientRectangle.Height;
					 int lastIndex = richTextBox1->GetCharIndexFromPosition(pos);
					 int lastLine = richTextBox1->GetLineFromCharIndex(lastIndex);

					 pos = richTextBox1->GetPositionFromCharIndex(lastIndex);
					 
					 String^ s = L"";

					 for (int i = firstLine; i <= lastLine + 1; i++)
					 {
					 	 s += i + 1 + "\n";
					 }

					 numberLabel->Text = s;
				 }

		private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
				{


					updateNumberLabel();
				}

		private: System::Void richTextBox1_VScroll(System::Object^  sender, System::EventArgs^  e) {
					int d = richTextBox1->GetPositionFromCharIndex(0).Y % (richTextBox1->Font->Height + 1);
					numberLabel->Location = Point(0, d);

					updateNumberLabel();
				}

		private: System::Void richTextBox1_Resize(System::Object^  sender, System::EventArgs^  e) {
					richTextBox1_VScroll(nullptr, nullptr);
				}

		private: System::Void richTextBox1_FontChanged(System::Object^  sender, System::EventArgs^  e) {
					updateNumberLabel();
					richTextBox1_VScroll(nullptr, nullptr);
				}

		public: virtual property System::String^ Text
				{
					System::String^ get() override
					{
						return (this->richTextBox1->Text);
					}

					void set (System::String^ value) override
					{
						this->richTextBox1->Text = value;
					}
				}
	};
}
