/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:40:59 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 17:47:48 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& obj);
		Brain&	operator=(const Brain& other);
		~Brain();

		void		setIdea(int idx, const std::string& newIdea);
		std::string	getIdea(int idx) const;
};

#endif
