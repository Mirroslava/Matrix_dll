#include <iostream>
#include <fstream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

Matrix::Matrix()
{
	cout<<"n="; cin>>n;
	cout<<"m="; cin>>m;
	matrix = new double *[n];
	for(int i=0; i<n; i++)
	{
		matrix[i] = new double [m];
	}

	cout<<"Input matrix:"<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; cin>>matrix[i][j], j++);
	}
}

Matrix::Matrix(int _n, int _m)
{
	n=_n;
	m=_m;
	matrix = new double *[n];
	for(int i=0; i<n; i++)
	{
		matrix[i] = new double [m];
	}
	NUL();
}

Matrix::Matrix(double upper, double diagonal, double lower, int _n, int _m)
{
	n=_n;
	m=_m;
	matrix = new double *[n];
	for(int i=0; i<n; i++)
	{
		matrix[i] = new double [m];
	}
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < m; j++)
		{
			if(i<j) matrix[i][j]=upper;
			if(i>j) matrix[i][j]=lower;
			if(i==j) matrix[i][j]=diagonal;
		}
	}
}

Matrix::Matrix(char *_info)
{
	ifstream fin(_info);
	fin>>n; fin>>m;

	matrix = new double *[n];
	for(int i=0; i<n; i++)
	{
		matrix[i] = new double [m];
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; fin>>matrix[i][j], j++);
	}
	fin.close();
}

double ** Matrix::get_matrix()
{
	return matrix;
}

int Matrix::get_n()
{
	return n;
}

int Matrix::get_m()
{
	return m;
}

void Matrix::inverse(double** matrixA, int _n)
{
	NEW(_n,_n);
	NUL();
	double C;
    int Imax;
	double **matrixB = new double *[n];
	for(int i=0; i<n; i++)
	{
		matrixB[i] = new double [n];
	}
	for(int i=0; i<n; i++)    //çàíóëåííÿ ìàòðèö³
    {
	    for(int j=0; j<n; matrixB[i][j]=0, j++);
    }
    for(int i=0; i<n; matrixB[i][i]=1, i++);   // îäèíè÷íà ìàòðèöÿ

	for(int k=0; k<n-1; k++)   //ë³÷èëüíèê ðÿäê³â
    {
	    Imax=k;    //ìàêñèìàëüíèé åëåìåíò â ñòîâïö³
        for(int i=k+1; i<n; i++)           //ïîøóê 
        {
	      	if(abs(matrixA[Imax][k])<abs(matrixA[i][k]))
		    {
			    Imax=i;
            }
        }
        if(Imax!=k)
 	    {
		    for(int i=0; i<n;  i++)
		    {
			    swap(matrixA[Imax][i], matrixA[k][i]);
			    swap(matrixB[Imax][i], matrixB[k][i]);
		    }
	    }
        for(int i=k+1; i<n; i++)
        {
		    C=matrixA[i][k]/matrixA[k][k];
		    for(int j=0; j<n; j++)
		    {
			    matrixA[i][j]=matrixA[i][j]-(C*matrixA[k][j]);
			    matrixB[i][j]=matrixB[i][j]-(C*matrixB[k][j]);
            }
		    matrixA[i][k]=0;
	    }
    }
    for(int i=0; i<n; i++)
    {
	    for(int j=n-1; j>=0; j--)
	    {
		    matrix[j][i]=matrixB[j][i];
		    for(int k=n-1; k>j; k--)
		    {
			    matrix[j][i]-=matrixA[j][k]*matrix[k][i];
            }
		    matrix[j][i]/=matrixA[j][j];
	    }
    }
	for(int i=0; i<n; i++)
    {
	    delete matrixB[i];
    }
    delete [] matrixB;
}
void Matrix::MUL(double** matrixA, double** matrixB, int n_A, int m_A, int n_B, int m_B)
{
    if(m_A==n_B)
	{
		NEW(n_A, m_B);
		NUL();
		for ( int i = 0; i < n_A; i++)
		{
			for ( int j = 0; j < m_B; j++)
			{
				for(int k=0; k<m_A; k++)
				{
					matrix[i][j]=matrix[i][j]+matrixA[i][k]*matrixB[k][j];
				}
            }
        }
    }
	else cout<<"ERROR!!!!!!!!!!!!!"<<endl;
}

void Matrix::SLAR(double** matrixA, double** matrixB, int _n)
{
	NEW(_n,1);
	NUL();
	double C;
    int Imax;
	for(int k=0; k<n-1; k++)   //ë³÷èëüíèê ðÿäê³â
    {
	    Imax=k;    //ìàêñèìàëüíèé åëåìåíò â ñòîâïö³
        for(int i=k+1; i<n; i++)           //ïîøóê 
        {
	      	if(abs(matrixA[Imax][k])<abs(matrixA[i][k]))
		    {
			    Imax=i;
            }
        }
        if(Imax!=k)
 	    {
		    for(int i=0; i<n;  i++)
		    {
			    swap(matrixA[Imax][i], matrixA[k][i]);
		    }
			swap(matrixB[Imax][0], matrixB[k][0]);
	    }
        for(int i=k+1; i<n; i++)
        {
		    C=matrixA[i][k]/matrixA[k][k];
		    for(int j=0; j<n; j++)
		    {
			    matrixA[i][j]=matrixA[i][j]-(C*matrixA[k][j]);
            }
			matrixB[i][0]=matrixB[i][0]-(C*matrixB[k][0]);
		    matrixA[i][k]=0;
	    }
    }
	for(int j=n-1; j>=0; j--)
	{
		 matrix[j][0]=matrixB[j][0];
		 for(int k=n-1; k>j; k--)
		 {
			 matrix[j][0]-=matrixA[j][k]*matrix[k][0];
         }
		 matrix[j][0]/=matrixA[j][j];
    }
}

void Matrix::NUL()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; matrix[i][j]=0, j++);
	}
}

void Matrix::NEW(int _n, int _m)
{
	for(int i=0; i<n; i++)
	{
		delete [] matrix[i];
	}
	delete matrix;

	n=_n; m=_m;

	matrix = new double *[n];
	for(int i=0; i<n; i++)
	{
		matrix[i] = new double [m];
	}
}

void Matrix::print()
{
	for(int i=0; i<n; cout<<endl, i++)
	{
		for(int j=0; j<m; cout<<setw(10)<<left<<matrix[i][j]<<" ", j++);
	}
	cout<<endl;
}

void Matrix::printv(double** matrixB)
{
	for(int i=0; i<n; cout<<endl, i++)
	{
		for(int j=0; j<m; cout<<setw(10)<<left<<matrix[i][j]<<" ", j++);
		cout<<" | "<<matrixB[i][0];
	}
	cout<<endl;
}

void Matrix::write_matrix(char *_result)
{
	ofstream fout(_result);
	for(int i=0; i<n; fout<<endl, i++)
	{
		for(int j=0; j<m; fout<<setw(10)<<left<<matrix[i][j]<<" ", j++);
	}
	fout<<endl;
}

Matrix::~Matrix()
{
	for(int i=0; i<n; i++)
	{
		delete [] matrix[i];
	}
	delete matrix;
}
