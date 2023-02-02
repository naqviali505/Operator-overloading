#include<iostream>
#include<ostream>
#include<istream>
#include<cmath>
using namespace std;
class VectorType
{
private:
	//necessary variables of pointers type
	double* x;
	double* y;
	double* z;
public:
	VectorType()
	{
		x = new double;
		*x=0;
		y = new double;
		*y = 0;
		z = new double;
		*z = 0;
	}
	VectorType(double* x1, double* y1, double* z1)
	{
		x = new double;
		*x = *x1;
		y = new double;
		*y = *y1;
		z = new double;
		*z = *z1;
	}
	VectorType(VectorType &obj)
	{
		x = new double;
		*x = *obj.x;
		y = new double;
		*y = *obj.y;
		z = new double;
		*z = *obj.z;
	}
	~VectorType()
	{
		delete x;
		delete y;
		delete z;
	}
	VectorType operator=(const VectorType& obj)
	{
		*x = *obj.x;
		*y = *obj.y;
		*z = *obj.z;
		return *this;
	}
	VectorType operator*( VectorType& obj)
	{
		VectorType obj1;
		*obj1.x = *x * (*obj.x);
		*obj1.y = *y * (*obj.y);
		*obj1.z = *z * (*obj.z);
		return obj1;
	}
	double findlength()
	{
		return(pow((*x) * (*x) + (*y) * (*y) + (*z) * (*z), 0.5));
	}
	double findangle(VectorType& obj)
	{
		return acos((*this).dotproduct(obj)/(obj.findlength()*(*this).findlength()));
	}
	VectorType operator+(VectorType &obj)
	{
		VectorType obj1;
		*obj1.x = *x + *obj.x;
		*obj1.y = *y + *obj.y;
		*obj1.z = *z + *obj.z;
		return obj1;
	}
	VectorType operator-(VectorType& obj)
	{
		VectorType obj1;
		*obj1.x = *x - *obj.x;
		*obj1.y = *y - *obj.y;
		*obj1.z = *z - *obj.z;
		return obj1;
	}
	VectorType operator++(int)
	{
		*x=*x+1;
		*y=*y+1;
		*z=*z+1;
		return *this;
	}
	VectorType operator++()
	{
		++*x;
		++*y;
		++*z;
		return *this;
	}
	VectorType operator--(int)
	{
		*x=*x-1;
		*y=*y-1;
		*z=*z-1;
		return *this;
	}
	VectorType operator--()
	{
		--*x;
		--*y;
		--*z;
		return *this;
	}
	double dotproduct(VectorType& obj)
	{
		VectorType obj1;
		obj1= obj * (*this);
		return (*obj1.x + *obj1.y + *obj1.z);
	}
	friend  bool operator!=(VectorType& obj1, VectorType& obj);
	friend  bool operator==(VectorType &obj1 ,VectorType& obj);
	friend istream& operator>>(istream & in, VectorType& obj);
	friend ostream& operator<<(ostream& out, VectorType& obj);
};
bool operator!=(VectorType& obj1, VectorType& obj)
{
	if (*obj1.x == *obj.x && *obj1.y == *obj.y && *obj1.z == *obj.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator==( VectorType &obj1,VectorType& obj)
{
	if (*obj1.x == *obj.x && *obj1.y == *obj.y && *obj1.z == *obj.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}
istream& operator>>(istream& in, VectorType& obj)
{
	in >> *obj.x;
	in >> *obj.y;
	in >> *obj.z;
	return in;
}
ostream& operator<<(ostream& out, VectorType& obj)
{
	out << *obj.x<<"i";
	if (*obj.y > 0)
		out <<"+"<< *obj.y << "j";
	else
		out  << *obj.y << "j";
	if (*obj.z> 0)
		out <<"+"<< *obj.z << "k";
	else
		out  << *obj.z << "k";
	return out;
}
int main()
{
	double u1 = 0, u2 = 0,u3 = 0,v1=0,v2=0,v3=0;
	u1 = 3, u2 = 6, u3 = -4, v1 = 9, v2 = 6, v3 = 2;
	VectorType u(&u1, &u2, &u3);
	cout <<"Vector u: "<< u << endl;
	VectorType v(&v1,&v2,&v3);
	cout <<" Vector v: "<< v << endl;
	v = v++;
	cout << "Vector v after post increment: " << v << endl;
	v = ++v;
	cout << "Vector v after pre increment: " << v << endl;
	u = u--;
	cout << "Vector u after post decrement: " << u << endl;
	u = --u;
	VectorType z;
	cout << "Vector u after pre decrement: " << u << endl;
	cout << "Vector u: " << u << endl;
	cout << " Vector v: " << v << endl;
	cout << "Enter elements for another vector z" << endl;
	cin >> z;
	cout << z << endl;
	cout << "Length of u is " << u.findlength() << endl;
	cout << "Length of v is " << v.findlength() << endl;
	cout << "The dot product of the two vectors u and v is "<< u.dotproduct(v) << endl;
	cout << "The angle between the two vectors u and v is " << u.findangle(v) * (180 / 3.1412) << endl;
	return 0;
}