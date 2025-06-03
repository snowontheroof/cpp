#include "Account.hpp"
#include <iostream>

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {
	_accountIndex = _totalAmount + 1;
	_totalAmount++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account( void ) {
}

void	Account::makeDeposit( int deposit ) {
	_amount += deposit;
	_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (_amount - withdrawal < 0)
		return (false);
	_amount -= withdrawal;
	_nbWithdrawals++;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
	std::cout << "index:" << _accountIndex <<  ";amount:" << _amount << ";deposits:"
		<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	_displayTimestamp( void ) {
	tm	time;

	std::cout << "[" << time.tm_year + 1900 << time.tm_mon + 1 << time.tm_mday
		<< "_" << time.tm_hour << time.tm_min << time.tm_sec << "] ";
}

Account::Account( void ) {
}
