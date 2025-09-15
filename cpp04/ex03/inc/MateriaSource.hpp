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
