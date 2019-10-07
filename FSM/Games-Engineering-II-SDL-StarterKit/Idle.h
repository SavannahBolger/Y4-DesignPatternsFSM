#ifndef IDLE_H
#define IDLE_H

#include <State.h>

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void handleInput();
	void update();
	void jumping(Animation* a);
	void climbing(Animation* a);
	void walking(Animation* a);
};

class Walking : public State
{
public:
	Walking() {};
	~Walking() {};
	void idle(Animation* a);
};

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a);
	void climbing(Animation* a);
};

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
	void jumping(Animation* a);
};

#endif // !IDLE_H