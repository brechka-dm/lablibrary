#include <math.h>
#include <stdio.h>
// Solution - это структура, которая хранит в себе набор решений квадратного
// уравнения. Если решений уравнение нет, то n_solutions = 0, а содержимое x1 и
// x2 неопределено. Если решения уравнения одно, то n_solutions = 1 и x1==x2
// == единственному решению. Если решений два, то n_solutions = 2, в x1 лежит
// решение, полученное вычитанием дискриминанта, в x1 лежит решение, полученное
// прибавлением дискриминанта
struct Solution {
    int n_solutions;  // количество решений. Ноль, 1 или 2
    float x1;         // первый корень уравнения
    float x2;         // второй корень уравнения
};

struct Solution quadratic_equation(float a, float b, float c) { //функция возвражает структуру 
    struct Solution solution; //внутренняя структура для сохранения результатов
    if(a=0 && b=0){//если коэф-ты a и b равны 0, то остается константа с
        solution.n_solutions =1; //количество корней
        solution.x1=-c; //корень 
        solution.x2=solution.x1; //второй корень равен первому
        return solution; //возвращаем всю структуру
    }
    if(a==0){ //если коэф-т a=0, то уравнение линейное, имеет один корень
        solution.n_solutions =1; //количество корней
        solution.x1=-c/b; //корень 
        solution.x2=solution.x1; //второй корень равен первому
        return solution; //возвращаем всю структуру
    }
    float d=b*b-4*a*c; //вычисляем дискриминант
    if(d<0){ //если дискриминант меньше 0
        solution.n_solutions = 0; // решений нет
        return solution;
    }
    else if(d==0){ //если дискриминант =0 
        solution.n_solutions = 1; //одно решение 
        solution.x1=-b/(2*a);
        solution.x2=solution.x1; //второй корень равен первому
        return solution;
    }
    else{ //если дискриминант не равен 0 
        solution.n_solutions = 2; //2 решения
        solution.x1 = (-b-sqrt(d))/(2*a);
        solution.x2 = (-b+sqrt(d))/(2*a);
        return solution;
    }
}

int main(void) {
    struct Solution solution;
    solution = quadratic_equation(1, 2, -3);
    printf("n=%d; x1=%f; x2=%f",solution.n_solutions, solution.x1, solution.x2); //выводим на экран отдельно каждое поле структуры
    return 0;
}