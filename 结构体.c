// 写法一：先定义，再取别名
struct Student
{
    char name[50];
    int age;
};
typedef struct Student Student; // 为 struct Student 取一个别名 Student

// 写法二：定义的同时取别名 (更常用)
typedef struct
{
    char name[50];
    int age;
} Person; // Person 现在就是这个匿名结构体类型的别名

int main()
{
    // 原来的写法
    struct Student s1;

    // 使用别名后的写法
    Student s2;
    Person p1;
    // 两者都更简洁了
    s2.age = 20;
    p1.age = 21;
}