#include<iostream>
using namespace std;

class Polynomial
{
  private:
  	int size;
  	int* array;
    // Variables to store information about polynomial
  public:
    Polynomial()
    {
      // Behavior of default constructor
    }

    Polynomial(int deg)
    {
    	size=deg;
    	array=new int [size+1];
      // Behavior of constructor with arguments
    }
  
    ~Polynomial()
    {
      cout<<"Destructor called"<<endl;// Behavior of destructor
    }
  
    //  Overload copy constructor, +, - and = operators
  
    void storePolynomial()
    {
    	for(int i=size;i>=0;i--)
    	{
    		cout<<"Enter the coefficient of x^"<<i<<" : ";
    		cin>>array[i];
		}
      //  Code to enter and store polynomial
    }
    void display()
    {
    	
    	for(int i=size;i>0;i--)
    	{
    		cout<<array[i]<<"x^"<<i<<"+ ";
    			
		}
		cout<<array[0];
      //  Code to print the polynomial in readable format
    }
    Polynomial(const Polynomial &secobj)
    {
    	size=secobj.size;
    	array=new int [size+1];
    	for(int i=size;i>=0;i--)
    	{
    		array[i]=secobj.array[i];
		}
	}
	Polynomial operator +(Polynomial secondobj)
	{
		int i,j;
		Polynomial obj;
		if(size>secondobj.size)
		{
			obj.size=size;
		    obj.array=new int[obj.size+1];
			for(i=size,j=secondobj.size;i,j>=0;)
			{
				if(i!=j)
				{
					obj.array[i]=array[i];
					i--;
				}
				else
				{
					obj.array[i]=array[i]+secondobj.array[j];
					i--;
					j--;
				}
				
			}
		}
		else
		{
			obj.size=secondobj.size;
			obj.array=new int[obj.size+1];
			for(i=secondobj.size,j=size;i,j>=0;)
			{
				if(i!=j)
				{
					obj.array[i]=secondobj.array[i];
					i--;
				}
				else
				{
					obj.array[i]=secondobj.array[i]+array[j];
					i--;
					j--;
				}
				
			}
		}
		return obj;
	}
	Polynomial operator -(Polynomial secondobj)
	{
		int i,j;
		Polynomial obj;
		if(size>secondobj.size)
		{
			obj.size=size;
		    obj.array=new int[obj.size+1];
			for(i=size,j=secondobj.size;i,j>=0;)
			{
				if(i!=j)
				{
					obj.array[i]=array[i];
					i--;
				}
				else
				{
					obj.array[i]=array[i]-secondobj.array[j];
					i--;
					j--;
				}
				
			}
		}
		else
		{
			obj.size=secondobj.size;
			obj.array=new int[obj.size+1];
			for(i=secondobj.size,j=size;i,j>=0;)
			{
				if(i!=j)
				{
					obj.array[i]=secondobj.array[i];
					i--;
				}
				else
				{
					obj.array[i]=array[i]-secondobj.array[j];
					i--;
					j--;
				}
				
			}
		}
		return obj;
	}
	Polynomial operator =(Polynomial secobject)
	{
		size=secobject.size;
		array=new int [size+1];
		for(int i=size;i>=0;i--)
		{
			array[i]=secobject.array[i];
		}
	}
  
};

int main()
{
  int degFirst, degSecond;
  cout<<"Enter the highest degree of first polynomial: ";
  cin>>degFirst;
  Polynomial firstPolynomial(degFirst);
  firstPolynomial.storePolynomial();
  cout<<endl;
  cout<<"Enter the highest degree of second polynomial: ";
  cin>>degSecond;
  
  Polynomial secondPolynomial(degSecond);
  secondPolynomial.storePolynomial();
  
  // Ask user to input the values of degFirst and degSecond 
  cout<<"\n\nThe first polynomial is: \n";
  firstPolynomial.display();
  cout<<"\n\nThe second polynomial is: \n";
  secondPolynomial.display();
  
 
  cout<<"\n\nPolynomial after addition: ";
  Polynomial thirdPolynomial=firstPolynomial+secondPolynomial;
 
  thirdPolynomial.display();
  cout<<"\n\nPolynomial after subtraction: \n";
   Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  fourthPolynomial.display();
  return 0;
}
