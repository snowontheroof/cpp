/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojala <sojala@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:33:57 by sojala            #+#    #+#             */
/*   Updated: 2025/06/06 10:47:04 by sojala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	brainReference(void)
{
	std::string		stringSTR = "HI THIS IS BRAIN";
	std::string*	stringPTR = &stringSTR;
	std::string&	stringREF = stringSTR;

	std::cout << "Memory address of stringSTR: " << &stringSTR << std::endl;
	std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value of stringSTR: " << stringSTR << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
}

int	main()
{
	brainReference();
	return 0;
}
