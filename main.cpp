/*
 * Issues without copy constructor
 *
 * */
#include<iostream>
struct Point_Risky {        /* Without copy constructor */
int x,y;
int* array;
void allocate(int size) {
    array = new int(size);
    }
void clear() {
    delete array;
    }
};
struct Point_Safe{
    Point_Safe(){}
    //Point_Safe& operator = (Point_Safe& temp)=delete;
    //Point_Safe(const Point_Safe& temp)= delete;
    int x,y;
    int* array;
    void allocate(int size) {
        array = new int(size);
        }
    void clear() {
        delete array;
        }
};
int main()
{
    //-*** Risky code************
    Point_Risky p;
    p.x=1;
    p.y=2;
    p.allocate(10);
    p.array[0]=10;
    p.array[1]=20;
    std::cout<<p.array<<'\n';
    std::cout<<p.array[0]<<'\n';
    std::cout<<p.array[0]<<'\n';
    p.clear();

    Point_Risky p1 = p; //Dangerous

    std::cout<<p1.array<<'\n';
    std::cout<<p1.array[0]<<'\n'; //Accessing Deleted Arrays
    std::cout<<p1.array[0]<<'\n'; //Accessing Deleted Arrays
    //-*********Safe code*******
    Point_Safe ps;
    ps.x=1;
    ps.y=2;
    ps.allocate(10);
    ps.array[0]=10;
    ps.array[1]=20;
    std::cout<<ps.array<<'\n';
    std::cout<<ps.array[0]<<'\n';
    std::cout<<ps.array[0]<<'\n';
    ps.clear();

    Point_Safe ps1 = ps; //Impossible - If ( Point_Safe(const Point_Safe& temp)= delete; )
    Point_Safe ps2;
     ps2.x=1;
     ps2.y=2;

     ps2 = ps1;//Impossible - If ( Point_Safe& operator = (Point_Safe& temp)=delete; )


    return 0;
}

//Output
/*0x56499c354eb0
10
10
0x56499c354eb0
1687798612
1687798612
*/
