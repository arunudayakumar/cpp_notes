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

};
int main()
{
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
