#include <iostream>
#include <climits>

//Function declarations (move here after writing all the code)
unsigned int add_checksum(unsigned int n); // function 1: checksum
unsigned int powerfunc(unsigned int number, unsigned int exponent); //function returns number^exponent


void add_checksum(unsigned int array[], std::size_t capacity);
bool verify_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n);
void remove_checksum(unsigned int array[], std::size_t capacity);

void add_checksum(unsigned int array[], std::size_t capacity) {

}

bool verify_checksum(unsigned int n) {
    return true;
}

unsigned int remove_checksum(unsigned int n) {
    return {15000};
}

void remove_checksum(unsigned int array[], std::size_t capacity) {

}




unsigned int add_checksum(unsigned int n) { //checksum function 1
	if(n<=99999999 && n>=0) { //if number is 8 digits
		unsigned int const elements {8}; //total # of elements must be 8
		unsigned int digits [8]; //stores 8 digits of the number
		unsigned int divisor {10}; 
		for(int index{0}; index<elements; index++) { //repeats for each digit in the number
			if(index == 0) { //for the first digit
				digits[index] = n%powerfunc(10,index+1); //save first digit into digits array
			}
			else { //for the rest of the digits
				digits[index] = (n%(powerfunc(10,index+1)))/powerfunc(10,index); //save digits using this algorithm
			}
		}

		for(int index{0}; index<elements; index++) {
			std::cout << digits[index] << "\t";  //print out all digits
		}
		std::cout << std::endl;

		//ALGORITHM FOR CHECKSUM
		unsigned int checksum {0}; //checksum number to be suffixed
		for(int index{0}; index<elements; index++) { //cycle for each digit
			if(index == 0 || index%2==0) {//every other digit starting from the last digit of the number (first number for array)
				digits[index]=digits[index]*2;
			}
		//std::cout << digits[index] << "\t";
		}
		//std::cout << std::endl;

		for(int index{0}; index<elements; index++) { //cycle for each digit
			if(digits[index]>9) { //if number is greater than 9
				digits[index] = digits[index]/10 + digits[index]%10; //set this number to the sum of its digits
			}
		}

		for(int index{0}; index<elements; index++) {  
			std::cout << digits[index] << "\t";  //print out all digits
		}
		std::cout << std::endl;

		for(int index{0}; index<elements; index++) { //add all digits together
			checksum+=digits[index];
		}

		checksum=checksum*9; //multiply sum by 9
		checksum = checksum%10; //get checksum digit

		unsigned int returnnum {checksum}; //variable to be returned

		for(int index{0}; index<elements; index++) { //repeats for each digit in the number
			if(index == 0) { //for the first digit
				digits[index] = n%powerfunc(10,index+1); //save first digit into digits array
			}
		else { //for the rest of the digits
				digits[index] = (n%(powerfunc(10,index+1)))/powerfunc(10,index); //save digits using this algorithm
			}
		}

		for(int index{0}; index<elements; index++) { //for each digit
			checksum+=digits[index]*powerfunc(10,index+1); //add the original number with suffix attached
		}	

		return checksum; //return computed number with suffix

	}

	else { //if number is greater than 8 digits
		return UINT_MAX; //return max unsigned integer value which signals an error
	}

	return n; //shold never get here
}

unsigned int powerfunc(unsigned int number, unsigned int exponent) { //power function
	unsigned int sum {1};
	for(int i = 1; i<=exponent; i++) {
		sum*=number;
	}
	return sum;
}

#ifndef MARMOSET_TESTING
int main();
#endif




//Function definitions (move here after writing all the code)




#ifndef MARMOSET_TESTING
int main() {
	unsigned int value_to_protect{12345678};
	unsigned int protected_value = add_checksum(value_to_protect);
	std::cout << "The value " << value_to_protect
		<< " with the checksum added is " << protected_value
	 	<< "." << std::endl;
	
	if (verify_checksum(protected_value))
	{
		std::cout << "The checksum is valid." << std::endl;
	}
	else   {
		std::cout << "The checksum is invalid." << std::endl;
	} 
	const std::size_t QTY_VALUES {3};
	unsigned int value_series[QTY_VALUES] {20201122, 20209913, 20224012};
	
	add_checksum(value_series, QTY_VALUES);
	
	std::cout << "Series with checksums added: ";
	for (std::size_t series_index {0};
		series_index < QTY_VALUES; series_index++)
	{
		std::cout << value_series[series_index] << " ";
	}

    std::cout << std::endl;




    return 0;
}
#endif