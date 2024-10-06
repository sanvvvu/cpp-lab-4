#include <iostream>
#include <ctime>

using namespace std;

int chetnost(int ch)                                // Проверка на чётность суммы ch элементов
{
    long long int summ;
    summ = ch * (ch + 1) / 2;                       // Формула суммы последовательности первых ch чисел

    if (summ % 2 == 0) return 1;
    else return 0;

}

int main()
{
    srand(time(0));

    long long int n;
    cin >> n;

    long long int summ;
    summ = n * (n + 1) / 2;

    if(chetnost(n)){
        long long int mpol;
        mpol = summ / 2;

        long long int petya[n];                 // Создаём массивы из 0
        long long int masha[n];

        long long int chet_petya = 0, chet_masha = 0;

/* Начинаем с наибольшего числа n и, уменьшая, добавляем числа в список Пети, 
пока не достигнем половины суммы. Остальные числа идут в список Маши. */
        for(long long int i = n; i != 0; i--){          
            if (mpol >= i){
                petya[chet_petya] = i;
                chet_petya ++;                  // Считаем кол-во мисок Пети
                mpol -= i;
            }
            else{
                masha[chet_masha] = i;
                chet_masha += 1;                // Считаем кол-во мисок Маши
            }
        }

        cout << "YES\n";

        cout << chet_petya << "\n";
        for(long long int j = 0; j < chet_petya; ++j){
            if (petya[j] != 0) cout << petya[j] << " ";
        }

        cout << "\n" << chet_masha << "\n";
        for(long long int k = 0; k < chet_masha; ++k){
            if (masha[k] != 0) cout << masha[k] << " ";
        }
        cout << "\n" << endl;
    }
    else{                                               // Если сумма чисел нечётная, то никак нельзя разделить на две равные кучи
        cout << "NO" << endl;
    }

    cout << "runtime = " << clock()/1000.0 << endl;     // время работы программы

    return 0;
}
