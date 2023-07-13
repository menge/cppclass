#include <iostream>
#include <cstring>

void func1 (char *s)
{
    std::cout << "func1: " << sizeof(s) << std::endl;
    std::cout << "func1 dereferenced: " << sizeof(*s) << std::endl;
}

int main(int argc, char** argv)
{
    char c_str_1[100] = "Hello";
    char c_str_2[50] = "Hello";
    char c_str_3[] = "Hello";
    //char c_str_4[5] = "Hello"; // results in compilation error
    char *ptr_1 = c_str_1;

    std::cout << sizeof(c_str_1) << std::endl;
    std::cout << sizeof(c_str_2) << std::endl;
    std::cout << sizeof(c_str_3) << std::endl;
    std::cout << sizeof(ptr_1) << std::endl;

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(bool) << std::endl;
    std::cout << sizeof(size_t) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(char) << std::endl;

    std::cout << sizeof(char *) << std::endl;
    std::cout << sizeof(int *) << std::endl;
    std::cout << sizeof(double *) << std::endl;

    func1(ptr_1);
    func1(c_str_1);

    // This is really weird
    // std::cout << sizeof(c_str_1 + 1) << std::endl;

    // TODO: why are all pointers 8 bytes in size?
    int a = 100;
    int *ptr_a = &a;

    printf("a's value: %i\n", a);
    printf("a's address: %p\n", &a);
    printf("ptr_a value: %p\n", ptr_a);
    printf("dereference ptr_a: %i\n", *ptr_a);

    //a += 10;
    //* (&a) += 10;
    *ptr_a += 10;

    printf("a's value: %i\n", a);
    printf("a's address: %p\n", &a);
    printf("ptr_a value: %p\n", ptr_a);
    printf("dereference ptr_a: %i\n", *ptr_a);

    {
        int a = 100;
        printf("inner a's address: %p\n", &a);
    }
    printf("a's address: %p\n", &a);

    // 2020-03-19
    int int_array[10] = {0};
    int *iptr = int_array;
    std::cout << "int array size: " << sizeof(int_array) << std::endl;
    std::cout << "int array element dereferenced: " << sizeof(*int_array) << std::endl;
    std::cout << "int array[0]: " << sizeof(int_array[0]) << std::endl;
    std::cout << "int array element dereferenced: " << sizeof(*(int_array+1)) << std::endl;
    std::cout << "int array[1]: " << sizeof(int_array[1]) << std::endl;
    std::cout << "iptr size: " << sizeof(iptr) << std::endl;
    std::cout << "iptr derefereced size: " << sizeof(*iptr) << std::endl;
    printf("int_array's address: %p\n", int_array);
    printf("iptr value: %p\n", iptr);
    printf("int_array[0] address: %p\n", &int_array[0]);
    printf("int_array[1] address: %p\n", &int_array[1]);
    printf("int_array[5] address: %p\n", &int_array[5]);
    printf("int_array+5 address: %p\n", int_array+5);
    printf("iptr+5 address: %p\n", iptr+5);
    printf("&iptr[5] address: %p\n", &iptr[5]);
    printf("&iptr[500000] address: %p\n", &iptr[500000]);
    //printf("iptr[500000] value: %i\n", iptr[500000]);
    printf("&iptr[10] address: %p\n", &iptr[10]);
    printf("iptr[10] value: %i\n", iptr[10]);
    printf("int_array[10] value: %i\n", int_array[10]);
    printf("iptr[9] value: %i\n", iptr[9]);
    printf("int_array[9] value: %i\n", int_array[9]);

    int foo[500000] = {0};
    printf("foo[500000-1] value: %i\n", foo[500000-1]);

    // 2020-04-02
    double darray[100];
    std::cout << sizeof(darray) << std::endl;
    float farray[100];
    std::cout << sizeof(farray) << std::endl;
    int zero = 0;
    char str[100] = "hello";
    std::cout << sizeof(str) << std::endl;
    str[99] = 'a';
    std::cout << "zero: " << zero << std::endl;
    str[100] = 'a';

    struct Person {
        char name[100];
        int age;
        char favorite_color[100];
    };

    Person anthony;
    strcpy(anthony.name, "Anthony");
    anthony.age = 11;
    strcpy(anthony.favorite_color, "blue");

    //printf("Anthony name %p\n", &anthony.name);
    //printf("Anthony age %p\n", &anthony.age);
    std::cout << "Anthony.name: " << anthony.name << std::endl;
    std::cout << "Anthony.age: " << anthony.age << std::endl;
    std::cout << "Anthony.favorite_color: " << anthony.favorite_color << std::endl;
    anthony.name[8] = 'z';
    anthony.name[9] = 'z';
    anthony.name[10] = 'z';
    anthony.name[11] = '\0';
    anthony.name[7] = ' ';
    anthony.name[12] = 'z';
    anthony.name[88] = 'z';
    anthony.name[99] = 'z';
    anthony.name[100] = 'z';
    anthony.name[101] = 'z';
    std::cout << "Anthony.name: " << anthony.name << std::endl;
    std::cout << "Anthony.age: " << anthony.age << std::endl;
    std::cout << "Anthony.favorite_color: " << anthony.favorite_color << std::endl;
}
