#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	std::cout << "index:" << _nbAccounts << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";closed" << std::endl;
}

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
    tm *now_tm = localtime(&now);
	
	    std::cout
		<< '['
              << (now_tm->tm_year + 1900)								   //tm_year is the year from 1900 so we add 1900
              << std::setw(2) << std::setfill('0') << (now_tm->tm_mon + 1) // +1 because january starts from 0 instead of 1
              << std::setw(2) << std::setfill('0') << now_tm->tm_mday
              << '_'
              << std::setw(2) << std::setfill('0') << now_tm->tm_hour
              << std::setw(2) << std::setfill('0') << now_tm->tm_min
              << std::setw(2) << std::setfill('0') << now_tm->tm_sec
        << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << ++_nbDeposits << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int		Account::checkAmount( void ) const
{
	return 1;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}
