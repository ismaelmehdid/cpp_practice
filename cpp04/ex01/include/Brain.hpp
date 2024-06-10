#ifndef Brain_Hpp
#define Brain_Hpp

#include <string>

#define NBR_IDEAS 100

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
	private:
		std::string ideas[NBR_IDEAS];
};

#endif