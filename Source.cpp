#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class complex
{
public:

	complex(float = 0, float = 0);
	complex complexAdd(complex&);
	complex complexSub(complex&);
	complex complexMul(complex&);
	void complexPrint();
	void complexCube();

private:

	float realnb;
	float imgnb;
};

complex::complex(float a, float b)
{
	realnb = a;
	imgnb = b;
}

complex complex::complexAdd(complex& x)
{
	return complex(realnb + x.realnb, imgnb + x.imgnb);
}

complex complex::complexSub(complex& x)
{
	return complex(realnb - x.realnb, imgnb - x.imgnb);
}

complex complex::complexMul(complex& x)
{
	return complex((realnb * x.realnb - imgnb * x.imgnb), (realnb * x.imgnb + imgnb * x.realnb));
}

void complex::complexPrint()
{
	if (imgnb >= 0)
		std::cout << realnb << '+' << imgnb << "i.\n";
	else
		std::cout << realnb << imgnb << "i.\n";
}

void complex::complexCube()
{
	complex temp = complex(realnb, imgnb);
	temp = complexMul(temp);
	temp = complexMul(temp);
	realnb = temp.realnb;
	imgnb = temp.imgnb;
}

int main()
{
	complex x(3.62, 1.25);
	complex y(0.32, 4.15);

	std::cout << "Two complex numbers have created, the two complex numbers are: \n";
	x.complexPrint();
	y.complexPrint();

	complex z = x.complexAdd(y);
	std::cout << "\nThe sum of two complex numbers is:\n";
	z.complexPrint();

	std::cout << "\nThe difference of two complex numbers is:\n";
	z = x.complexSub(y);
	z.complexPrint();

	std::cout << "\nThe product of two complex numbers is:\n";
	z = x.complexMul(y);
	z.complexPrint();

	std::cout << "\nThose two complex numbers after being cubed are:\n";
	x.complexCube();
	y.complexCube();
	x.complexPrint();
	y.complexPrint();

	return 0;
}