#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void initMat(vector<vector<int> > *mat, int n);
void printMat(vector<vector<int> > *mat);
void printVect(vector<int> *vect);
void rotateMat(vector<vector<int> > *mat, int n, int seed);

int main()
{
    int n;
    vector<vector<int> > mat;

    do
    {
        cout << "Enter square matrix dimension (-1 to terminate):";
        cin >> n;
        initMat(&mat, n);
        printMat(&mat);
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < n / 2; i++)
                rotateMat(&mat, n - 2 * i, i);
            printMat(&mat);
        }
    }while (n > -1);

    return 0;
}

void initMat(vector<vector<int> > *mat, int n)
{
	mat->clear();
	for (int i = 0; i < n; i++)
	{
            vector<int> vect;
            for (int j = 0; j < n; j++)
                    vect.push_back(i*n + j);
            mat->push_back(vect);
	}
}

void printMat(vector<vector<int> > *mat)
{
    for (int i=0; i<(*mat).size(); i++)
    {
        printVect(&(*mat)[i]);
        cout << endl;
    }
    cout << endl;
}

void printVect(vector<int> *vect)
{
    for (int i=0; i<(*vect).size(); i++)
        cout << setw(2) << (*vect)[i] << ' ';
}

void rotateMat(vector<vector<int> > *mat, int n, int seed)
{
    int steps = n - 1;
    int temp;
    for (int i = 0; i < steps; i++)
    {
        temp = (*mat)[seed][seed + i];
        (*mat)[seed][seed + i] = (*mat)[steps + seed - i][seed];
        (*mat)[steps + seed - i][seed] = (*mat)[steps + seed][steps + seed - i];
        (*mat)[steps + seed][steps + seed - i] = (*mat)[seed + i][steps + seed];
        (*mat)[seed + i][steps + seed] = temp;
    }
}