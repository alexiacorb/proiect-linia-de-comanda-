#ifndef DATA_H
#define DATA_H

using namespace std;
class Data
{
    private:
        int zi,luna,an;
    public:
        Data();
        Data(int zi,int luna,int an);
        virtual ~Data();
        int getZi() const;
        int getLuna() const;
        int getAn() const;
        friend ostream& operator<<(ostream& os, const Data& data);

};

#endif // DATA_H
