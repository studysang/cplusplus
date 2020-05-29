#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Matrix
{
public:
    Matrix(string name, int row, int col){myname = name, myrow = row; mycol = col;};
    ~Matrix(){};
    vector<int> elements{0,0,0,0};
    int myrow;
    int mycol;
    string myname;
    int getNumRows(){return myrow;};
    int getNumCols(){return mycol;};
    void setElement(Matrix *m, int x, int y, int val, int shift);
    void addMatrix(Matrix *m1, Matrix *m2, Matrix *mout);
    void mulMatrix(Matrix *m1, Matrix *m2, Matrix *mout);
};
void Matrix::mulMatrix(Matrix *m1, Matrix *m2, Matrix *mout)
{
    int tmp = 0;
    int shift = mout->mycol;
    for(int i = 0; i<mout->myrow;++i)
    {    
        for(int j = 0; j<mout->mycol;++j)    
        {             
            tmp = m1->elements.at(i*shift+j) * m2->elements.at(j*shift+i);
            mout->elements.at(i*shift+j) = tmp;
        }        
    }
}
void Matrix::addMatrix(Matrix *m1, Matrix *m2, Matrix *mout)
{
    int tmp = 0;
    int shift = mout->mycol;
    for(int i = 0; i<mout->myrow;++i)
    {    
        for(int j = 0; j<mout->mycol;++j)    
        {             
            tmp = m1->elements.at(i*shift+j) + m2->elements.at(i*shift+j);
            mout->elements.at(i*shift+j) = tmp;
        }        
    }
}
void Matrix::setElement(Matrix *m, int x, int y, int val, int shift)
{
    cout<<"set matrix element"<<endl;             
    m->elements.at(x*shift+y) = val;      
}
void printMatrix(Matrix *m, int row, int col, int shift)
{
    cout<<"print out matrix"<<endl;
    for(int i = 0; i<row;++i)
    {    
        for(int j = 0; j<col;++j)            
            cout<<m->elements.at(i*shift+j)<<" ";
        cout<<endl;        
    }
    cout<<endl;    
    cout<<"Matrix: "<<m->myname<<", "<<"row: "<<row<<", "<<"col: "<<col<<endl;
}
int main()
{
    cout<<"Initialize matrix"<<endl;
    Matrix *m1 = new Matrix("m1",2,2);
    Matrix *m2 = new Matrix("m2",2,2);
    Matrix *mout = new Matrix("mout",2,2);
    int row, col;

    cout<<"get rows and cols"<<endl;    
    row = m1->getNumRows();
    col = m1->getNumCols(); 
    cout<<"set elemets at row and col"<<endl;
    m1->setElement(m1,0,0,10,2);
    m1->setElement(m1,1,1,10,2);   
    printMatrix(m1,row,col, col);
    
    row = m2->getNumRows();
    col = m2->getNumCols();
    cout<<"set elemets at row and col"<<endl;
    m2->setElement(m2,0,0,10,2);
    m2->setElement(m2,1,1,10,2);
    printMatrix(m2,row,col, col);
    
    cout<<"add matrix"<<endl;
    mout->addMatrix(m1, m2, mout);    
    printMatrix(mout,row,col, col);
    
    cout<<"multiply matrix"<<endl;
    mout->mulMatrix(m1, m2, mout);    
    printMatrix(mout,row,col, col);
    cout<<endl;
    return 0;
}