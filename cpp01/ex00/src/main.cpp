/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:28:55 by maximart          #+#    #+#             */
/*   Updated: 2025/06/16 16:22:56 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	randomChump("Bishop");
	randomChump("Queen");
	randomChump("King");
	Zombie *heapZombie = newZombie("HeapHipHip");
	heapZombie->announce();
	delete heapZombie;
	return (0);
}