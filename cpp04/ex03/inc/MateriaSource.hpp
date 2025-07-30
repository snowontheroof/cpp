#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria*	storage[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource();

		void		learnMateria(AMateria* m) override;
		AMateria*	createMateria(const std::string& type) override;
};

#endif
