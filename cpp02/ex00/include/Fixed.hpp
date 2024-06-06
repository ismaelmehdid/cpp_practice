#ifndef Fixed_hpp
#define Fixed_hpp

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &toCopy);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int m_nbrValue;
		static const int fractionalBits = 8;
};

#endif