#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

class Flower{
private:
    string name;
    string color;
    string smell;
    string region;

public:
    Flower ()
    {
        name = "";
        color = "";
        smell = "";
        region = "";
    }
    Flower (string n, string c, string s, string r)
    {
        name = n;
        color = c;
        smell = s;
        region = r;
    }
    Flower (const Flower& f)
    {
        name = f.GetName();
        color = f.GetColor();
        smell = f.GetSmell();
        region = f.GetRegion();
    }
    ~Flower () {};
    string GetName() const
    {
        return name;
    }
    string GetColor() const
    {
        return color;
    }
    string GetSmell() const
    {
        return smell;
    }
    string GetRegion() const
    {
        return region;
    }
    Flower& operator= (Flower f)
    {
        name = f.GetName();
        color = f.GetColor();
        smell = f.GetSmell();
        region = f.GetRegion();
    }
    friend ostream& operator<< (ostream &out, const Flower &A);
};
ostream& operator<< (ostream &out, const Flower &A){
    out << A.GetName() << " " << A.GetColor() << " " << A.GetSmell() << " " << A.GetRegion() << " " << endl;
    return out;
}
bool operator> (Flower f1, Flower f2)
    {
        if (f1.GetName() > f2.GetName())
            return true;
        else if(f1.GetName() == f2.GetName() && f1.GetColor() > f2.GetColor())
            return true;
        else if(f1.GetName() == f2.GetName() && f1.GetColor() == f2.GetColor() && f1.GetSmell() > f2.GetSmell())
            return true;
        return false;
    }
bool operator>= (Flower f1, Flower f2)
    {
        if (f1.GetName() >= f2.GetName())
            return true;
        else if(f1.GetName() == f2.GetName() && f1.GetColor() >= f2.GetColor())
            return true;
        else if(f1.GetName() == f2.GetName() && f1.GetColor() == f2.GetColor() && f1.GetSmell() >= f2.GetSmell())
            return true;
        return false;
    }
bool operator< (Flower f1, Flower f2)
    {
        if (f2 > f1)
            return true;
        return false;
    }
 bool operator<= (Flower f1, Flower f2)
    {
        if (f2 >= f1)
            return true;
        return false;
    }
long findSmallestPosition(vector<Flower> &A, long startPosition, long vectorLength)
{
	long smallestPosition = startPosition;

	for(long i = startPosition; i < vectorLength; i++)
	{
		if(A[i] < A[smallestPosition])
			smallestPosition = i;
	}
	return smallestPosition;
}

void selectionSort(vector<Flower> &A, long vectorLength)
{
	for(long i = 0; i < vectorLength; i++)
	{
		long smallestPosition = findSmallestPosition(A, i, vectorLength);
		Flower x = A[smallestPosition];
		A[smallestPosition] = A[i];
		A[i] = x;
	}
	return;
}
int Partition(vector<Flower> &A, int start, int pivot)
{
	int i = start;
	while(i < pivot)
	{
		if(A[i] > A[pivot] && i == pivot-1)
		{
			Flower x = A[i];
			A[i] = A[pivot];
			A[pivot] = x;
			pivot--;
		}

		else if(A[i] > A[pivot])
		{
			Flower x = A[pivot - 1];
			A[pivot - 1] = A[pivot];
			A[pivot] = x;

			x = A[i];
			A[i] = A[pivot];
			A[pivot] = x;
			pivot--;
		}

		else i++;
	}
	return pivot;
}

void quickSort(vector<Flower> &A, int start, int End)
{
	if(start < End)
	{
		int pivot = Partition(A, start, End);

		quickSort(A, start, pivot - 1);
		quickSort(A, pivot + 1, End);
	}
}

void heapify(vector<Flower> &A, long listLength, long root)
{
	long largest = root;
	long l = 2*root + 1;
	long r = 2*root + 2;

	if (l < listLength && A[l] > A[largest])
		largest = l;

	if (r < listLength && A[r] > A[largest])
		largest = r;

	if (largest != root)
	{
		Flower x = A[root];
		A[root] = A [largest];
		A[largest] = x;
		heapify(A, listLength, largest);
	}
}

void heapSort(vector <Flower> &A, long listLength)
{
	for(long i = listLength / 2 - 1; i >= 0; i--)
		heapify(A, listLength, i);

	for(long i = listLength - 1; i >= 0; i--)
	{
		Flower x = A[i];
		A[i] = A[0];
		A[0] = x;
		heapify(A, i, 0);
	}
}
int main()
{
    long vibor;
    cout << "print\n 1 for selectionSort\n 2 for quickSort\n 3 for heapSort\n";
    cin >> vibor;
    vector<Flower> f1,f2,f3,f4,f5,f6,f7;
    ifstream fin100("f100.txt"),
             fin500("f500.txt"),
             fin1k("f1000.txt"),
             fin10k("f10000.txt"),
             fin20k("f20000.txt"),
             fin50k("f50000.txt"),
            fin100k("f100000.txt");
    for (long i = 0; i < 100; i++)
    {
        string a,b,c,d;
        fin100 >> a >> b >> c >> d;
        Flower x(a,b,c,d);
        f1.push_back(x);
    }
    for (long i = 0; i < 500; i++)
    {
        string a,b,c,d;
        fin500 >> a >> b >> c >> d;
        Flower x(a,b,c,d);
        f2.push_back(x);
    }
    for (long i = 0; i < 1000; i++)
    {
        string a,b,c,d;
        fin1k >> a >> b >> c >> d;
        Flower x(a,b,c,d);
        f3.push_back(x);
    }
    for (long i = 0; i < 10000; i++)
    {
        string a,b,c,d;
        fin10k >> a >> b >> c >> d;
        Flower x(a,b,c,d);
        f4.push_back(x);
    }
    for (long i = 0; i < 20000; i++)
    {
        string a,b,c,d;
        fin20k >> a >> b >> c >> d;
        Flower x(a,b,c,d);
        f5.push_back(x);
    }
    for (long i = 0; i < 50000; i++)
    {
        string a,b,c,d;
        fin50k >> a >> b >> c >> d;
        Flower x(a,b,c,d);
        f6.push_back(x);
    }
    for (long i = 0; i < 100000; i++)
    {
        string a,b,c,d;
        fin100k >> a >> b >> c >> d;
        Flower x(a,b,c,d);
        f7.push_back(x);
    }
    if (vibor == 1)
    {
        cout << "selection size 100\n";
        clock_t s100 = clock();
        selectionSort(f1, 100);
        cout << (double)(clock() - s100) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 500\n";
        clock_t s500 = clock();
        selectionSort(f2, 500);
        cout << (double)(clock() - s500) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 1000\n";
        clock_t s1k = clock();
        selectionSort(f3, 1000);
        cout << (double)(clock() - s1k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 10000\n";
        clock_t s10k = clock();
        selectionSort(f4, 10000);
        cout << (double)(clock() - s10k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 20000\n";
        clock_t s20k = clock();
        selectionSort(f5, 20000);
        cout << (double)(clock() - s20k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 50000\n";
        clock_t s50k = clock();
        selectionSort(f6, 50000);
        cout << (double)(clock() - s50k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 100000\n";
        clock_t s100k = clock();
        selectionSort(f7, 100000);
        cout << (double)(clock() - s100k) * 1000 / CLOCKS_PER_SEC << " ms\n";
    }
    else if (vibor == 2)
    {
        cout << "selection size 100\n";
        clock_t s100 = clock();
        quickSort(f1, 0, f1.size() - 1);
        cout << (double)(clock() - s100) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 500\n";
        clock_t s500 = clock();
        quickSort(f2, 0, f2.size() - 1);
        cout << (double)(clock() - s500) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 1000\n";
        clock_t s1k = clock();
        quickSort(f3, 0, f3.size() - 1);
        cout << (double)(clock() - s1k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 10000\n";
        clock_t s10k = clock();
        quickSort(f4, 0, f4.size()-1);
        cout << (double)(clock() - s10k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 20000\n";
        clock_t s20k = clock();
        quickSort(f5, 0, f5.size() - 1);
        cout << (double)(clock() - s20k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 50000\n";
        clock_t s50k = clock();
        quickSort(f6, 0, f6.size() - 1);
        cout << (double)(clock() - s50k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 100000\n";
        clock_t s100k = clock();
        quickSort(f7, 0, f7.size() - 1);
        cout << (double)(clock() - s100k) * 1000 / CLOCKS_PER_SEC << " ms\n";
    }
    else if (vibor == 3)
    {
        cout << "selection size 100\n";
        clock_t s100 = clock();
        heapSort(f1, f1.size());
        cout << (double)(clock() - s100) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 500\n";
        clock_t s500 = clock();
        heapSort(f2, 500);
        cout << (double)(clock() - s500) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 1000\n";
        clock_t s1k = clock();
        heapSort(f3, 1000);
        cout << (double)(clock() - s1k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 10000\n";
        clock_t s10k = clock();
        heapSort(f4, 10000);
        cout << (double)(clock() - s10k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 20000\n";
        clock_t s20k = clock();
        heapSort(f5, 20000);
        cout << (double)(clock() - s20k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 50000\n";
        clock_t s50k = clock();
        heapSort(f6, 50000);
        cout << (double)(clock() - s50k) * 1000 / CLOCKS_PER_SEC << " ms\n";

        cout << "selection size 100000\n";
        clock_t s100k = clock();
        heapSort(f7, 100000);
        cout << (double)(clock() - s100k) * 1000 / CLOCKS_PER_SEC << " ms\n";
    }
    fin100.close();
    fin500.close();
    fin1k.close();
    fin10k.close();
    fin20k.close();
    fin50k.close();
    fin100k.close();
    ofstream o100("out100.txt"),
             o500("out500.txt"),
             o1k("out1000.txt"),
             o10k("out10000.txt"),
             o20k("out20000.txt"),
             o50k("out50000.txt"),
             o100k("out100000.txt");
    for (long i = 0; i < 100; i++)
    {
        o100 << f1[i];
    }
    for (long i = 0; i < 500; i++)
    {
        o500 << f2[i];
    }
    for (long i = 0; i < 1000; i++)
    {
        o1k << f3[i];
    }
    for (long i = 0; i < 10000; i++)
    {
        o10k << f4[i];
    }
    for (long i = 0; i < 20000; i++)
    {
        o20k << f5[i];
    }
    for (long i = 0; i < 50000; i++)
    {
        o50k << f6[i];
    }
    for (long i = 0; i < 100000; i++)
    {
        o100k << f7[i];
    }
    o100.close();
    o500.close();
    o1k.close();
    o10k.close();
    o20k.close();
    o50k.close();
    o100k.close();

}
