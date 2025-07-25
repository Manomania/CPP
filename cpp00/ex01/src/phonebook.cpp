/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:26:43 by maximart          #+#    #+#             */
/*   Updated: 2025/05/06 19:13:35 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() {
	count = 0;
	oldest = 0;
}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
	int	Index;

	if (count >= 8)
		Index = oldest;
	else
		Index = count;
	if (!contacts[Index].promptContact())
	{
		std::cout << "\nError: Contact addition canceled" << std::endl;
		return ;
	}
	if (count >= 8)
	{
		Index = oldest;
		oldest = (oldest + 1) % 8;
	}
	else
		Index = count++;
	std::cout << "Contact added successfully" << std::endl;
	std::cout << std::endl;
}

void	printHeader()
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::displayContact(int Index) const
{
	std::cout << "CONTACT #" << (Index + 1) << ": " << std::endl << contacts[Index].getFullContact() << std::endl;
}

void	PhoneBook::searchContact() const
{
	int	index;

	if (count == 0)
	{
		std::cout << "EMPTY" << std::endl;
		return ;
	}
	printHeader();
	for (int i = 0; i < count; i++)
	{
		std::cout << "|" << std::setw(10) << (i+1) << "|" << contacts[i].getContact() << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	std::cout << "\nEnter index to display (1-" << count << "): ";
	if (!(std::cin >> index))
	{
		if (std::cin.eof())
			return ;
		else
		{
			std::cout << "Error: Only digits allowed" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return ;
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
	if (index > count || index < 1)
	{
		std::cout << "Error: Index must be between 1 and " << count << std::endl;
		std::cout << std::endl;
		return ;
	}
	displayContact(index - 1);
}
