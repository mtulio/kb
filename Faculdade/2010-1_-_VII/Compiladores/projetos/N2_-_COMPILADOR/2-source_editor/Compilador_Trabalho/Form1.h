#pragma once




namespace Compilador_Trabalho {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menu;
	protected: 

	private: System::Windows::Forms::ToolStripMenuItem^  arquivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  salvarCtrlSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirCtrlOToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: Compilador_Trabalho::rTextBox^  richTextBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  salvarComoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ferramentasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  compilarToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;









	private: System::Windows::Forms::ToolStripMenuItem^  novoCtrlNToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::ToolStripButton^  newToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  openToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  saveToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  compilarToolStripButton;
	private: System::Windows::Forms::ToolStripMenuItem^  caminhoDoCompiladorToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;








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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->arquivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->novoCtrlNToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salvarCtrlSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salvarComoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirCtrlOToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ferramentasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compilarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->caminhoDoCompiladorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ajudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->newToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->openToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->compilarToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew Compilador_Trabalho::rTextBox());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menu->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->arquivoToolStripMenuItem, 
				this->ferramentasToolStripMenuItem, this->ajudaToolStripMenuItem});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(496, 24);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menuStrip";
			// 
			// arquivoToolStripMenuItem
			// 
			this->arquivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->novoCtrlNToolStripMenuItem, 
				this->salvarCtrlSToolStripMenuItem, this->salvarComoToolStripMenuItem, this->abrirCtrlOToolStripMenuItem, this->sairToolStripMenuItem});
			this->arquivoToolStripMenuItem->Name = L"arquivoToolStripMenuItem";
			this->arquivoToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->arquivoToolStripMenuItem->Text = L"Arquivo";
			// 
			// novoCtrlNToolStripMenuItem
			// 
			this->novoCtrlNToolStripMenuItem->Name = L"novoCtrlNToolStripMenuItem";
			this->novoCtrlNToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->novoCtrlNToolStripMenuItem->Size = System::Drawing::Size(213, 22);
			this->novoCtrlNToolStripMenuItem->Text = L"Novo";
			this->novoCtrlNToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::novoToolStripMenuItem_Click);
			// 
			// salvarCtrlSToolStripMenuItem
			// 
			this->salvarCtrlSToolStripMenuItem->Name = L"salvarCtrlSToolStripMenuItem";
			this->salvarCtrlSToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->salvarCtrlSToolStripMenuItem->Size = System::Drawing::Size(213, 22);
			this->salvarCtrlSToolStripMenuItem->Text = L"Salvar";
			this->salvarCtrlSToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::salvarToolStripMenuItem_Click);
			// 
			// salvarComoToolStripMenuItem
			// 
			this->salvarComoToolStripMenuItem->Name = L"salvarComoToolStripMenuItem";
			this->salvarComoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->salvarComoToolStripMenuItem->Size = System::Drawing::Size(213, 22);
			this->salvarComoToolStripMenuItem->Text = L"Salvar Como";
			this->salvarComoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::salvarComoToolStripMenuItem_Click);
			// 
			// abrirCtrlOToolStripMenuItem
			// 
			this->abrirCtrlOToolStripMenuItem->Name = L"abrirCtrlOToolStripMenuItem";
			this->abrirCtrlOToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->abrirCtrlOToolStripMenuItem->Size = System::Drawing::Size(213, 22);
			this->abrirCtrlOToolStripMenuItem->Text = L"Abrir";
			this->abrirCtrlOToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::abrirToolStripMenuItem_Click);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->sairToolStripMenuItem->Size = System::Drawing::Size(213, 22);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sairToolStripMenuItem_Click);
			// 
			// ferramentasToolStripMenuItem
			// 
			this->ferramentasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->compilarToolStripMenuItem, 
				this->caminhoDoCompiladorToolStripMenuItem});
			this->ferramentasToolStripMenuItem->Name = L"ferramentasToolStripMenuItem";
			this->ferramentasToolStripMenuItem->Size = System::Drawing::Size(84, 20);
			this->ferramentasToolStripMenuItem->Text = L"Ferramentas";
			// 
			// compilarToolStripMenuItem
			// 
			this->compilarToolStripMenuItem->Name = L"compilarToolStripMenuItem";
			this->compilarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::E));
			this->compilarToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->compilarToolStripMenuItem->Text = L"Compilar";
			this->compilarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::compilarToolStripMenuItem_Click);
			// 
			// caminhoDoCompiladorToolStripMenuItem
			// 
			this->caminhoDoCompiladorToolStripMenuItem->Name = L"caminhoDoCompiladorToolStripMenuItem";
			this->caminhoDoCompiladorToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->caminhoDoCompiladorToolStripMenuItem->Text = L"Caminho do Compilador";
			this->caminhoDoCompiladorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::caminhoDoCompiladorToolStripMenuItem_Click);
			// 
			// ajudaToolStripMenuItem
			// 
			this->ajudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->sobreToolStripMenuItem});
			this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			this->ajudaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->ajudaToolStripMenuItem->Text = L"Ajuda";
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(104, 22);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sobreToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 386);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(496, 22);
			this->statusStrip1->TabIndex = 2;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Visible = false;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->newToolStripButton, 
				this->openToolStripButton, this->saveToolStripButton, this->compilarToolStripButton});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(496, 25);
			this->toolStrip1->TabIndex = 3;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// newToolStripButton
			// 
			this->newToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->newToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newToolStripButton.Image")));
			this->newToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->newToolStripButton->Name = L"newToolStripButton";
			this->newToolStripButton->Size = System::Drawing::Size(23, 22);
			this->newToolStripButton->Text = L"&Novo";
			this->newToolStripButton->Click += gcnew System::EventHandler(this, &Form1::novoToolStripMenuItem_Click);
			// 
			// openToolStripButton
			// 
			this->openToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->openToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripButton.Image")));
			this->openToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openToolStripButton->Name = L"openToolStripButton";
			this->openToolStripButton->Size = System::Drawing::Size(23, 22);
			this->openToolStripButton->Text = L"&Abrir";
			this->openToolStripButton->Click += gcnew System::EventHandler(this, &Form1::abrirToolStripMenuItem_Click);
			// 
			// saveToolStripButton
			// 
			this->saveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripButton.Image")));
			this->saveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripButton->Name = L"saveToolStripButton";
			this->saveToolStripButton->Size = System::Drawing::Size(23, 22);
			this->saveToolStripButton->Text = L"&Salvar";
			this->saveToolStripButton->Click += gcnew System::EventHandler(this, &Form1::salvarToolStripMenuItem_Click);
			// 
			// compilarToolStripButton
			// 
			this->compilarToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->compilarToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"compilarToolStripButton.Image")));
			this->compilarToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->compilarToolStripButton->Name = L"compilarToolStripButton";
			this->compilarToolStripButton->Size = System::Drawing::Size(23, 22);
			this->compilarToolStripButton->Text = L"&Compilar";
			this->compilarToolStripButton->Click += gcnew System::EventHandler(this, &Form1::compilarToolStripMenuItem_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"por";
			this->saveFileDialog1->Filter = L"Arquivo de Texto (*.txt)|*.txt|Arquivo POR (*.por)|*.por|Todos Arquivos (*.*)|*.*" 
				L"";
			this->saveFileDialog1->FilterIndex = 2;
			this->saveFileDialog1->Title = L"Salvar Arquivo";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Arquivo de Texto (*.txt)|*.txt|Arquivo POR (*.por)|*.por|Todos Arquivos (*.*)|*.*" 
				L"";
			this->openFileDialog1->FilterIndex = 2;
			this->openFileDialog1->Title = L"Abrir Arquivo";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->richTextBox2);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->groupBox1->Location = System::Drawing::Point(0, 265);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(496, 121);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Log";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox2->Location = System::Drawing::Point(12, 19);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(478, 96);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(0, 52);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(496, 207);
			this->richTextBox1->TabIndex = 1;
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->DefaultExt = L"exe";
			this->openFileDialog2->FileName = L"Automato";
			this->openFileDialog2->Filter = L"Arquivo Executável (*.exe)|*.exe";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 408);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menu);
			this->MainMenuStrip = this->menu;
			this->Name = L"Form1";
			this->Text = L"Editor - Compilador";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Interface Gráfica
	private: bool salvo;
	private: bool modificado;
	private: bool RecemAberto;
	private: System::String^ arquivo;
	private: System::String^ arquivoCompilador;
	private: System::String^ nomeArquivo;

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			
					arquivo = String::Empty;
					arquivoCompilador = String::Empty;
					modificado = false;
			 }

	private: System::Void novoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
					if (richTextBox1->Text != String::Empty && salvo == false)
					{
						if (MessageBox::Show("Tem certeza que deseja prosseguir?\r\nOs dados não salvos serão perdidos.", "Aviso", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
						{
							arquivo = "";
							salvo = false;
							modificado = false;
							RecemAberto = false;
							richTextBox1->Text = String::Empty;
							this->Text = "Compilador";
						}
					}
					else
					{
						arquivo = "";
						salvo = false;
						modificado = false;
						RecemAberto = false;
						richTextBox1->Text = String::Empty;
						this->Text = "Compilador";
					}
			 }

	private: void salvar()
			 {
				 System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(arquivo);

				 try
				 {
					if (sw != nullptr)
					{
						sw->Write(richTextBox1->Text);
						sw->Flush();
						sw->Close();
						salvo = true;
						modificado = false;
						this->Text = "Compilador (" + System::IO::Path::GetFileName(arquivo) + ")";
						toolStripStatusLabel1->Text = "Alterações foram salvas";
						toolStripStatusLabel1->Visible = true;
					}
				 }
				 catch (...)
				 {
					MessageBox::Show("Problema ao gravar o arquivo.\r\nChecar permissão de arquivo e/ou pasta.", "Erro",
					    			MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			 }

	private: void salvarArquivo(bool tipo) {
					//
					// Tipos:
					// true-> salvar
					// false-> salvar como 
					//
				    if (tipo)
					{
						if (arquivo != String::Empty)
							salvo = true;
					}
					else
					{
						salvo = false;
					}

					if (salvo == false)
					{
						if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
						{
							arquivo = saveFileDialog1->FileName;
							salvar();
						}
					}
					else
					{
						salvar();
					}
			     }

	private: void compilar() {
				 richTextBox2->Text = "";
				 Process^ comp = gcnew Process;
				 ProcessStartInfo^ compStartInfo = gcnew ProcessStartInfo(arquivoCompilador, arquivo);
				 compStartInfo->UseShellExecute = false;
				 compStartInfo->RedirectStandardOutput = true;
				 compStartInfo->RedirectStandardError = true;
				 compStartInfo->CreateNoWindow = true;
				 comp->StartInfo = compStartInfo;
				 comp->Start();

				 StreamReader^ sr = comp->StandardOutput;
				 StreamReader^ sr2 = comp->StandardError;
				 richTextBox2->Text += sr->ReadToEnd();
				 richTextBox2->Text += sr2->ReadToEnd();
				 comp->Close();
			 }

	private: System::Void salvarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				
					salvarArquivo(true);
			 }

	private: System::Void salvarComoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

					salvarArquivo(false);
			 }

	private: System::Void abrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					
					if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						try
						{
							System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);
							arquivo = openFileDialog1->FileName;
							richTextBox1->Text = sr->ReadToEnd();
							sr->Close();
							modificado = false;
							salvo = false;
							RecemAberto = true;
							this->Text = "Compilador (" + System::IO::Path::GetFileName(arquivo) + ")";
						}
						catch (...)
						{
							MessageBox::Show("Problema ao gravar o arquivo.\r\nChecar permissão de arquivo e/ou pasta.", "Erro",
											MessageBoxButtons::OK, MessageBoxIcon::Error);
						}
					}
			 }
			 
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
					if (modificado)
					{
						if (MessageBox::Show("Tem certeza que deseja prosseguir?\r\nOs dados não salvos serão perdidos.", "Aviso", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Cancel)
							e->Cancel = true;
					}
			 }
		     
	private: System::Void richTextBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
					if (modificado == false)
					{
						modificado = true;
						if (this->Text != "Compilador")
							this->Text += "*";
						toolStripStatusLabel1->Visible = false;
					}
			 }
		     
	private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					this->Close();
			 }
			 
	private: System::Void sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 MessageBox::Show("Trabalho de Compilador\r\n" +
									"Versão: 1.0\r\n\r\n\r\n" +
									"Integrantes:\r\n" +
									"Gustavo de Andrade Rosa\r\n" +
									"Juliane Barbosa Maximo \r\n" +
									"Marco Túlio Rodrigues Braga \r\n" +
									"Adão Junior \r\n" +
									"Marcus Vinissius Costa Rodrigues \r\n" +
									"Marco Aurélio de Faria. \r\n\r\n" +
									"© 2010"
									, "Sobre", MessageBoxButtons::OK, MessageBoxIcon::Information);
		     }

			 private: System::Void caminhoDoCompiladorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
						
							if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
							{
								arquivoCompilador = openFileDialog2->FileName;
							}
					  }

#pragma endregion

	private: System::Void compilarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
					//Compilador AQUI
				 /*System::Diagnostics::ProcessStartInfo^ si = gcnew System::Diagnostics::ProcessStartInfo ();
				 
				 System::Diagnostics::Process p = System::Diagnostics::Process::Start ();*/
				 
				 //variável para checar se está ok
				 bool ok = false;
				 

				 if (salvo || RecemAberto)
					 salvarToolStripMenuItem_Click(nullptr, nullptr);
				 else
					salvarComoToolStripMenuItem_Click(nullptr, nullptr);

				 if (salvo == true && modificado == false) //verfica se está salvo mas modificado
				 {
					 ok = true;
				 }
				 
				 if (ok)
				 {
					 if (System::IO::File::Exists("Automato.exe"))
					 {
						 arquivoCompilador = "Automato.exe";
						 compilar();
					 }
					 else if (System::IO::File::Exists(arquivoCompilador))
					 {
						 compilar();
					 }
					 else
					 {
						 MessageBox::Show("Caminho para o compilador não encontrado.\r\nFavor selecionar no próximo dialog o caminho correto.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
						 caminhoDoCompiladorToolStripMenuItem_Click(nullptr, nullptr);
					 }
				 }
				 else
				 {
					 MessageBox::Show("O arquivo não foi salvo.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }

		     }

};
}

