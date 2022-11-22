#include <iostream>

class Object
{
		protected:
			float firstSide, secondSide, thirdSide;
};

class Triangle: public Object
{
		private:
			float firstSide, secondSide, thirdSide, height;
		public:
			void sidesTriangle(float a, float b, float c, float h)
			{
				firstSide = a;
				secondSide = b;
				thirdSide = c;
				height = h;
			}
			float perimeterTriangle(std::string type) 
			{
				float P, S;
				float A;
				P = firstSide + secondSide + thirdSide;
				S = 0.5*(secondSide * height);
				return (type == "perimeter" ? P : S);
			}
};

class Rectangle :public Object
	{
		protected:
			float fourthSide;
		public:
			void setSides(float a, float b, float c, float d)
			{
				firstSide = a;
				secondSide = b;
				thirdSide = c;
				fourthSide = d;
			}
			float calc(std::string what)
			{
				float P, S;
				P = firstSide + secondSide + thirdSide + fourthSide;
				S = firstSide * secondSide * thirdSide * fourthSide;
				return (what == "perimeter" ? P : S);
			}
	};

class Square :public Object
{
		protected:
            float fourthSide;
        public:
            void setSides(float a, float b, float c, float d)
            {
                firstSide = a;
                secondSide = b;
                thirdSide = c;
                fourthSide = d;
            }
            float calc(std::string what)
            {
                float P, S;
                P = firstSide + secondSide + thirdSide + fourthSide;
                S = firstSide * secondSide * thirdSide * fourthSide;
                return (what == "perimeter" ? P : S); 
            }
};

class Circle
{
		private:
			float PI;
			float R;
    	public:
        	void setSides(float pi, float r)
        	{
            	PI = pi;
            	R = r;
        	}
        	float calc(std::string what)
        	{
            	float P, S;
            	P = 2*3.14*R;
            	S = PI * R*10;
            	return (what == "perimeter" ? P : S);
        	}
};

class Ellipse :public Object
{
      	public:
          	void setSides(float a, float b)
          	{
			  
              	firstSide = a;
              	secondSide = b;
 
          	}
          	float calc(std::string what)
          	{
              	float P, S;
              	P = ((3.14*firstSide*secondSide+(firstSide-secondSide)*(firstSide-secondSide))/(firstSide+secondSide))*4;
              	S = 3.14 * firstSide * secondSide;
              	return (what == "perimeter" ? P : S);
          	}

};

int main()
{
		Triangle triangle;
		Square square;
		Rectangle rectangle;
		Ellipse ellipse;
		Circle circle;
		float a, b, c, h, R;
		float pi = 3.14;
		std::cout << "Enter the first second third. Height for triangle: ";
		std::cin >> a >> b >> c >> h;
		triangle.sidesTriangle(a, b, c, h);
		std::cout << "PERIMETER TRIANGLE: " << triangle.perimeterTriangle("perimeter") << std::endl;
		std::cout << "AREA TRIANGLE: " << triangle.perimeterTriangle("area") << std::endl;
		rectangle.setSides(a, b, c, h);
		std::cout << "PERMIMETER RECTANGLE: " << rectangle.calc("perimeter") << std::endl;
		std::cout << "AREA RECTANGLE: " << rectangle.calc("area") << std::endl;
	    square.setSides(a, b, c, h);
	    std::cout << "PERMIMETER SQUARE: " << square.calc("perimeter") << std::endl;
	    std::cout << "AREA SQUARE: " << square.calc("area") << std::endl;
		ellipse.setSides(a, b);
	    std::cout << "PERMIMETR ELLIPSE: " << ellipse.calc("perimeter") << std::endl;
	    std::cout << "AREA ELLIPSE: " << ellipse.calc("area") << std::endl;
		std::cout << "Enter cyrcle R: ";
		std::cin >> R;
		circle.setSides( pi, R ); 
		std::cout << "PERMIMETER SQUARE: " << circle.calc("perimeter") << std::endl;
		std::cout << "AREA SQUARE: " << circle.calc("area") << std::endl;
		return 0;
}
