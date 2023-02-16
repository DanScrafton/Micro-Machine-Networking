#ifndef MY_CLASS_H
#define MY_CLASS_H


class My_Class
{
    public:
        My_Class(int data_);

        virtual ~My_Class();

        void Do_Something(int param_1,int param_2,int param_3);

        int get_Value();

    protected:

    private:
    int data;
};

#endif // MY_CLASS_H
