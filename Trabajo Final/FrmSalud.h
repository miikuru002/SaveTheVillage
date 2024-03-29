#pragma once
#include <ctime>
#include "Controlador.h"
#include "File.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmSalud
	/// </summary>
	public ref class FrmSalud : public System::Windows::Forms::Form
	{
	public:
		FrmSalud(int nenemigos, int naliados)
		{
			srand(time(NULL));
			InitializeComponent();
			//carga el buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//carga los bitmaps
			bmpMap = gcnew Bitmap("mapa1.png");
			bmpLider = gcnew Bitmap("lider2.png");
			bmpHabitante = gcnew Bitmap("habitante1.png");
			bmpAgente = gcnew Bitmap("agente.png");
			bmpVacuna = gcnew Bitmap("vacuna.png");
			bmpAliado = gcnew Bitmap("aliado.png");

			//File
			file = new File();
			file->readData();

			//carga el controlador
			controlador = new Controlador(bmpLider, bmpHabitante, bmpAgente, bmpAliado, file->getTime(), file->getHp(), nenemigos, naliados);

		}

	private:
		//SINTAXIS PARA EL BUFFER
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//BITMAPS
		Bitmap^ bmpMap;
		Bitmap^ bmpHabitante;
		Bitmap^ bmpLider;
		Bitmap^ bmpAgente;
		Bitmap^ bmpVacuna;
		Bitmap^ bmpAliado;

		//FILE
		File* file;

		//CONTROLADOR
		Controlador* controlador;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblScore;
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Timer^ timer2;


	private: System::Windows::Forms::Panel^ panel1;
	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~FrmSalud()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblScore = (gcnew System::Windows::Forms::Label());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmSalud::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblVidas);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->lblScore);
			this->panel1->Controls->Add(this->lblTiempo);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(718, 444);
			this->panel1->TabIndex = 0;
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Location = System::Drawing::Point(63, 38);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(13, 13);
			this->lblVidas->TabIndex = 5;
			this->lblVidas->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 38);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(36, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Vidas:";
			// 
			// lblScore
			// 
			this->lblScore->AutoSize = true;
			this->lblScore->Location = System::Drawing::Point(63, 25);
			this->lblScore->Name = L"lblScore";
			this->lblScore->Size = System::Drawing::Size(13, 13);
			this->lblScore->TabIndex = 3;
			this->lblScore->Text = L"0";
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Location = System::Drawing::Point(63, 12);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(13, 13);
			this->lblTiempo->TabIndex = 2;
			this->lblTiempo->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Score:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tiempo:";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FrmSalud::timer2_Tick);
			// 
			// FrmSalud
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 447);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmSalud";
			this->Text = L"Mundo: Salud";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmSalud::FrmSalud_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//CLEAR
		buffer->Graphics->Clear(Color::White); //limpia el lienzo/canvas

		//COLISION
		controlador->colision(buffer->Graphics);

		//MOVER
		controlador->moverTodo(buffer->Graphics);

		//DIBUJAR
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		controlador->dibujarTodo(buffer->Graphics, bmpLider, bmpHabitante, bmpAgente, bmpAliado, bmpVacuna);
		lblVidas->Text = "" + controlador->getLider()->getHp();
		lblScore->Text = "" + controlador->getLider()->getScore();
		lblTiempo->Text = "" + controlador->getTime();

		//CONDICION
		if (controlador->getLider()->getHp() == 0) {
			timer1->Enabled = false;
			MessageBox::Show("--------�PERDISTE!--------\nAcabaron con tus vidas :(");
			this->Close();
		}
		else if (controlador->getTime() == 0) {
			timer1->Enabled = false;
			MessageBox::Show("--------�PERDISTE!--------\nSe termin� el tiempo :(");
			this->Close();
		}
		else if (controlador->getLider()->getScore() >= 100) {
			timer1->Enabled = false;
			MessageBox::Show("--------�GANASTE!--------\nLograste salvar al pueblo :D");
			this->Close();
		}
		else {
			//RENDER
			buffer->Render(g);
		}
	}

	private: System::Void FrmSalud_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Aliado* a;
		Bala* b;

		switch (e->KeyCode) {

		case Keys::A: case Keys::Left:
			controlador->getLider()->mover(buffer->Graphics, 'A');
			break;

		case Keys::D: case Keys::Right:
			controlador->getLider()->mover(buffer->Graphics, 'D');
			break;

		case Keys::W: case Keys::Up:
			controlador->getLider()->mover(buffer->Graphics, 'W');
			break;

		case Keys::S: case Keys::Down:
			controlador->getLider()->mover(buffer->Graphics, 'S');
			break;

		case Keys::P:
			a = new Aliado(bmpAliado->Width / 4, bmpAliado->Height / 4, 2);
			controlador->generarAliado(a);
			break;


		case Keys::Space:
			b = new Bala(bmpVacuna->Width, bmpVacuna->Height,
				controlador->getLider()->getX(), controlador->getLider()->getY(), controlador->getLider()->getDireccion());
			controlador->disparar(b);
			break;
		}
	}

	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		controlador->decreaseTime();
	}
};
}
