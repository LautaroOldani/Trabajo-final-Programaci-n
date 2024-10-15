#include <iostream>
#include <conio.h> 
#include <ctime>
#include <windows.h> 
#include <conio2.h>

using namespace std;

const int bordeSup = 2;
const int bordeIzq = 2;
const int bordeDer = 30;
const int bordeInf = 15;

class Pelota {
private:
	clock_t tempo;
	clock_t paso;
	int direccionX;
	int direccionY;
	int col;
	int x, y;
	int velocidad;
	
	void borrar() {
		gotoxy(x, y);
		textcolor(7);
		cout << ' ';
		textcolor(col);
	}
	
	void dibujar() const {
		gotoxy(x, y);
		cout << 'O';
	}
	
public:
		Nave(int vel, int color = WHITE) : velocidad(vel), col(color) {
			paso = CLOCKS_PER_SEC / velocidad;
			tempo = clock();
			direccionX = 1;
			direccionY = 1;
			x = rand() % (bordeDer - bordeIzq + 1) + bordeIzq;
			y = rand() % (bordeInf - bordeSup + 1) + bordeSup;
		}
		
		void start() {
			if (tempo + paso < clock()) {
				borrar();
				mover();
				dibujar();
				tempo = clock();
			}
		}
		
		void mover() {
			if (_kbhit()) {
				char tecla = _getch();
				switch (tecla) {
				case 'A': // Mover a la izquierda
					x -= velocidad;
					break;
				case 'D': // Mover a la derecha
					x += velocidad;
					break;
				case 'W': // Mover hacia arriba
					y -= velocidad;
					break;
				case 'S': // Mover hacia abajo
					y += velocidad;
					break;
				case 27: // Tecla ESC para salir
					exit(0);
				default:
					break;
				}
				
				
				if (x < bordeIzq) x = bordeIzq;
				if (x > bordeDer) x = bordeDer;
				if (y < bordeSup) y = bordeSup;
				if (y > bordeInf) y = bordeInf;
			}
		}
};

class Galaxia {
private:
	int filas;
	int columnas;
	
public:
	Galaxia(int f, int c) : filas(f), columnas(c) {}
	
	void dibujar() const {
		for (int i = 0; i < filas; ++i) {
			for (int j = 0; j < columnas; ++j) {
				if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1) {
					std::cout << "*";
				} else {
					std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
	}
};

Galaxia rectangulo(15, 30);

int main() {
	rectangulo.dibujar();
	Pelota p1(50, 1);
	
	while (true) {
		p1.start();
		Sleep(10); 
	}
	return 0;
}

