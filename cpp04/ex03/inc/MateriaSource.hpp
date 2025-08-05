/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonjaojala <sonjaojala@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:43:13 by sonjaojala        #+#    #+#             */
/*   Updated: 2025/08/05 14:43:14 by sonjaojala       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# define STORAGE_MAX 4
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria*	_storage[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource();

		void		learnMateria(AMateria* m) override;
		AMateria*	createMateria(const std::string& type) override;
};

#endif
