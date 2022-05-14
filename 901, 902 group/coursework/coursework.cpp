#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <io.h>
#include <vector>
#include <string>
////////////PARSER/////////////////
class parser {
private:
	const char* path;
	void file_open(FILE* parsing_file) {
		if (parsing_file == NULL) {
			printf("Error: cannot open file");
			return;
		}

		if (feof(parsing_file)) {
			printf("Error: file empty");
			return;
		}
	};

public:
	parser(const char* path) {
		if (path)
			this->path = path;
	}
	
	void file_read(std::vector<std::string>& queue) {
		char* data_string = new char;
		FILE* parsing_file = new FILE;
		parsing_file = fopen(this->path, "r");
		file_open(parsing_file);
		while (true) {
			std::string temp_data_string;

			if (feof(parsing_file)) {
				break;
			}

			fgets(data_string, 2, parsing_file);
			temp_data_string += data_string;
			while (*data_string != '\n' && *data_string != '#') {
				fgets(data_string, 2, parsing_file);
				if (feof(parsing_file)) {
					break;
				}
				if (*data_string != '\n' && *data_string != '#')
					temp_data_string += data_string;
			}
			queue.push_back(temp_data_string);
		}
	}
};
////////////!PARSER////////////////

////////////COMMANDS///////////////
class command;
class commanded_character;
class commands_queue {
private:
	static std::vector<commanded_character*> commands;
	static commands_queue* instance;

	commands_queue() {
	};
public:

	static void add_to_com_queue(commanded_character* com) {
		commands.push_back(com);
	}

	static std::vector<commanded_character*> get_com_queue() {
		return commands;
	};

	static commands_queue* getInstance() {
		if (instance)
			instance = new commands_queue();
		return instance;
	}
};

commands_queue* commands_queue::instance;
std::vector<commanded_character*> commands_queue::commands;
class command {
private:
	std::string id = "NULL";
public:
	virtual void invoke() = 0;
	virtual std::string get_id() = 0;
};

class commanded {
	std::vector<command*> inner_commands;
public:
	void invoke_command(int id) {
		inner_commands[id]->invoke();
	}
	void set_inner_commands(std::vector<command*> new_commands){
		inner_commands = new_commands;
	}
	command* get_inner_command(int id) {
		return inner_commands[id];
	}
	std::vector<command*> get_inner_commands() {
		return inner_commands;
	}
};

class print_info : public command {
private:
	std::string id = "to_console";
public:
	print_info() : command() {};
	void invoke() override {
		printf("\
*********************************************\n\
* Курсовой проект по дисциплине             *\n\
* Объектно-ориентированное программирование *\n\
* Тема: Сказка 'Золушка'                    *\n\
* выполнил студент группы ИТ - 902          *\n\
* xxxxxxxxxxxxxxxxxxxx                      *\n\
*********************************************\n");
	}
	std::string get_id() override {
		return id;
	};
};

class start : public command {
private:
	std::string id = "to_console";
public:
	void invoke() override {
		printf("%s\n", "===GAME STARTED===");
	}
	std::string get_id() override {
		return id;
	};
};
//cinderella
class lose_shoe : public command {
private:
	std::string id = "lose_shoe";
public:
	void invoke() override{printf("%s\n", "losed her shoe");}
	std::string get_id() override {return id;};
};

class count_peas : public command {
private:
	std::string id = "count_peas";
public:
	void invoke() override {printf("%s\n", "counting peas");}
	std::string get_id() override {return id;};
};
//prince
class find_shoe : public command {
private:
	std::string id = "find_shoe";
public:
	void invoke() override { printf("%s\n", "find cinderella shoe"); }
	std::string get_id() override { return id; };
};

class run_to_cinderella : public command {
private:
	std::string id = "run_to_cinderella";
public:
	void invoke() override { printf("%s\n", "run to cinderella"); }
	std::string get_id() override { return id; };
};

class give_shoe : public command {
private:
	std::string id = "give_shoe";
public:
	void invoke() override { printf("%s\n", "gived cinderella her shoe"); }
	std::string get_id() override { return id; };
};

class hug_cinderella : public command {
private:
	std::string id = "hug_cinderella";
public:
	void invoke() override { printf("%s\n", "hugged cinderella"); }
	std::string get_id() override { return id; };
};
////////////!COMMANDS///////////////
////////////CHARACTER//////////////
class character{
private:
	std::string name;
public:
	std::string get_name() {
		return name;
	}
	void set_name(std::string new_name) {
		name = new_name;
	}
	void set_name(const char* new_name) {
		name = new_name;
	}
};

class commanded_character : public character, public commanded {
public:
	commanded_character(std::string new_name, std::vector<command*> new_commands) {
		commands_queue* instance = commands_queue::getInstance();
		instance->add_to_com_queue(this);
		set_name(new_name);
		set_inner_commands(new_commands);
	}
};
////////////!CHARACTER/////////////
///////FAIRYTAIL_CHARACTER/////////
class cinderella : public commanded_character {
public:
	cinderella() :commanded_character("cinderella", std::vector<command*>{new lose_shoe, new count_peas}) {}
};
class prince : public commanded_character {
public:
	prince() :commanded_character("prince", std::vector<command*>{new give_shoe, new hug_cinderella, new find_shoe, new run_to_cinderella}) {}
};

int main()
{
	std::vector<std::string> queue;
	parser Parser("commands.dat");
	commands_queue* com_queue = commands_queue::getInstance();
	Parser.file_read(queue);
	setlocale(LC_ALL, "Russian");
	print_info com1;
	com1.invoke();

	start com2;
	com2.invoke();

	cinderella char1;
	prince char2;

	for (int i = 0; i < queue.size(); i++) {
		std::vector<commanded_character*> commanded_chars = com_queue->get_com_queue();
		for (int j = 0; j < commanded_chars.size(); j++) {
			for (int k = 0; k < commanded_chars[j]->get_inner_commands().size(); k++) {
				if (queue[i] == commanded_chars[j]->get_inner_command(k)->get_id()) {
					std::cout << commanded_chars[j]->get_name() << ": ";
					commanded_chars[j]->invoke_command(k);
				}
			}
		}
	}
}