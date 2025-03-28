#include <bits\stdc++.h>
using namespace std;

class Polynomial{
private:
    int *degrees;
    int size;

public:
    Polynomial()
    {
        size = 0;
        degrees = new int[size];
    }
    Polynomial(int sz)
    {
        size = sz + 2;
        degrees = new int[size];
    }
    ~Polynomial()
    {
        delete [] degrees;
    }
    void inputDegrees()
    {
        cout << "Enter polynomial:\n";
        for (int i = 0; i < size; i++)
            cin >> degrees[i];
    }
    void inputDegrees(ifstream & file)
    {
        for (int i = 0; i < size; i++)
            file >> degrees[i];
    }

    Polynomial operator+(const Polynomial& p)
    {
        Polynomial res(max(p.size,this->size)-2);
        for (int i = 0; i < min(p.size,this->size); ++i)
            res.degrees[i] = this->degrees[i] + p.degrees[i];
        if(this->size > p.size)
        {
            for (int i = p.size; i < this->size; ++i)
                res.degrees[i] = this->degrees[i];
        }
        else
        {
            for (int i = this->size; i < p.size; ++i)
                res.degrees[i] = p.degrees[i];
        }
        return res;
    }

    Polynomial operator-(const Polynomial& p)
    {
        Polynomial res(max(p.size,this->size)-2);
        for (int i = 0; i < min(p.size,this->size); ++i)
            res.degrees[i] = this->degrees[i] - p.degrees[i];
        if(this->size > p.size)
        {
            for (int i = p.size; i < this->size; ++i)
                res.degrees[i] = this->degrees[i];
        }
        else
        {
            for (int i = this->size; i < p.size; ++i)
                res.degrees[i] = -p.degrees[i];
        }
        return res;
    }

    Polynomial& operator=(const Polynomial& p)
    {
        delete [] this->degrees;
        this->degrees = new int[p.size];
        this->size = p.size;
        for (int i = 0; i < size; ++i)
            this->degrees[i] = p.degrees[i];
        return *this;
    }

    friend ostream& operator<<(ostream &out , const Polynomial& p)
    {
        bool start = 0;
        for (int i = p.size-1; ~i ; --i)
        {
            if(!i)
                out << " = " << p.degrees[i];
            else if(p.degrees[i])
            {
                if(i != p.size-1 && p.degrees[i] > 0 && start)
                    out << " + ";
                else if(p.degrees[i] < 0)
                    out << " - ";
                if(abs(p.degrees[i]) != 1 || i < 2)
                    out << abs(p.degrees[i]);
                if(i > 1)
                {
                    out << "x";
                    if(i > 2)
                        out << "^" << i-1;
                }
                start = 1;
            }
        }
        return out;
    }
};

void user()
{
    int ord1 , ord2;
    cout << "Order of first polynomial:\n";
    cin >> ord1;
    Polynomial p1(ord1);
    p1.inputDegrees();
    cout << "Order of second polynomial:\n";
    cin >> ord2;
    Polynomial p2(ord2) , p3 , p4;
    p2.inputDegrees();
    p3 = p1 + p2;
    p4 = p2 - p1;
    cout << "First polynomial: " << p1 << '\n';
    cout << "Second polynomial: " << p2 << '\n';
    cout << "Sum of polynomials: " << p3 << '\n';
    cout << "Difference of polynomials: " << p4 << '\n';
}

void file()
{
    cout << "Enter testcases file name (without extension):\n";
    string filename;
    cin.ignore();
    getline(cin,filename);
    ifstream testcases(filename+".txt");
    int tc;
    testcases >> tc;
    for (int i = 0; i < tc; ++i)
    {
        int ord1 , ord2;
        testcases >> ord1;
        Polynomial p1(ord1);
        p1.inputDegrees(testcases);
        testcases >> ord2;
        Polynomial p2(ord2) , p3 , p4;
        p2.inputDegrees(testcases);
        p3 = p1 + p2;
        p4 = p2 - p1;
        cout << "Test Case #" << i+1 << '\n';
        cout << "First polynomial: " << p1 << '\n';
        cout << "Second polynomial: " << p2 << '\n';
        cout << "Sum of polynomials: " << p3 << '\n';
        cout << "Difference of polynomials: " << p4 << '\n';
        cout << '\n';
    }
}

signed main()
{
    char choice;
    cout << "Load testcases from file (y/n)?\n";
    cin >> choice;
    if(choice == 'y')
        file();
    else
        user();
}