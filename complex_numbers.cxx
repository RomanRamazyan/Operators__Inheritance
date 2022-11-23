#include<iostream>

class Complex 
{
	protected:
		// Դասի անդամ փոփոխականների անունները ցանկալի է սկսել m_ ով, որպեսզի հետո դրանք տարբերվեն մյուս ժամանակավոր փոփոխականներից
		int real, img;
};

class Adder :public Complex
{
	public:
		Adder( int i = 0, int j = 0 ) 
		{real = i; img = j;}
		Adder operator + ( Adder const &myObj ) 
		{
			Adder r;
			r.real = real + myObj.real;
			r.img = img + myObj.img;
			return r;
		}
		
		// Adder& operator = ( Equal const &myObj );
		// Adder& operator += ( AdderEqual const &myObj )
		// Adder& operator ++();
		// և այլն
		
		void print()
		{ std::cout << "Adder is: " << real << " + i" << img << '\n'; }
};

// Պետք էր մեկ դասում բոլոր օպերատորները գերբեռնել
class Equal :public Complex
{
	public:
	    Equal( int i = 0, int j = 0 )
		{real = i; img = j;} 
	    Equal operator = ( Equal const &myObj ) 
		{
	        Equal r;
	        r.real = real = myObj.real;
	        r.img = img = myObj.img;
	        return r;
	    }   
	    void print() 
		{ std::cout << "Equal is: " << real << " + i" << img << '\n'; }
};

class AdderEqual :public Complex
{
	public:
	    AdderEqual( int i = 0, int j = 0 )
		{real = i; img = j;} 
	    AdderEqual operator += ( AdderEqual const &myObj ) 
		{
	        AdderEqual r;
	        r.real = real += myObj.real;
	        r.img = img += myObj.img;
	        return r;
	    }   
	    void print() 
		{ std::cout << "AdderEqual is: " << real << " + i" << img << '\n'; }
};

class DoubleEqual :public Complex
{
	public:
	    DoubleEqual( int i = 0, int j = 0 ) 
		{real = i; img = j;} 
	    DoubleEqual operator == ( DoubleEqual const &myObj ) 
		{
	        DoubleEqual r;
	        r.real = real == myObj.real;
	        r.img = img == myObj.img;
	        return r;
	    }   
	    void print() 
		{ std::cout << "DoubleEqual is: " << real << " + i" << img << '\n'; }
};

class DoubleAdder
{
    private:
       int i;
    public:
       DoubleAdder(): i( 10 ) 
	   {}
       void operator ++() 
       {
            ++i;
       }
       void print() 
       {
            std::cout << "i = " << i << std::endl; 
       }
};

int main()
{
    Adder a1( 5, 6 ), a2( 20, 8 );
    Adder a3 = a1 + a2;
 	a3.print();
    Equal b1( 5, 6 ), b2( 20, 8 );
    Equal b3 = b1 = b2;
    b3.print();
    AdderEqual c1( 5, 6 ), c2( 20, 8 );
    AdderEqual c3 = c1 += c2;
    c3.print();
    DoubleEqual d1( 20, 8 ), d2( 20, 8 );
    DoubleEqual d3 = d1 == d2;
    d3.print();
    DoubleAdder myObj;
    std::cout << "Before: ";
    myObj.print();
    ++myObj; 
    std::cout << "After: ";
    myObj.print();
}
