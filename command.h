#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	public:
		OpCommand(double value){
			this->root = new Op(value);
		};
		
};

class AddCommand : public Command {
	public:
		AddCommand(Command* com, double value){
			Base* t = new Op(value);
			this->root = new Add(t, com->get_root());	
		};
};

class SubCommand : public Command {
	public:
		SubCommand(Command* com, double value){
			Base* t = new Op(value);
			this->root = new Sub(t, com->get_root();	
		};

};

class MultCommand : public Command {
	public:
		MultCommand(Command* com, double value){
			Base* t = new Op(value);
			this->root = new Mult(t, com->get_root());
		};
};

class SqrCommand : public Command {
	public:
		SqrCommand(Command* com){
			this->root = new Sqr(com->get_root());
		};
	
};

#endif //__COMMAND_CLASS__
