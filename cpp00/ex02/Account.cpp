#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

Account::Account(int initial_deposit):
        _accountIndex(_nbAccounts),
	    _amount(initial_deposit),
	    _nbDeposits(0),
	    _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += checkAmount();
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";created" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << checkAmount();
    std::cout << ";deposit:" << deposit;
    this->_amount += deposit;
    _totalAmount += deposit;
    std::cout << ";amount:" << checkAmount();
    this->_nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << checkAmount();
    if (checkAmount() < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << ";withdrawal:" << withdrawal;
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << ";amount:" << checkAmount();
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
    return _totalAmount;
}

int	Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int		Account::checkAmount(void) const
{
    return this->_amount;
}

void	Account::_displayTimestamp(void)
{
    time_t now;

    now = time(NULL);
    std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S]") << " ";
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";p_amount:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
