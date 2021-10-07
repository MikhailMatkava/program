// Задание: определить есть ли в последовательности число X (для вещественных чисел - с точностью ε).

#include <stdio.h>
int main(void)
{
    double E = 1e-3;       //Погрешность сравнения
    double current_element; //Буффер с текущим элементом последовательности
    double X;               //Сравниваемое число
    char status = 1; //Условие входа в цикл 

    char *name_of_file = "input.txt"; //файл с последовательностью
    // считать данные
    FILE *inp;
    inp = fopen(name_of_file, "r");
    if(inp == NULL)      //удалось ли открыть файл
    {
        printf("\t****\tThere are some troubles with reading the file!\t****\n");
        return -1;
    }

    //ввод сравниваемого числа X
    printf("Enter the desired number:  ");
    if (scanf("%lf", &X) != 1)
    {
        printf("\t****\tWARNING\t****\n\tWrong format of input!\n");
        return -1;
    }
    // обрабатываем каждый член последовательности и проверяем его считываемость 
    status = fscanf(inp, "%lf", &current_element);
    while(status==1)   //Если все хорошо то входим в цикл:
        {
            if(( X+E > current_element) && ( X-E < current_element))
                {
                    printf("Yes, there is an element which is equal of X.\n");
                    fclose(inp);
                    return 0;
                }
                
            status = fscanf(inp, "%lf", &current_element); //Считываем элемент 
        }
    if((status != 1) && (status != EOF))
                {
                printf("\t****\tWARNING! The data in the file is INCORRECT.\t****\n");
                fclose(inp);        //Закрываем файл
                return -1;
                }
    printf("No, there is no element which is equal of X.\n");
    fclose(inp);        //Закрыть файл
    return 0;
}