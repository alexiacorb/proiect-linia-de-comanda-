#ifndef DATA_H
#define DATA_H


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
};

#endif // DATA_H
