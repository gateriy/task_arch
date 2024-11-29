#include "Task_1.h"


/*
В этом задании нужно написать функцию clone для класса трёхдиагональной матрицы, 
которая возвращает std::unique_ptr. Код класса трёхдиагональной матрицы ниже:
*/

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;

    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }
       
    auto clone() const {
        std::cout << "Clone create!" << std::endl;
        return std::make_unique<tridiagonal_matrix>(this->m_down, this->m_upper, this->m_middle);
    }     
};


void Task_1() {
	
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };

    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

     
    for (const auto& i : matrix_clone->m_down) {
        std::cout << "Проверка вывод вектора из клона m_down: " << i << std::endl;
    }

    //return 0;

};