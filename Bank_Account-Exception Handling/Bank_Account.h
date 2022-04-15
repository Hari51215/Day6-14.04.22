#ifndef BANKACCOUNT
#define BANKACCOUNT

class NameSizeOutOfBoundException
{
    public:
        NameSizeOutOfBoundException()=default;
        ~NameSizeOutOfBoundException()=default;
};

class CodeSizeOutOfBoundException
{
    public:
        CodeSizeOutOfBoundException()=default;
        ~CodeSizeOutOfBoundException()=default;
};

class IllegalAgeLimitException
{
    public:
        IllegalAgeLimitException()=default;
        ~IllegalAgeLimitException()=default;
};

class NegativeValueException
{
    public:
        NegativeValueException()=default;
        ~NegativeValueException()=default;
};



#endif