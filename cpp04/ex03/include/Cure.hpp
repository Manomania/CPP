#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria {
private:
public:
	Cure();
	virtual ~Cure();
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};
