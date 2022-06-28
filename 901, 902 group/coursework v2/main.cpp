#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Exception_ReplicaNotProcessed : public exception {
	const char* what() const throw() { return "Никто не смог обработать реплику (неверный номер)"; }
};

class fileNotOpened : public exception {
public:
	const char* what() const throw() { return "File not opened!"; }
};

// Общий класс для файлов
class File {
public:
	virtual void openFile() = 0;
	virtual void closeFile() = 0;
};

// Класс для текстовых файлов
class TextFile : public File {
public:

	TextFile(string name) :filename(name) {}
	TextFile(const char* name) :filename(name) {}
	TextFile(char* name) :filename(name) {}

	// Открывает файл для последующей обработки
	void openFile() {
		file.open(filename.c_str());
		if (!file.is_open()) {
			fileNotOpened e;
			throw e;
		}
	}


	// Закрывает работу с файлом (по окончании оброаботки)
	void closeFile() {
		file.close();
	}

	// Получает следующий символ из файла
	bool getNextChar(char& ch) {
		if (!file.get(ch)) {
			return false;
		}
		return true;
	}

private:
	string filename; // Имя файла
	ifstream file;   // Текстовый файл
};

// Класс обработчика содержимого текстового файла
class TextFileProcessor : public TextFile {
public:
	TextFileProcessor(string filename) : TextFile(filename) { }
	TextFileProcessor(char* filename) : TextFile(filename) { }
	TextFileProcessor(const char* filename) : TextFile(filename) { }

	virtual void processFile() = 0;

	string getFileContent() { return fileContent; }
	void setFileContent(string fileContent) { this->fileContent = fileContent; }

private:
	string fileContent; // Содержимое файла в виде строки
};

// Класс сценария
class Script : public TextFileProcessor {
public:
	/* КОНСТРУКТОРЫ/ДЕСТРУКТОРЫ */
	Script() : TextFileProcessor("commands.txt") { prepareScript(); }
	Script(string scriptFileName) : TextFileProcessor(scriptFileName) { prepareScript(); }
	Script(char* scriptFileName) : TextFileProcessor(scriptFileName) { prepareScript(); }
	Script(const char* scriptFileName) : TextFileProcessor(scriptFileName) { prepareScript(); }
	~Script() { }
	/* КОНСТРУКТОРЫ/ДЕСТРУКТОРЫ END */

	/* МЕТОДЫ */
	int getCommand(int num) {
		return commands[num];
	}

	int size() {
		return commands.size();
	}
	/* МЕТОДЫ END */

private:
	vector <int> commands; // Команды из сценария в виде чисел

	// Получает содержимое файла в виде строки
	// Исключает из строки все символы, кроме цифр 0-9, символа переноса строки (\n), символа терминального нуля (\0)
	// Все цифры в одной строке конкатенируются. Все символы после знака комментария (точка с запятой) ";" игнорируются
	void processFile() {
		string fileContent = getFileContent(); // Содержимое файла сценария в виде строки
		char ch;
		while (getNextChar(ch)) {
			if (ch != '0' &&				   // Если текущий сивол - не число и не символ переноса/окончания строки
				ch != '1' &&
				ch != '2' &&
				ch != '3' &&
				ch != '4' &&
				ch != '5' &&
				ch != '6' &&
				ch != '7' &&
				ch != '8' &&
				ch != '9' &&
				ch != '\n' &&
				ch != '\0') {
				if (ch == ';') { // Пропуск всего, что стоит после точки с запятой (до символа переноса строки)
					while (ch != '\n') {
						if (!getNextChar(ch))
							break;
					}
					fileContent += '\n';
				}
				continue;
			}
			fileContent += ch;
		}

		setFileContent(fileContent);
	}

	// Получает готовые команды в виде чисел из строки с числами, разделенными символами переноса строки ('\n')
	void extractCommands() {
		string fileContent = getFileContent();
		string row;				// Переменная для хранения строк символов (до \n)
		int commandsNum = 0;	// Количество команд
		int command;			// Переменная для хранения команды, полученной из строки
		for (int i = 0; i < fileContent.length() + 1; i++) {
			row += fileContent[i];
			if (fileContent[i] == '\n' || fileContent[i] == '\0') {
				if (command = atoi(row.c_str())) {
					commandsNum++;
					//commands.resize(commandsNum);
					commands.push_back(command);
				}
				row.clear();
				continue;
			}
		}
	}

	void prepareScript() {
		try {
			openFile();
			processFile();
			extractCommands();
			closeFile();
		}
		catch (exception & e) {
			cout << "Error: " << e.what() << endl;
		}
	}
};

class Manager;

class Actor {
public:
	/* КОНСТРУКТОРЫ */
	Actor(const char* name, Actor* next = 0) {
		setName(name);
		setNextActor(next);
	}
	Actor(string name, Actor* next = 0) {
		setName(name);
		setNextActor(next);
	}
	/* КОНСТРУКТОРЫ END */


	// Метод - обертка, который вызывается у актера
	// Метод передаст необработанную реплику следующему актеру
	void handleRequest(int replica_id) {
		if (!processReplica(replica_id)) {			// Если реплика не была обработана
			if (nextActor == 0) {					// Если следующего актера нет (текущий - последний) и реплика не была обработана
				Exception_ReplicaNotProcessed e;	// То бросается исключение об этом
				throw e;
			}
			else {									// Иначе необработанная реплика передается следующему актеру
				nextActor->handleRequest(replica_id);
			}
		}
	}

	void say(const char* phrase) {
		cout << getName() << ": \"" << phrase << "\"" << endl;
	}

	void action(const char* action) {
		cout << getName() << ": *" << action << "*" << endl;
	}

	/* ГЕТТЕРЫ/СЕТТЕРЫ */
	void		setName(string newName) { name = newName; }
	void		setName(char* newName) { name = newName; }
	void		setNextActor(Actor* next) { nextActor = next; }
	string		getName() { return name; }
	/* ГЕТТЕРЫ/СЕТТЕРЫ END */
private:
	string name;			  //Имя актера
	Actor* nextActor;	      // Актер, который идет следующий в цеопчке ответственности

protected:
	// Обработка реплики
	// Здесь задается вся логика реакций актера на различные реплики
	virtual bool processReplica(int replica_id) = 0;

};

class Father : public Actor {
public:
	Father(Actor* next = 0) : Actor("Отец", next) { son = 0; }
	friend Manager;
private:
	Actor* son;

	bool processReplica(int replica_id) {
		switch (replica_id) {
		case 11: sayOtpravil(); break;
		case 15: sayAcip(); break;
		case 231: whoIsYourSon(); break;
		default: return false; break;
		}
		return true;
	}

	void sayOtpravil() { action("Отправил Ивана в поле"); }
	void sayAcip() { action("Дал седло и саблю"); }


	void whoIsYourSon() {
		string answer = "";
		answer.append("Мой сын: ");
		answer.append(son->getName());
		say(answer.c_str());
	}
};

class Ivan : public Actor {
public:
	Ivan(Actor* next = 0) : Actor("Иван", next) { father = 0; }
	friend Manager;
private:
	Actor* father;
	vector <Actor*> companions;

	bool processReplica(int replica_id) {
		switch (replica_id) {
		case 22: sayGopole(); break;
		case 23: sayKill(); break;
		case 24: sayAciphelp(); break;
		case 26: sayGoznak(); break;
		case 211: sayHelloIlly(); break;
		case 216: sayHelloFedor(); break;
		case 217: sayPrival(); break;

		case 220: sayDefeatposol(); break;
		case 228: sayVinDobriny(); break;
		case 232: whoIsYourFather(); break;
		default: return false; break;
		}
		return true;
	}

	void sayGopole() { action("Пошел в поле"); }
	void sayKill() { action("Убивает мошек и возвращается домой"); }
	void sayAciphelp() { say("Давайте мне полог и седло, а ты, батюшка, давай саблю, котора у тебя висит — на стене заржавела. Что я за мужик! У меня ничего нет."); }
	void sayGoznak() { action("Приезжает к столбу и оставляет надпись."); }
	void sayHelloIlly() { say("Здорово, Илюха!"); }
	void sayHelloFedor() { say("Здорово, Федюнька!"); }
	void sayPrival() { action("Разбил привал на лугах царя с Ильей и Федором."); }
	void sayDefeatposol() { action("Прогоняет посла и требует от Царя в жены его дочь!"); }
	void sayVinDobriny() { action("Отрубает голову Добрыне"); }

	void addCompanion(Actor* newCompanion) { companions.push_back(newCompanion); }

	void whoIsYourFather() {
		string answer = "";
		answer.append("Мой отец: ");
		answer.append(father->getName());
		say(answer.c_str());
	}
};

class Illy : public Actor {
public:
	Illy(Actor* next = 0) : Actor("Илья Муромец", next) {}
	friend Manager;
private:
	vector <Actor*> companions;

	bool processReplica(int replica_id) {
		switch (replica_id) {
		case 37: sayRides(); break;
		case 38: saySay(); break;
		case 39: sayGoivan(); break;
		case 310: saySayIlly(); break;
		case 322: sayFight(); break;
		default: return false; break;
		}
		return true;
	}

	void sayRides() { action("Читает надпись"); }
	void saySay() { say("Ба, проехал сильный, могучий богатырь: ослушаться не годно."); }
	void sayGoivan() { action("Догнал Ивана"); }
	void saySayIlly() { say("Здравствуй, сильный, могучий богатырь!"); }
	void sayFight() { action("Бьет рать"); }

	void addCompanion(Actor* newCompanion) { companions.push_back(newCompanion); }
};

class Fedor : public Actor {
public:
	Fedor(Actor* next = 0) : Actor("Федор Лыжников", next) {}
	friend Manager;
private:
	vector <Actor*> companions;

	bool processReplica(int replica_id) {
		switch (replica_id) {
		case 412: sayRides(); break;
		case 413: saySay(); break;
		case 414: sayGoivan(); break;

		case 415: saySayFedor(); break;
		case 424: sayFight(); break;
		default: return false; break;
		}
		return true;
	}

	void sayRides() { action("Читает надпись"); }
	void saySay() { say("Илья Муромец проехал, ослушаться не гоже."); }
	void sayGoivan() { action("Догнал Ивана"); }
	void saySayFedor() { say("Здравствуй, сильный, могучий богатырь!"); }
	void sayFight() { action("Бьет рать"); }

	void addCompanion(Actor* newCompanion) { companions.push_back(newCompanion); }
};

class King : public Actor {
public:
	King(Actor* next = 0) : Actor("Царь", next) {}
private:
	bool processReplica(int replica_id) {
		switch (replica_id) {
		case 518: saySize(); break;


		case 519: sayPosol(); break;
		case 521: sayRatone(); break;
		case 523: sayRattwo(); break;
		case 525: sayDobriny(); break;
		case 529: sayStrax(); break;
		case 530: saySvadba(); break;
		default: return false; break;
		}
		return true;
	}

	void saySize() { action("Видит богатырей и гневается."); }
	void sayPosol() { action("Отправляет посла"); }
	void sayRatone() { action("Шлет рать"); }
	void sayRattwo() { action("Шлет еще больше рать"); }
	void sayDobriny() { action("Зовет на помощь Добрыню"); }
	void sayStrax() { say("Ох, богатырь убил Добрыню; беда теперя! Ступайте скорее, зовите богатыря во дворец."); }
	void saySvadba() { action("Выдает за Ивана дочь"); }
};

class Dobriny : public Actor {
public:
	Dobriny(Actor* next = 0) : Actor("Добрыня", next) {}
private:
	bool processReplica(int replica_id) {
		switch (replica_id) {
		case 626: saySmex(); break;
		case 627: saySay(); break;
		default: return false; break;
		}
		return true;
	}

	void saySmex() { action("Смеется с Ивана"); }
	void saySay() { say(" Что это за сильный, могучий богатырь? Маленький, худенький! "); }
};

class Manager : public Actor {
public:
	Manager(Actor* next = 0) : Actor("Менеджер", next) {
		father = 0;
		ivan = 0;
		illy = 0;
		fedor = 0;
	}

	void setTroupe(vector <Actor*>* troupe) {
		this->troupe = troupe;
		findActors();
	}

private:
	vector <Actor*>* troupe;
	Father* father;
	Ivan* ivan;
	Illy* illy;
	Fedor* fedor;

	bool processReplica(int replica_id) {
		switch (replica_id) {
		case 1: start(); break;
		case 233: illyJoinsIvan(); break;
		case 234: fedorJoinsIvan(); break;
		default: return false; break;
		}
		return true;
	}

	void findActors() {
		for (int i = 0; i < troupe->size(); i++) {
			if (troupe->data()[i]->getName() == "Отец") {
				father = (Father*)troupe->data()[i];
			}
			else if (troupe->data()[i]->getName() == "Иван") {
				ivan = (Ivan*)troupe->data()[i];
			}
			else if (troupe->data()[i]->getName() == "Илья Муромец") {
				illy = (Illy*)troupe->data()[i];
			}
			else if (troupe->data()[i]->getName() == "Федор Лыжников") {
				fedor = (Fedor*)troupe->data()[i];
			}
		}
	}

	void start() {
		father->son = ivan;
		ivan->father = father;
	}

	void illyJoinsIvan() {
		ivan->addCompanion(illy);
		illy->addCompanion(ivan);
	}

	void fedorJoinsIvan() {
		ivan->addCompanion(fedor);
		fedor->addCompanion(ivan);


		illy->addCompanion(fedor);
		fedor->addCompanion(illy);
	}
};
// Абстрактная фабрика набора актеров
class AbstractActorFactory {
public:
	virtual Actor* createActor(Actor* next) = 0;
};

class FatherFactory : public AbstractActorFactory {
public:
	Actor* createActor(Actor* next = 0) { return new Father(next); }
};

class IvanFactory : public AbstractActorFactory {
public:
	Actor* createActor(Actor* next = 0) { return new Ivan(next); }
};

class IllyFactory : public AbstractActorFactory {
public:
	Actor* createActor(Actor* next = 0) { return new Illy(next); }
};

class FedorFactory : public AbstractActorFactory {
public:
	Actor* createActor(Actor* next = 0) { return new Fedor(next); }
};

class KingFactory : public AbstractActorFactory {
public:
	Actor* createActor(Actor* next = 0) { return new King(next); }
};

class DobrinyFactory : public AbstractActorFactory {
public:
	Actor* createActor(Actor* next = 0) { return new Dobriny(next); }
};

class ManagerFactory : public AbstractActorFactory {
public:
	Actor* createActor(Actor* next = 0) { return new Manager(next); }
};

// Фабрика конкретного актеров
class TroupeCreateor {
public:
	Actor* createFather(Actor* next = 0) { return father_f.createActor(next); }
	Actor* createIvan(Actor* next = 0) { return ivan_f.createActor(next); }
	Actor* createIlly(Actor* next = 0) { return illy_f.createActor(next); }
	Actor* createFedor(Actor* next = 0) { return fedor_f.createActor(next); }
	Actor* createKing(Actor* next = 0) { return king_f.createActor(next); }
	Actor* createDobriny(Actor* next = 0) { return dobriny_f.createActor(next); }
	Actor* createManager(Actor* next = 0) { return manager_f.createActor(next); }
private:
	FatherFactory father_f;
	IvanFactory ivan_f;
	IllyFactory illy_f;
	FedorFactory fedor_f;
	KingFactory king_f;
	DobrinyFactory dobriny_f;
	ManagerFactory manager_f;
};

// Абстрактный театр
class AbstractTheatre {
public:
	virtual void play() = 0;
};

// Конкретный театр со своими актерами и сценарием
class Theatre : public AbstractTheatre {
public:
	// Конструктор создает фабрику актеров и вызывает метод создания труппы актеров
	Theatre() {
		TroupeCreateor factory;
		inviteTroupe(&factory);
		script = new Script;	// Сценарий по-умолчанию берется из файла "commands.txt", однако можно в качестве аргумента конструктору указать любое другое название
	}

	// Примечание: Фабрика актеров для театра и сам театр получаются "связанными" (т.к. выделяет память фабрика, а освобождает память театр)
	~Theatre() {
		for (int i = 0; i < troupe.size(); i++) delete troupe[i];
	}


	void play() {
		for (int i = 0; i < script->size(); i++) {
			troupe.back()->handleRequest(script->getCommand(i));
		}
	}
private:
	vector <Actor*> troupe;
	Script* script;
	Manager* m;
	// Метод вызывает метод создания актеров у фабрики и сохраняет готовых актеров в труппу (вектор troupe)
	void inviteTroupe(TroupeCreateor* actor_factory) {
		troupe.push_back(actor_factory->createFather());
		troupe.push_back(actor_factory->createIvan(troupe.back()));
		troupe.push_back(actor_factory->createIlly(troupe.back()));
		troupe.push_back(actor_factory->createFedor(troupe.back()));
		troupe.push_back(actor_factory->createKing(troupe.back()));
		troupe.push_back(actor_factory->createDobriny(troupe.back()));
		troupe.push_back(actor_factory->createManager(troupe.back()));

		m = (Manager*)troupe.back();
		m->setTroupe(&troupe);
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	try {
		Theatre theatre;
		theatre.play();
	}
	catch (exception & e) {
		cout << e.what() << endl;
	}
	printf("\
*********************************************\n\
* Курсовой проект по дисциплине             *\n\
* Объектно-ориентированное программирование *\n\
* Тема: Сказка \"Иван-дурак\"               *\n\
* выполнил студент группы ИТ - 902          *\n\
* Бардин Марк Игоревич                      *\n\
*********************************************\n");
	system("pause");
	return 0;
}
