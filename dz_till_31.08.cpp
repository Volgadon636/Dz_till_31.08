
#include <iostream>
using namespace std;

template<typename T,typename T2>
double avg(T* mas, T2 size) {
    long long sum = 0,size_p = size;
    for (int i = 0; i < size; ++i) {
        sum += mas[i];
    }

    double avg = (double)sum / size_p;
    
    return avg;
    
}
template<typename T>
T max1(T * mas,int size) {
    T MAX = mas[0];
    for (int i = 0; i < size; ++i) {
        if (mas[i] > MAX) {
            MAX = mas[i];
        }
    }
    return MAX;
}
template<typename T>
T max_2(T **matrix, int size1, int size2) {
    T MAX = matrix[0][0];
    for (int j = 0; j < size1; ++j) {
        for (int i = 0; i < size2; ++i) {
            if (matrix[j][i] > MAX) {
                MAX = matrix[j][i];
            }
        }
    }
    return MAX;

}
template<typename T>
T max3(T ***mas, int size1, int size2, int size3) {
    T MAX = mas[0][0][0];
    for (int u = 0; u < size1; ++u) {
        for (int j = 0; j < size2; ++j) {
            for (int i = 0; i < size3; ++i) {
                if (mas[u][j][i] > MAX) {
                    MAX = mas[u][j][i];
                }
            }
        }
    }
    return MAX;
    

}
int main()
{
    srand(time(0));
    {
        cout << "Exercise 4" << endl << endl;
        int size1, size2, size3;
        cout << "enter size1 / size2 / size 3:  "; cin >> size1 >> size2 >> size3; cout << "\n\n";
        
        int *mas = new int[size1];

        int **matrix = new int*[size1];
        for (int i = 0; i < size1; ++i) {
            matrix[i] = new int[size2];
        }

        int ***trio = new int**[size1];
        for (int i = 0; i < size1; ++i) {
            trio[i] = new int* [size2];
        }
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                trio[i][j] = new int[size3];
            }
        }

        for (int u = 0; u < size1; ++u) {
            mas[u] = rand() % 101;
            for (int j = 0; j < size2; ++j) {
                matrix[u][j] = rand() % 101;
                for (int i = 0; i < size3; ++i) {
                    trio[u][j][i] = rand() % 101;
                }
            }
        }

        
        //вывод
        cout << "Mas 1: \n\n";
        for (int u = 0; u < size1; ++u) {cout<< mas[u]<<' ';  }
        cout << "\n\n";
        cout << "Matrix 2: \n\n";
        for (int u = 0; u < size1; ++u) {
            
            for (int j = 0; j < size2; ++j) {
                cout<< matrix[u][j]<<' ';
                
            }
            cout << endl;
        }
        cout << "\n\n";
        cout << "Trio 3: \n\n";
        for (int u = 0; u < size1; ++u) {
            
            for (int j = 0; j < size2; ++j) {
                
                for (int i = 0; i < size3; ++i) {
                    cout<< trio[u][j][i]<<' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << "\n\n";
        //итог
        cout << "Max from mas: " << max1(mas, size1)<<"\t";
        cout << "Max from matrix: " << max_2(matrix, size1,size2) << "\t";
        cout << "Max from trio: " << max3(trio, size1, size2, size3) << "\t\n\n";


        //чистка
        delete[] mas;

        for (int i = 0; i < size1; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                delete[] trio[i][j];
            }
        }
        delete[] trio;
        
    }
    system("pause");
    {
        cout << "Exercise 1" << endl<<endl;
        //avg(указатель на массив, размер)
        int size = 10;
        int* mas = new int[size];
        char* chas = new char[size];
        float* fmas = new float[size];
        for (int i = 0; i < size; ++i) {
            mas[i] = rand() % 11;
            chas[i] = rand() % 11;
            fmas[i] = 1.1 + rand() % 11;
            cout << mas[i] << ' ';
        }
        
        //для примера
        double avg_int, avg_char, avg_float;
        avg_int = avg(mas, size);
        avg_char = avg(chas, size);
        avg_float = avg(fmas, size);
        cout << "\navg(int) is: " << avg_int << endl;
        cout << "\navg(char) is: " << avg_char << endl;
        cout << "\navg(float) is: " << avg_float << endl;
        delete[] mas, chas, fmas;
    }
    
}
