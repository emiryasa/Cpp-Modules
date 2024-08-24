#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR : This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level)
{
	void	(Harl::*complaintFunctions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string	complaintLevels[] = {"debug","info","warning","error"};

	for (int cur = 0; cur < 4; cur++)
	{
		if (level == complaintLevels[cur])
		{
			(this->*complaintFunctions[cur])();
			break;
		}
	}
	return;
}
