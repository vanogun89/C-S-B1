#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp> //boost version is 1.69.0
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <stdlib.h>
#include <cstdio>

namespace mult = boost::multiprecision;

mult::cpp_int pow(mult::cpp_int number, mult::cpp_int power)
{
	auto _number = number;
	while (--power)
	{
		number *= _number;
	}
	return number;
}

using namespace std;

void print_txt()
{
	system("cls");
	std::cout << "________________________________________________________________________________";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "         _____     _____      ___               _____               __   \n";
	std::cout << "        | ___ \\   /  ___|    / _ \\             | ___ \\             /  |    \n";
	std::cout << "        | |_/ /    \\ `--.   / /_\\ \\   ______   | |_/ /    ______   `| |  \n";
	std::cout << "        |  _ /      `--. \\  |  _  |  |______|  | ___ \\   |______|   | |  \n";
	std::cout << "        | | \\ \\   /\\__/ /   | | | |            | |_/ /             _| |_ \n";
	std::cout << "        \\_|  \\_|  \\____/    \\_| |_/            \\____/              \\___/ ";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "________________________________________________________________________________\n\n";
	std::cout << "  Криптографическая утилита создана исключительно для проектной деятельности.\n";
	std::cout << "\t\t Создатель - Панферов Иван Олегович. \n";
	system("color 0F");
	std::cout << "________________________________________________________________________________\n";
	std::cout << "                               |__ TERMINAL __|\n\n";
	std::cout << "  ";
}

int main()
{   
	SetConsoleTitleA("RSA-utility");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	std::string Login;
	int Password;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t\tПриветствуем вас в криптосистеме RSA-B-1" << "\n";
	std::cout << "______________________________________________________________________________";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t\t";
	std::cout << "Login: ";
	std::cin >> Login;
	std::cout << "\t\t";
	std::cout << "\n";
	std::cout << "\t\t";
	std::cout << "\n";
	std::cout << "\t\t";
	std::cout << "\n";
	std::cout << "\t\t";
	std::cout << "Password: ";
	std::cin >> Password;
	std::cout << "\t\t";
	std::cout << "\n";
	std::cout << "\t\t";
	std::cout << "\n";
	std::cout << "\n\t\t\t   Загрузка данных...\n";
	if (Login == "Project1519")
	{
		if (Password == 5797301)
		{
			print_txt();
			int flag;
			flag = 0;
			while (flag != 1)
			{
				std::string command;
				std::cin >> command;
				std::cout << "\n";
				if (command == "/rsaciph")
				{
					std::cout << "\n";
					std::cout << "->->->\tВведите сообщение:\t";
					char imput[1000];
					std::cin.getline(imput, 1000, '.');
					int size;
					size = strlen(imput);
					int position;
					position = 0;
					int p[6] = { 71, 51, 101, 71, 107, 47 };
				    int q[6] = { 59, 41, 83, 47, 101, 41 };
					int num;
					srand(time(0));
					num = rand() % 5;
					imput[size + 1] = '~';
					std::cout << "\n";
					while (position < size)
					{
						long n;
						n = p[num] * q[num];
						long φ;
						φ = (p[num] - 1) * (q[num] - 1);
						int e;
						e = 3;
						int k;
						long double d1;
						k = 1;
						d1 = 1 + (k*φ);
						d1 = d1 / e;
						while (d1 != floor(d1))
						{
							d1 = 1 + (k*φ);
							d1 = d1 / e;
							k++;
						}
						unsigned long long int d;
						d = d1;

						int yuwis;
						yuwis = 5;

						unsigned long long int information, resty;

						float nums, uo;
						information = abs(int(imput[position]));
						information = pow(information, e);
						resty = information;
						unsigned long long int secret;
						secret = information / n;
						information = secret * n;
						secret = resty - information;
						nums = position / yuwis;
						uo = nums * yuwis;
						if ((position - uo) == 0)
						{
							std::cout << "\n";
						}
						std::cout << "\t" << secret << " ";
						position++;
						num = num + 1;
						if (num == 6)
						{
							num = 0;
						}
					}
					std::cout << "\n\n->->->\tКриптограмма RSA получена...\n\n";
					std::cout << "  ";
				}
				if (command == "/exit")
				{
					flag++;
				}
				if (command == "/clean")
				{
					print_txt();

				}
				if (command == "/createfile")
				{
					std::cout << "->->->\tРасположение файла с именем и его расширением: ";
					std::string filename;
					std::cin >> filename;
					std::ofstream ofs(filename); 
					ofs.close();
					std::cout << "\n";
					std::cout << "->->->\tФайл был успешно создан...\n\n";
					std::cout << "  ";

				}
				if (command == "/deletefile")
				{
					std::cout << "->->->\tРасположение файла с именем и его расширением: ";
					std::string delfilename;
					std::cin >> delfilename;
					remove(delfilename.c_str());
					std::cout << "\n";
					std::cout << "->->->\tФайл был успешно удален...\n\n";
					std::cout << "  ";
				}
				if (command == "/rsaciphtxt")
				{
					std::ofstream file;
					std::string adress;
					std::cout << "->->->\tРасположение файла с именем и его расширением: ";
					std::cin >> adress;
					std::cout << "\n";
					file.open(adress);
					char imput[1000];
					std::cout << "->->->\tВведите сообщение:\t";
					std::cin.getline(imput, 1000, '.');
					int size;
					size = strlen(imput);
					int position;
					position = 0;
					int p[6] = { 71, 51, 101, 71, 107, 47 };
					int q[6] = { 59, 41, 83, 47, 101, 41 };
					int num;
					srand(time(0));
					num = rand() % 5;
					file << num;
					file << "\n";
					imput[size + 1] = '~';
					std::cout << "\n";
					while (position < size)
					{
						long n;
						n = p[num] * q[num];
						long φ;
						φ = (p[num] - 1) * (q[num] - 1);
						int e;
						e = 3;
						int k;
						long double d1;
						k = 1;
						d1 = 1 + (k*φ);
						d1 = d1 / e;
						while (d1 != floor(d1))
						{
							d1 = 1 + (k*φ);
							d1 = d1 / e;
							k++;
						}
						unsigned long long int d;
						d = d1;

						int yuwis;
						yuwis = 5;

						unsigned long long int information, resty;

						float nums, uo;
						information = abs(int(imput[position]));
						information = pow(information, e);
						resty = information;
						unsigned long long int secret;
						secret = information / n;
						information = secret * n;
						secret = resty - information;
						nums = position / yuwis;
						uo = nums * yuwis;
						if ((position - uo) == 0)
						{
							file << "\n";
						}
						file << "\t" << secret << " ";
						position++;
						num = num + 1;
						if (num == 6)
						{
							num = 0;
						}
						
					}
					file.close();
					std::cout << "\n->->->\tКриптограмма RSA.txt получена...\n\n";
					std::cout << "  ";
				}
				if (command == "/rsadeciphtxt")
				{
					std::ifstream defile;
					std::string adress;
					int num;
					int cub;
					std::cout << "->->->\tРасположение файла с именем и его расширением: ";
					std::cin >> adress;
					std::cout << "\n";
					defile.open(adress);
					char teus;
					std::string oop, heg;
					defile.get(teus);
					std::cout << "->->->\tВведите язык криптограммы(рус. или англ.): ";
					std::string language;
					std::cin >> language;
					std::cout << "\n";
					heg = teus;
					num = atoi(heg.c_str());
					std::cout << "\n";
					std::cout << "  ";
					int p[6] = { 71, 51, 101, 71, 107, 47 };
					int q[6] = { 59, 41, 83, 47, 101, 41 };
					do
					{
						long n;
						n = p[num] * q[num];
						long φ;
						φ = (p[num] - 1) * (q[num] - 1);
						int e;
						e = 3;
						int k;
						long double d1;
						k = 1;
						d1 = 1 + (k*φ);
						d1 = d1 / e;
						while (d1 != floor(d1))
						{
							d1 = 1 + (k*φ);
							d1 = d1 / e;
							k++;
						}
						unsigned long long int d;
						d = d1;
						defile >> oop;
						cub = atoi(oop.c_str());
						mult::cpp_int chisel, chisel1;
						chisel1 = pow(mult::cpp_int(cub), mult::cpp_int(d));
						chisel = chisel1 / n;
						chisel = chisel * n;
						chisel = chisel1 - chisel;
						num++;
						if (language == "/rus")
						{

							chisel = chisel - (2*chisel);
							std::cout << (char)chisel;
							if (num == 6)
							{
								num = 0;
							}
						}
						if (language == "/eng")
						{
							std::cout << (char)chisel;
							if (num == 6)
							{
								num = 0;
							}
						}
					} while (!defile.eof());
					std::cout << "\n\n->->->\tКриптограмма RSA.txt дешифрована...\n\n";
					std::cout << "  ";
				}
				if (command == "/help")
				{
					std::cout << "->->->\tВывод всех команд RSA-B-1: \n\n";
					std::cout << "\t\t";
					std::cout << "/rsaciph - получение криптограммы в терминале.\n\n";
					std::cout << "\t\t";
					std::cout << "/rsaciphtxt - запись криптограммы в .txt файл.\n\n";
					std::cout << "\t\t";
					std::cout << "/rsadeciphtxt - дешифрование из .txt файла.\n\n";
					std::cout << "\t\t";
					std::cout << "/createfile - создание файла.\n\n";
					std::cout << "\t\t";
					std::cout << "/deletefile - удаление файла\n\n";
					std::cout << "\t\t";
					std::cout << "/clean - очистка окна консоли.\n\n";
					std::cout << "\t\t";
					std::cout << "/exit - выход из программы.\n\n";
					std::cout << "->->->\tВывод одной подкоманды RSA-B-1: \n\n";
					std::cout << "\t";
					std::cout << "language: /rus or /eng - выбор языков считывания при дешифровании.\n\n";
					std::cout << "  ";
				}
				
			}
			
		}

		else
		{
			std::cout << "\n\t Неверно введены данные!\t Просьба перезайти в систему..." << std::endl;
			std::cout << "\n";
			system("PAUSE");
			return 0;
		}
	}
	else
	{
		std::cout << "\n\t Неверно введены данные!\t Просьба перезайти в систему..." << std::endl;
		std::cout << "\n";
		system("PAUSE");
		return 0;
	}
}