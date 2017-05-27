#ifndef USER_H
#define USER_H
#include "book.h"

class user
{
public:
    friend book *load_books();

    user *next;
    user();
    user(user& u);
    user(int user_type1,string name1, string id1, string passwd,string academy1,int permission1,int credit1,double debt1);
    ~user();
    void setdebt(double d);
    void copyuser(user* target);//将target拷贝给当前类

    void init();//添加新用户

    float payment();

/*
    void change_password()//修改密码
    {
        string newpassword;
        cout<<"请输入新密码";
          cin>>newpassword;
        password=newpassword;
    }
*/

    void add_log(int type,int act_num,string u_id,book* b_book);

    void order_book(book* target);
    book* book_login();//载入借过的书
    int book_borrow(book* target);//将target放入借书链表,有头节点 targer指向书的指针，返回是否借书成功
    void save_book_return(string book);///将用户归还的书籍写入user_borrow.txt，已归还书籍参数为0
    void book_return(int n);

    int get_type();
    void save_book_borrowed(book* target);
    string getname();

    string get_id();

    string get_academy();

    string get_password();

    int get_permission();

    int get_credit();

    double get_debt();

    int getnumber();

    int get_bookhand();
    int get_expirenum();

    book* getbookborrowed();

    int getpermission();

    int getcredit();

    void output();


    void  setpassword(string s);
    user* load_user();
    bool check_permission(user* client,int authority);
    bool check_credit(user* client,double price);
private:
    int user_type;//老师0学生1
    string id;//学号/工作证
    string password;//密码初始00000000
    string name;//姓名
    string academy;//学院
    int permission;//借阅权限，小数
    int book_number;//借书总数量
    int books_hand;//在手中的书数量
    int expire_num;//过期书目数量
    int credit;//用户信用度
    book* borrowed;//所借书目
    book* expire;//过期书目
    double debt;//欠款
};


#endif // USER_H
