#include <iostream>

int main(int argc, char* argv[]){


	int n1 = 0;
	int n2 = 0; 

	std::cout <<"Informe o primeiro numero ";
	std::cin >> n1;

	std::cout <<"Informe o segundo numero ";
	std::cin >> n2;

	int sum = n1 + n2;

	std::cout <<"A soma dos numero e " << sum << std::endl;

	return 0;
}