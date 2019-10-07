#include <Idle.h>

#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Idle::walking(Animation * a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

void Walking::idle(Animation* a)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Jumping::idle(Animation* a)
{
	std::cout << "Jumping -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Jumping::climbing(Animation* a)
{
	std::cout << "Jumping -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Climbing::idle(Animation* a)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Climbing::jumping(Animation* a)
{
	std::cout << "Climbing -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
