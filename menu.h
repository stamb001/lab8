#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"

using namespace std;

class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() {
			this->history_index = -1;
		};
		void execute() {
			if(this->history.size() == 0 || this->history_index == -1) {
				cout << "0" << endl;
			}
			else {
				this->history.at(this->history_index)->execute();
			}
		};
		bool initialized() {
			if(this->history.size() > 0){
				return true;
			}
			else {
				return false;
			}
		};
		void add_command(Command* cmd) {
			if(this->history.size() - 1 == this->history_index){
				this->history.push_back(cmd);
			}
			else{
				this->history.at(this->history_index + 1);
			}
			this->history_index += 1;		
		};
		Command* get_command() {
			return this->history.at(this->history_index);
		};
		void undo() {
			if(this->history_index > 0){
				this->history_index -= 1;
			}
		};
		void redo() {
			if(this->history_index < this->history.size())
				this->history_index += 1;
			}
		};
};

#endif //__MENU_CLASS__
