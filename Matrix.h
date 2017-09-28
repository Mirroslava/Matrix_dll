#ifdef Matrix_operations_EXPORTS
#define Matrix_operations_API __declspec(dllexport) 
#else
#define Matrix_operations_API __declspec(dllimport) 
#endif

class Matrix
{
private:
		double **matrix;
		int n;
		int m;
public:
	Matrix_operations_API Matrix();                                                                          //матриц€ з клав≥атури
	Matrix_operations_API Matrix(int _n,int _m);                                                             //нулева матриц€
	Matrix_operations_API Matrix(double upper, double diagonal, double lower, int _n, int _m);               //створенн€ матриц≥
	Matrix_operations_API Matrix(char *_info);                                                               //матриц€ з файлу
	Matrix_operations_API double ** get_matrix();                                                            //повертаЇ матрицю
	Matrix_operations_API int get_n();                                                                       //повертаЇ n
	Matrix_operations_API int get_m();                                                                       //повертаЇ m
	Matrix_operations_API void ADD(double** matrixA, double** matrixB, int n_A, int m_A, int n_B, int m_B);  //додаванн€
	Matrix_operations_API void SUB(double** matrixA, double** matrixB, int n_A, int m_A, int n_B, int m_B);  //в≥дн≥манн€
	Matrix_operations_API void MUL(double** matrixA, double** matrixB, int n_A, int m_A, int n_B, int m_B);  //множенн€ матриць
	Matrix_operations_API void MUL_scalar(double** matrixA, int n_A, int m_A, double scalar);                //множенн€ на скал€р
	Matrix_operations_API void DIV_scalar(double** matrixA, int n_A, int m_A, double scalar);                //д≥ленн€ на скал€р
	Matrix_operations_API void transpose(double** matrixA, int n_A, int m_A);                                //транспонована матриц€
	Matrix_operations_API void inverse(double** matrixA, int _n);                                            //обернена матриц€(методом √аусса з поступцевим вибором головного елемента)
	Matrix_operations_API void SLAR(double** matrixA, double** matrixB, int _n);                             //знаходженн€ х-≥в. –озв€зок р≥вн€нн€ 
	Matrix_operations_API void turning(double** matrixA, double** matrixB, int _n);                          //слар, метод поворот≥в
	Matrix_operations_API void NUL();                                                                        //зануленн€ матриц≥
	Matrix_operations_API void NEW(int _n, int _m);                                                          //зм≥ненн€ розм≥ру матриц≥
	Matrix_operations_API void print();                                                                      //друк матриц≥
	Matrix_operations_API void printv(double** matrixB);                                                     //друк матриц≥ з вектором
	Matrix_operations_API void write_matrix(char *_result);                                                  //запис у файл
	Matrix_operations_API ~Matrix();                                                                         //деструктор(видаленн€ пам€т≥)
};